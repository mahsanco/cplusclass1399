#include "file_type.h"
#include <boost/filesystem/fstream.hpp>
file_type::file_type(boost::filesystem::path path ) 
{
   size=boost::filesystem::file_size(path) ;

}
	
std::string const& file_type::get_name() 
{
    return name ;
}
	
		
std::string const& file_type::get_data() 
{
    return data ;
}
	
	
std::string const& file_type::get_type_file() 
{
    return type_file ;
}
	

boost::filesystem::path const& file_type::get_path() 
{
    return path ;
}   
int file_type::get_size()
{
    return size ;
}
