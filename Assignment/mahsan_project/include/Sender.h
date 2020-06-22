#ifndef SENDER_H
#define SENDER_H
#include <string>


/***************************************************************************//**
 * This class sends a prepared block of data
 * connects to server(reciever).
 ******************************************************************************/

class Sender
{


public:
     
   /***************************************************************************//**
    * A constructor with two arguments: port and ip address of server.
    ******************************************************************************/ 
    Sender(size_t port, const std::string &ip_address);


   /***************************************************************************//**
    * This member function tryes to make a connection with server(reciever)
    ******************************************************************************/
    void connect_to_server();


   /***************************************************************************//**
    * This member function sends a block of data,
    * it gets a block of data by refrence as argument,
    * it would return zero, if could send successfuly.
    ******************************************************************************/
    int send(const std::string&);

   /***************************************************************************//**
    * This function  sets port member field.
    ******************************************************************************/
    void setPort(size_t);

   /***************************************************************************//**
    * This sets ip_address field.
    ******************************************************************************/
    void setIpAddress(const std::string&);

private:
 
    size_t port; ///< the port on which reciever is listening.
    std::string ip_address; ///< the ip address of reciever
    
}


#endif
      
