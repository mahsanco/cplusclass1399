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
    Compressor* compressor; 
    Encryptor* encryptor;
    int server_is_ready();
    int save_on_server();

public:
    void recive_file();
};

#endif
