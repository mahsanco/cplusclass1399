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
    std::ifstream file(_file_path, std::ios::in|std::ios::binary|std::ios::ate);
     

    if (file.is_open())
    {
        size = file.tellg();
	file_size = (size_t)size;
	file.seekg(0, std::ios::beg);
	file.read(&file_data[0], size);

	size_t t_file_size = file_size;

	while (t_file_size > 0)
	{
            std::string buffer;
	    size_t window = std::min(t_file_size, block_size);
	    file.read(&buffer[0], window);
	    blocks.push_back(buffer);
	    t_file_size -= window;

	}
	file.close();
    } 
    else std::cout << "Unable to open file";
	 
    
}



void FilePreSending::compress_file()
{
    
    int index, err;
    size_t len;
    zip *archive = zip_open((file_name + ".zip").c_str(), ZIP_CREATE, &err);
    zip_source *source = zip_source_buffer(archive, file_data.c_str(), len, 0);

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



/// small test
int main()
{
    std::string file_path = "/home/hossein/Desktop/1.txt";
    FilePreSending fp(file_path);

}

