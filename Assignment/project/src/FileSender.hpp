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
private :

    std::string file_name;

    /// For compressing directory data
    Compressor* compressor;

    /// For encrypting directory data 
    Encryptor* encryptor; 

    /// Connect to the server with socket
    int connect_to_server(int port, std::string host); 
    
    /// Send directory name to the server
    int send_to_server(); 

public :

    FileSender();

    ~FileSender();

    /// Send compressed and encrypted directory
    void send_file(std::string _file_name); 
};

#endif