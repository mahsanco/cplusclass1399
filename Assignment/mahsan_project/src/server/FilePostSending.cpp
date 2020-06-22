#include "FilePostSending"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


FilePostSending::FilePostSending(const std::string &_file_name, size_t _file_size)
{
    file_name = _file_name;
    file_size = _file_size;
}


FilePostSending::write_file(const std::string &file_path, std::vector<std::string> &blocks)
{
    ofstream file(file_path, std::ios::binary);

    for(int block_num = 0; block_num < blcoks.size(); block_num++)
    {
       
        char* buffer = new char[blocks[block_num].size()];
        file.write(buffer, sizeof(buffer));
	delete [] buffer;

    }

     file.close();
    

}

