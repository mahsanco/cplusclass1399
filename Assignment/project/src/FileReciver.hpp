/**
 * File Reciver
 * Connect to the server.
 * Recive a compressed and encrypted directory from server.
 */

#ifndef _FileReciver_
#define _FileReciver_ 

#include <iostream>
#include <string>
#include "Compressor.hpp"
#include "Encryptor.hpp"


class FileReciver
{
private :

    std::string file_name;

    /// For decompressing directory data
    Compressor* compressor; 

    /// For decrypting directory data
    Encryptor* encryptor; 

    /// Prepare the server to recive and save the directory
    int server_is_ready(int port); 

    /// Save the downloaded directory
    int save_on_server(); 

public :

    FileReciver();
    
    ~FileReciver();

    /// Recive the compresed and encrypted directory
    void recive_file(std::string _file_name); 
};

#endif