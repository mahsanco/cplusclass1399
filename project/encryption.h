#ifndef _ENCRYPTION_H_
#define _ENCRYPTION_H_

#include <string>
#include <vector>
#include "file_type.h"

class encryption
{
	public:
		
		/*
		 * Encrypt group of files
		 * @param group of files that would be encrypted
		 * @return a strign that represent files
		 */
		static std::string encrypt(std::vector<file_type> files) ;

		/*
         * Decrypt a string
		 * @param an encrypted string
		 * @return group of files
		 */
		static std::vector<file_type> encrypt(std::string files) ;
		
		/*
		 * Constructor
		 */
		encryption() ;
	
    private:
};

#endif
