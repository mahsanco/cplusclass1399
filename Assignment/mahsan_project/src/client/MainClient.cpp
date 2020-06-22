#include "FilePreSending.h"
#include <iostream>
#include <string>

int main()
{
    std::string file_path = "/home/hossein/Desktop/1.txt";
    std::cout << "Hi";
    FilePreSending fp(file_path);
    std::cout << "bye";
    fp.read_file(file_path, 128);
    fp.compress_file();
    std::cout << fp.get_file_data(); 
    return 0;
}
