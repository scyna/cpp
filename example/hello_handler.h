#include "../scyna/endpoint.h"
#include "hello.pb.h"

class HelloHandler : public scyna::Endpoint::Handler<PROTO::HelloRequest>
{
    const scyna::Error *execute() override
    {
        ctxINFO("Receive HelloRequest");
        PROTO::HelloResponse response;
        response.set_content("Hello " + request.name());
        std::cout << "Request:" << request.name() << std::endl;
        return OK(response);
    }
};
