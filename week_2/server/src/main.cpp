#include "server.cpp"

int main()
{
    boost::asio::io_service io_service;
    Server srv(io_service, 15001);
    srv.start_accept();
    io_service.run();
    return 0;
}