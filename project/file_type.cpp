#include "file_type.h"
#include <boost/filesystem/fstream.hpp>
#include <utility>
#include <cstdlib>
#include <fstream>
file_type::file_type(boost::filesystem::path construct_path )
{
    this->path=construct_path ;
    if(boost::filesystem::is_directory(construct_path))

    {
        size=0 ;
        data="" ;
    }
    else
    {
        size=(int)boost::filesystem::file_size(path) ;
        std::ifstream file(path.string()) ;
        data=std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    }   
}	

std::string const& file_type::get_data() 
{
    return data ;
}

boost::filesystem::path const& file_type::get_path() 
{
    return path ;
}   
int file_type::get_size()
{
    return size ;
}
std::vector<file_type> file_type::files_of_a_path(boost::filesystem::path path) 
{
    std::vector<file_type> all_files ;
    //first path is directory path
    all_files.push_back(path) ;
    for(auto& p: boost::filesystem::recursive_directory_iterator(path))
        if(boost::filesystem::is_regular_file(p.path()) || boost::filesystem::is_directory(p.path()))
            all_files.push_back(file_type(p.path())) ;
    return all_files ;

}
/*
 * TODO:
 * Make a string from vector<file_type>
 * Format:size_of_vector+' ' + each file_type(file 0+file 1+... file n-1)
 * Each file_type format:
 * Size of data + ' ' + data +size of path + ' ' +path 
 */
std::string file_type::vector_of_files_to_string(std::vector<file_type> vector_of_files) 
{

    std::string return_value="" ;
    return_value+=std::to_string(vector_of_files.size())+' ' ;
    for(file_type i:vector_of_files)
    {
        return_value+=std::to_string(i.get_size())+" " ;
        return_value+=i.get_data() ;
        std::string str_path=i.get_path().string() ;
        return_value+=std::to_string(str_path.size())+" " ;
        return_value+=str_path ;
    }
    return return_value ;
}


int file_type::string_to_int(const std::string&  str, int &index)
{
    std::string number_str="" ;
    while(str[index]!=' ')
        number_str+=str[index++] ;
    index++ ;
    return std::stoi(number_str) ;
}
/*
 * TODO:
 * Change a Serialized string back to the vector<file_type>
 * Format:size_of_vector+' ' + each file_type(file 0+file 1+... file n-1)
 * Each file_type format:
 * Size of data + ' ' + data +size of path + ' ' +path 
 */
std::vector<file_type> file_type::string_to_vector_of_files(std::string data) 
{
    int index=0 ;
    int size_of_vector=string_to_int(data,index) ;
    std::vector<file_type> return_value ;
    for(int i=0;i<size_of_vector;i++)
    {
        int size_of_data=string_to_int(data,index) ;
        std::string file_data=data.substr(index,size_of_data) ;
        index+=size_of_data ;
        int size_of_path= string_to_int(data,index) ;
        boost::filesystem::path file_path(data.substr(index,size_of_path)) ;
        index+=size_of_path ;
        return_value.push_back(file_type(file_path,file_data,size_of_data)) ;
    }
    return return_value ;

}
/*
 * TODO:
 * Output all files into out_path
 * If it's a file copy the file
 * And if it's a directory create it
 */
void file_type::output_files(boost::filesystem::path inner_path , boost::filesystem::path out_path,std::vector<file_type> vector_of_files) 
{
    std::string inner_path_str=inner_path.string() ,out_path_str=out_path.string() ;

    boost::filesystem::create_directory(out_path) ;
    for(file_type i:vector_of_files)
    {
        std::string file_path=i.get_path().string() ;
        file_path.replace(0,inner_path_str.size(),out_path_str) ;
        if(i.get_size()!=0)
        {
            std::ofstream ofs (file_path, std::ofstream::out) ;
            ofs<<i.get_data() ;
            ofs.close() ;
        }
        else
            boost::filesystem::create_directory(file_path) ;
    }
}
