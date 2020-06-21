#ifndef _DATA_RECEIVER_H_
#define _DATA_RECEIVER_H_

#include <string>
#include <thread>
#include <arpa/inet.h> 

//this should be singleton
class data_receiver
{
    private:
        
        int master_socket,addrlen ;
        struct sockaddr_in address; 
      
        /*
         * the demon is running in background 
         */
        static void demon() ;
        
        //thread of demon
        std::thread demon_thread ;
   	public:	
		
	   
        /*
		 * @param is the socket we use
		 * @return is encrypted data that we received
		 */
		  std::string receiver(int socket);
		
         /*
		  * Constructor
		  * @param port is inner port!         
		  */
         data_receiver(int port) ;
         
         /*
          * Deconstructor
          */
         ~data_receiver() ;
         

 };

#endif
