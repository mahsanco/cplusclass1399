/**
 * Server
 * Child class of FileReciver class.
 * Recive the submitted directory from the server.
 */

#ifndef _Server_
#define _Server_ 

#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include "FileReciver.hpp"
#include "Encryptor.hpp"
#include "Decrypt.hpp"

#define PORT 8080 
#define IP_PROTOCOL 0 
#define IP_ADDRESS "127.0.0.1"


class Server : public FileReciver
{
private :

    int sock_fd;

    int new_socket;
    
    struct sockaddr_in serv_addr; 

    std::vector <std::string> file_data;

    Decrypt *decrypt;

public :

    Server();

    ~Server();

    /// Initial server
    virtual void make_ready_server();

    /// Save the name of file
    virtual std::string get_name_from_socket();

    /// Save the data of file
    virtual std::vector <std::string> get_data_from_socket();

};

#endif