#include <filesystem>
#include <vector>
#include "file_type.h"
class compress
{

	public:
		
		/*
		 * @return instance of object
		 */
		static compress *get_instance() ;
	
		/*
		 * compress a path
		 * @param path of file or folder
		 * @return compressed file in one object
		 */
		static std::vector<file_type> compressor(std::filesystem::path path) ;
		
		/*
		 * decompress a group of files in path
		 * @param object_of_files is our files
		 * @param path is a path that we put our files there
		 */
		static void decompress(std::vector<file_type> &object_of_files,std::filesystem::path path) ;
	private:
		/*
		 * constructor
		 */
		compress() ;
		static compress *instance ;/*instance of object*/
	
};
