#ifndef RECIEVER_H
#define RECIEVER_H
#include <string>


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
    Reciever(size_t port, const std::string &ip_address);

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

   /***************************************************************************//**
    * This function  sets port member field.
    ******************************************************************************/
    void setPort(size_t);

   /***************************************************************************//**
    * This sets ip_address field.
    ******************************************************************************/
    void setIpAddress(const std::string& _ip_address);

private:

    size_t port; ///< the port on which reciever is listening.
    std::string ip_address; ///< the ip address of reciever

}


#endif
