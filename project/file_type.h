#include <string>
#include <filesystem>

class file_type
{
	private :
	
		std::filesystem::path path ;/*path of file*/
		std::string name ;/*name of file*/
		std::string data ;/*data of file*/ 
		int size ;/*size of file*/
		std::string type_file ;/*type of file*/
	public:
	
		/*
		 * @param is path of file
		 */
		file_type(std::filesystem::path path ) ;
	
		/*
		 * @return name of file
		 */
		std::string const& get_name() ;
	
		/*
		 * @return data of file
		 */
		std::string const& get_data() ;
	
		/*
		 * @return type of file
		 */
		std::string const& type_file() ;
	
		/*
		 * @return path of file
		 */
		std::filesystem::path const& get_name() ;
		
		/*
		 * @return size of file
		 */
		int get_size();

}
