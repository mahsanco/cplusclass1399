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
    * This member function listens on defined socket, and checks if there is a new 
    * sender to make a connection with.
    ******************************************************************************/    
    void run();

   /***************************************************************************//**
    * this member function responses to sender and handles the data coming from 
    * it, it has one argument: socket id 
    ******************************************************************************/
    void handle_sender(int socket);
    


private:

    size_t port; ///< the port on which reciever is listening.
    struct sockaddr_in reciever_info;
    int info_len;
    int master_socket;
    std::vector<int> senders;
    const size_t max_senders = 20;

};


#endif
