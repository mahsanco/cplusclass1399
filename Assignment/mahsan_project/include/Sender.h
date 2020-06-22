#ifndef SENDER_H
#define SENDER_Hi

#include <string>
#include <vector>
#include <netinet/in.h>

/***************************************************************************//**
 * This class sends data to server(reciever).
 ******************************************************************************/

class Sender
{


public:
     
   /***************************************************************************//**
    * A constructor with one argument: port of server.
    ******************************************************************************/ 
    Sender(size_t port);



   /***************************************************************************//**
    * This member function sends a block of data,
    * it gets a block of data by refrence as argument,
    * it would return zero, if could send successfuly.
    ******************************************************************************/
    void send_block(const std::string& block);

    
   /***************************************************************************//**
    * This member function sends bocks of data, which are stored in
    * a vector, one argument: a vector of strings
    ******************************************************************************/
    void send_file(std::vector<std::string> &blocks);


   /***************************************************************************//**
    * This member function sends an integer, one argument: integer or size_t
    ******************************************************************************/    
    void send_size(size_t size); 


private:
 
    size_t port; ///< the port on which reciever is listening.
    struct sockaddr_in reciever_info;
    int m_socket;
};


#endif
      
