#include <iostream>
#include "../scyna/engine.h"
#include "../scyna/logger.h"
#include "hello_handler.h"

int main(int, char **)
{
    LOG_INFO("Receive HelloRequest")
    scyna::Engine::Init("http://127.0.0.1:8081", "ex_hello", "123456");
    scyna::Endpoint::Register<HelloHandler>("/example/hello");
    scyna::Engine::instance()->start();
}
