#include "engine.h"
#include "proto/generated/scyna.pb.h"
#include <boost/make_shared.hpp>
#include <curl/curl.h>
#include "path.h"
#include "session.h"
#include "generator.h"
#include "logger.h"

scyna::Engine *scyna::Engine::instance_;

size_t writefunc(void *ptr, size_t size, size_t nmemb, std::string *s)
{
    s->append(static_cast<char *>(ptr), size * nmemb);
    return size * nmemb;
}

scyna::Engine::Engine(std::string module, uint64_t sid, const scyna_proto::Configuration &config)
{
    this->module_ = module;
    this->session_ = new Session(sid);
    this->id_ = new Generator();
    this->logger_ = new Logger(sid, true);

    std::cout << "NATS URL:" << config.natsurl() << std::endl;

    natsOptions *opt = NULL;

    // natsOptions_Create(&otp);
    // natsOptions_SetServers(&opt,)

    natsConnection_ConnectTo(&connection_, config.natsurl().c_str());
    std::cout << "Connected to NATS" << std::endl;
}

scyna::Engine::~Engine()
{
    this->release();
}

void scyna::Engine::release()
{
    if (connection_ != NULL)
    {
        natsConnection_Destroy(connection_);
        connection_ = NULL;
    }
    if (session_ == NULL)
    {
        delete session_;
        session_ = NULL;
    }
    if (id_ == NULL)
    {
        delete id_;
        id_ = NULL;
    }
    if (logger_ == NULL)
    {
        delete logger_;
        logger_ = NULL;
    }
}

scyna::Engine *scyna::Engine::instance()
{
    return instance_;
}

void scyna::Engine::Init(std::string managerURL, std::string module, std::string secret)
{
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl)
    {
        auto url = managerURL + Path::SESSION_CREATE_URL;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        scyna_proto::CreateSessionRequest request;
        request.set_module(module);
        request.set_secret(secret);
        auto data = request.SerializeAsString();

        std::string result;

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data.length());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else
        {
            scyna_proto::CreateSessionResponse response;
            if (response.ParseFromString(result))
            {
                instance_ = new Engine(module, (uint64_t)response.sessionid(), response.config());
                std::cerr << "Engine created, session:" << response.sessionid() << std::endl;
            }
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    if (instance_ == nullptr)
    {
        std::cerr << "Can not create scyna::Engine" << std::endl;
        exit(0);
    }
}

void scyna_about_to_exit_handler(int s)
{
    printf("Caught signal %d\n", s);
    exit(1);
}

void scyna::Engine::start()
{
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = scyna_about_to_exit_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);
    pause();
}

boost::shared_ptr<scyna_proto::Response> scyna::Engine::natsRequest(std::string subject, const scyna_proto::Request &request)
{
    natsMsg *reply = NULL;
    auto data = request.SerializeAsString();
    auto status = natsConnection_Request(&reply, connection_, subject.c_str(), (const void *)data.c_str(), data.length(), 5000);

    if (status != NATS_OK)
    {
        return nullptr;
    }

    auto ret = boost::make_shared<scyna_proto::Response>();

    auto ok = ret->ParseFromArray(natsMsg_GetData(reply), natsMsg_GetDataLength(reply));
    natsMsg_Destroy(reply);

    if (ok)
    {
        return ret;
    }

    return nullptr;
}