/**
 * File Sender
 * Connect to the server.
 * Send a compressed and encrypted directory to server.
 */

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

    std::string file_name;
    Compressor* compressor; /// For compressing directory data
    Encryptor* encryptor; /// For encrypting directory data

    int connect_to_server(int port, std::string host); /// Connect to the server with socket
    int send_to_server(); /// Send directory name to the server

public:
    void send_file(std::string _file_name); /// Send compressed and encrypted directory
};

#endif
