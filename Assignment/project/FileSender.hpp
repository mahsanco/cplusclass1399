#ifndef _FileSender_
#define _FileSender_ 

#include <iostream>
#include <string>
#include "Compressor.hpp"
#include "Encryptor.hpp"

class FileSender
{
private:
    FileSender();
    ~FileSender();
    Compressor* compressor; 
    Encryptor* encryptor;
    int socket;
    int send_to_server();

public:
    void send_file(std::string file_name);
};

#endif
