#include <string>
#include <filesystem>
#include <vector>
#include "file_type.h"

class encryption
{
	public:
		
		/*
		 * @return instance of object
		 */
		static encryption *get_instance() ;

		/*
		 * encrypt group of files
		 * @param group of files that would be encrypted
		 * @return a strign that represent files
		 */
		static std::string encrypt(std::vector<file_type> files) ;

		/*
		 * decrypt a string
		 * @param an encrypted string
		 * @return group of files
		 */
		static std::vector<file_type> encrypt(std::string files) ;
		
	private:
		/*
		 * constructor
		 */
		encryption() ;
		static encryption *instance ;/*instance of object*/
	
