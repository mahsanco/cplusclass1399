#include "data_sender.h"
#include <unistd.h> 
//based on geeksforgeeks
data_sender::data_sender(std::string hostname,int port) 
{
    sock = socket(AF_INET, SOCK_STREAM, 0) ; 
	if(sock<0)
    {
       //exception 
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(port); 

    if(inet_pton(AF_INET,hostname.c_str() , &serv_addr.sin_addr)<=0) 
	{ 
        //exception    
    } 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		//exception  
	}   
}

void data_sender::sender(std::string data)
{
    //not completed
    send(sock , data.c_str() , (int)data.size() , 0 ); 
}

data_sender::~data_sender()
{
    close(sock) ;
}
