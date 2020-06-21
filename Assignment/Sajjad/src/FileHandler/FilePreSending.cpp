#include "FilePreSending.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <zip.h>


FilePreSending::FilePreSending(const std::string &_file_path, const std::string &_file_name, _is_directory)
{

    file_path = _file_path;
    file_name = _file_name;
    is_directory = _is_directory;
    blocks = new std::vector<std::string>;
    
    read_file(_file_path, 128);

}


void FilePreSending::read_file(const std::string &_file_path)
{   

    file_path = _file_path;
    std::ifstream fin(file_path, std::ios::binary);

    if(!fin) 
    {
        std::cerr << "Unabel to open file."
    }
    else 
    {
        while(!fin.eof())
        {  
	    	
           std::string buffer;
           fin.read(&buffer, block_size)
           blocks.push_back(buffer);
	}

    }

    fin.close();

}



void FilePreSending::compress_file()
{
    
    int index, err;
    zip *archive = zip_open(file_name + ".zip", ZIP_CREATE. &err);
    size_t len;
    char *data = readfile(file_path + "/" + file_name, &len);
    zip_source *source = zip_source_buffer(archive, data, len, 0);

    if(source == NULL) 
    {  
        std::cout << "failed to create source buffer. " << zip_strerror(archive) << std::endl;
        return ;    
    }

    index = (int)zip_add(archive, file_path + "/"  + file_name, source);

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
    std::string file_path = "/home/hossein/Desktop";
    std::string file_name = "1.txt";    
    FilePreSending fp(file_path, file_name);
    fp.compress_file();

}


