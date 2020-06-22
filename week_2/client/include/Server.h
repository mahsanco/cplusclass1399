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

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <optional>
#include <boost/asio.hpp>


class Session
    : public std::enable_shared_from_this<Session>
{
public:

    Session(boost::asio::ip::tcp::socket&& socket);

    void start();

private:

    boost::asio::ip::tcp::socket socket;
    boost::asio::streambuf streambuf;
};

class Server
{
public:

    /**
    * Create socket
    *
    * @param {uint16} port - server is listening on this port
    */
    Server(boost::asio::io_service& io_service, std::uint16_t port);


    /**
    * start socket bind
    *
    * @return Server status
    */
    void start_accept();

    /// Handle threads and make new thread for new client
    void handle_accept() const;

private:

    boost::asio::io_service& io_service;
    boost::asio::ip::tcp::acceptor acceptor;
    std::optional<boost::asio::ip::tcp::socket> socket;
};
