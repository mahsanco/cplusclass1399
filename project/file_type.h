#include <string>
#include <boost/filesystem.hpp>

class file_type
{
	private :
	
		boost::filesystem::path path ;///Path of file
		std::string name ;///Name of file
		std::string data ;///Data of file 
		int size ;///Size of file
		std::string type_file ;///Type of file
	public:
	
		/*
		 * @param is path of file
		 */
		file_type(boost::filesystem::path path ) ;
	
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
		std::string const& get_type_file() ;
	
		/*
		 * @return path of file
		 */
		boost::filesystem::path const& get_path() ;
		
		/*
		 * @return size of file
		 */
		int get_size();

};
