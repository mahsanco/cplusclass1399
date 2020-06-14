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
private:
    FileReciver();
    ~FileReciver();

    std::string file_name;
    Compressor* compressor; /// For decompressing directory data
    Encryptor* encryptor; /// For decrypting directory data

    int server_is_ready(int port); /// Prepare the server to recive and save the directory
    int save_on_server(); /// Save the downloaded directory

public:
    void recive_file(std::string _file_name); /// Recive the compresed and encrypted directory
};

#endif
