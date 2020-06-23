#ifndef _DATA_SENDER_H_
#define _DATA_SENDER_H_

#include <string>
#include <arpa/inet.h> 


class data_sender
{
    private:
        int sock ;
        struct sockaddr_in serv_addr; 

    public:


        /*
         * @param data is encrypted data that we want send
         */
        void sender(std::string data) ;

        /*
         * Constructor
         * @param hostname is name of server
         * @param port is exit port!
         */
        data_sender(std::string hostname,int port) ;

        /*
         *Deconstructor
         */
        ~data_sender();

};

#endif
