#ifndef RECIEVER_H
#define RECIEVER_H

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>

/***************************************************************************//**
 * This class makes listens on a defined port, and answers to file senders and
 * recieves their files
 ******************************************************************************/

class Reciever
{


public:

   /***************************************************************************//**
    * A constructor with two arguments: port and ip address of reciever.
    ******************************************************************************/
    explicit Reciever(size_t port);

   /***************************************************************************//**
    * This member function listen on defined socket, and checks if there is a new 
    * sender to make a connection with.
    ******************************************************************************/    
    void listen();

   /***************************************************************************//**
    * this member function make a new connection, actually runs a new thread,
    * and answers senders` requests.
    ******************************************************************************/
    void make_new_connection();

   /***************************************************************************//**
    * This member function recieves a block of data,
    * arguments: the vector of blocks by reference to push recieved block in it
    ******************************************************************************/
    int recieve(std::vector<std::string> &blocks);

    

private:

    size_t port; ///< the port on which reciever is listening.
    struct sockaddr_in socket_address;
};


#endif
