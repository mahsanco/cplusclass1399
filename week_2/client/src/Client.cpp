#include <iostream>
#include <boost/asio.hpp>

namespace io = boost::asio;
namespace ip = io::ip;
using tcp = ip::tcp;
using error_code = boost::system::error_code;
using namespace std::placeholders;

class application
{
public:

    application(io::io_service& io_service, std::string const& hostname)
        : resolver(io_service)
        , socket(io_service)
    {
        request = "GET / HTTP/1.1\n"
            "Host: " + hostname + "\n"
            "Connection: close\n\n";

        resolver.async_resolve(hostname, "http", std::bind(&application::on_resolve, this, _1, _2));
    }

private:

    void on_resolve(error_code error, tcp::resolver::results_type results)
    {
        std::cout << "Resolve: " << error.message() << "\n";
        io::async_connect(socket, results, std::bind(&application::on_connect, this, _1, _2));
    }

    void on_connect(error_code error, tcp::endpoint const& endpoint)
    {
        std::cout << "Connect: " << error.message() << ", endpoint: " << endpoint << "\n";
        io::async_write(socket, io::buffer(request), std::bind(&application::on_write, this, _1, _2));
    }

    void on_write(error_code error, std::size_t bytes_transferred)
    {
        std::cout << "Write: " << error.message() << ", bytes transferred: " << bytes_transferred << "\n";
        io::async_read(socket, response, std::bind(&application::on_read, this, _1, _2));
    }

    void on_read(error_code error, std::size_t bytes_transferred)
    {
        std::cout << "Read: " << error.message() << ", bytes transferred: " << bytes_transferred << "\n\n"
            << std::istream(&response).rdbuf() << "\n";
    }

    tcp::resolver resolver;
    tcp::socket socket;
    std::string request;
    io::streambuf response;
};

int main(int argc, char* argv[])
{
    io::io_service io_service;
    application app(io_service, argv[0]);
    io_service.run();
    return 0;
}