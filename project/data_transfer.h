#ifndef _DATA_TRANSFER_H_
#define _DATA_TRANSFER_H_

#include <string>

class data_transfer
{
    private:
		
   	public:
			
		
		/*
		 * @param hostname is name of server
		 * @param data is encrypted data that we want send
		 * @param port is exit port!
		 */
		  void sender(std::string hostname,std::string data,int port) ;
		
		/*
		 * @param is inner port
		 * @return is encrypted data that we received
		 */
		  std::string receiver(int port);
		/*
		 * Constructor
		 */
         data_transfer() ;
	
 };

#endif
