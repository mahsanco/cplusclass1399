/**
 * Client
 * Child class of FileSender class.
 * Send the received directory to the server.
 */

#ifndef _Client_
#define _Client_ 

#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string>
#include <string.h> 
#include "FileSender.hpp"

#define PORT 8080 
#define IP_PROTOCOL 0 
#define IP_ADDRESS "127.0.0.1"


class Client : public FileSender
{
private :

    int sock_fd;
    
    struct sockaddr_in serv_addr; 

public :

    Client();

    ~Client();

    /// Connect to the server with socket
    virtual void connect_to_server();

    /// Send directory name to the server
    virtual void send_name_to_server(); 

    /// Send directory data to the server
    virtual void send_data_to_server(std::string data); 

};

#endif