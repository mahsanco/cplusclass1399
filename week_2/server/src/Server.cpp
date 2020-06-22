/***************************************************************************//**
 * Class server
 *
 * Start socket server and save file from client
 *
 * Auther: mahdigh
 *
 * Cntact: mahdigh113@gmail.com
 *
 * Created on: june 11 2020
 *
 ******************************************************************************/

//#ifndef Server_H
//#define Server_H


//#include "Compressor.h"
//#include "Encryptor.h"
#include "Server.h"




    Session::Session(boost::asio::ip::tcp::socket&& socket)
        : socket(std::move(socket))
    {
    }

    void Session::start()
    {
        boost::asio::async_read_until(socket, streambuf, '\n', [self = shared_from_this()](boost::system::error_code error, std::size_t bytes_transferred)
        {
            std::cout << std::istream(&self->streambuf).rdbuf();
        });
    }


    Server::Server(boost::asio::io_service& io_service, std::uint16_t port)
        : io_service(io_service)
        , acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
    {
    }

    void Server::start_accept()
    {
        socket.emplace(io_service);

        acceptor.async_accept(*socket, [&](boost::system::error_code error)
            {
                std::make_shared<Session>(std::move(*socket))->start();
                start_accept();
            });
    }


