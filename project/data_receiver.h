#ifndef _DATA_RECEIVER_H_
#define _DATA_RECEIVER_H_

#include <string>
#include <thread>
#include <arpa/inet.h> 
#include <stack>
#include <utility>
#include <mutex> 
//this should be singleton
class data_receiver
{
    private:
        
        static int master_socket,addrlen ;
        static struct sockaddr_in address; 
        static bool end ;
        /*
         * all new received datas
         * first is sender info 
         * second is data
         */
        static std::stack<std::pair<std::string,std::string> > data_received ;

        /*
         * the demon is running in background 
         */
        static void demon() ;
        
        //thread of demon
        static std::thread demon_thread ;
        /*
         * for safety of stack
         */
        static std::mutex stack_use_safe ;

    public:	
		 
         /*
          * @return data_received
          */
   	     static std::stack<std::pair<std::string,std::string> > & get_data_received()
         {
            return data_received ;     
         }
         /*
          * @return stack_use_safe
          */
        static std::mutex & get_stack_use_safe() 
        {
            return stack_use_safe ;
        }
        /*
		 * @param is the socket we use
		 * @return is encrypted data that we received
		 */
		  static void receiver(int socket);
		  
          /*
           *end the demon
           */
          static void end_program()
          {
            end=true ;
          }
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
