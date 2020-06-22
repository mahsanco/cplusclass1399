#include "FilePreSending.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <experimental/filesystem>
#include <zip.h>

namespace fs = std::experimental::filesystem;

FilePreSending::FilePreSending(const std::string &_file_path)
{

   
    file_path = _file_path;
    is_directory = fs::is_directory(fs::status(_file_path));
    file_name = fs::path(_file_path).filename();
    

}



void FilePreSending::read_file(const std::string &_file_path, size_t block_size)
{   
    
    std::streampos size;
    std::ifstream file(_file_path, std::ios::binary|std::ios::ate);
    
    if (file.is_open())
    {
        size = file.tellg();
	file_size = (size_t)size;
	char *content = new char[file_size];
	file.seekg(0, std::ios::beg);
	file.read(content, size);
	file_data = std::string(content);
    	
	size_t t_file_size = file_size;

	while (t_file_size > 0)
	{
	    size_t window = std::min(t_file_size, block_size);
	    char* buffer = new char[window];
	    file.read(buffer, window);
	    blocks.push_back(std::string(buffer));
	    t_file_size -= window;
	    delete [] buffer;

	}

	delete [] content;
	file.close();
    } 
    else std::cout << "Unable to open file";
	 
    
}



void FilePreSending::compress_file()
{
    
    int index, err;
    
    std::string zip_name = file_name + std::string(".zip");    
    zip *archive = zip_open((zip_name).c_str(), ZIP_CREATE, &err);
   
    if(!archive)
    {
        std::cout << "could not open or create archive" <<  std::endl;
        exit(1) ;
    }

    zip_source *source = zip_source_buffer(archive, file_data.c_str(), file_size, 0);

    if(source == NULL) 
    {  
        std::cout << "failed to create source buffer. " << zip_strerror(archive) << std::endl;
        return ;    
    }

    index = (int)zip_add(archive, file_path.c_str(), source);

    if(index < 0)
    {
        zip_source_free(source);
	std::cout << "failed to add file to archive. " << zip_strerror(archive) << std::endl;
        return ;

    }

    zip_close(archive);
    
}


std::string FilePreSending::get_file_name()
{
    return file_name;
}

std::string FilePreSending::get_file_data()
{
    return file_data;

}



