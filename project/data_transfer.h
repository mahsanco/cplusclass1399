#include <string>

class data_transfer
{
	public:
		
		/*
		 * @return instance of object
		 */
		static data_transfer *get_instance() ;
		
		/*
		 * @param hostname is name of server
		 * @param data is encrypted data that we want send
		 * @param port is exit port!
		 */
		static void sender(std::string hostname,std::string data,int port) ;
		
		/*
		 * @param is inner port
		 * @return is encrypted data that we received
		 */
		static std::string receiver(int port);
		/*
		 * Constructor
		 */
		data_transfer() ;
	private:
		static data_transfer *instance ;///Instance of object
	

};
