#include "data_receiver.h"
#include <sys/types.h> 
#include <sys/socket.h> 

//based on geeksforgeeks
data_receiver::data_receiver(int port)
{
    master_socket = socket(AF_INET , SOCK_STREAM , 0) ;
    if(master_socket==0)
    {
        //exception 
    } 
    int opt=true ;
	if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,  sizeof(opt)) < 0 ) 
    {
        //exception 
    }
    address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons( port ); 

    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0) 
	{ 
        //exception 		
    } 
    if (listen(master_socket, 3) < 0) 
	{ 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 
		
	//accept the incoming connection 
	addrlen = sizeof(address); 
    
    demon_thread=std::thread(demon) ;

}

data_receiver::~data_receiver()
{
    demon_thread.join() ;
}
