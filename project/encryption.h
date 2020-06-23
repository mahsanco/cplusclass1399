#ifndef _ENCRYPTION_H_
#define _ENCRYPTION_H_

#include <string>

class encryption
{
	public:
		
		/*
		 * Encrypt group of files
		 * @param group of files that would be encrypted
		 * @return a string that represent files
		 */
		static std::string encrypt(std::string) ;

		/*
         * Decrypt a string
		 * @param an encrypted string
		 * @return decrypted string
		 */
		static std::string decrypt(std::string) ;
		
		/*
		 * Constructor
		 */
		encryption() ;
	
    private:
};

#endif
