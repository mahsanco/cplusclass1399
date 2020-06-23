#ifndef _COMPOSER_H_
#define _COMPOSER_H_


#include <boost/filesystem.hpp>
#include <vector>
#include "file_type.h"
class compress
{

	public:
		/*
         * This library would decrease size of string
         * To send to server
         * I used gzip
         */
			
		/*
		 * Compress a string
		 * @param uncompressed string (this would be from Serialization)
		 * @return compressed string
		 */
		static std::string compressor(std::string) ;
		
		/*
		 * Decompress a string
		 * @param compressed string
		 * @return uncompressed string
		 */
		static std::string decompress(std::string) ;
		
        /*
		 * Constructor
		 */
		compress() ;

	private:

};

#endif
