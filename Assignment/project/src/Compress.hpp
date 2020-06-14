/**
 * Child Class of Compressor class.
 * Returns a compressed version of a input string.
 * Compresses an input string using the ... algorithm.
 */

#ifndef _Compress_
#define _Compress_ 

#include <iostream>
#include <string>
#include <vector>
#include "Compressor.hpp"

class Compress : public Compressor
{
private:

    Compress(std::string _file_name);
    ~Compress();

public:
    std::string read_file_data(); /// Reads the data in the received directory
    std::string compress_file_input(); /// /// Compresses the data in the received directory
    void send_compressed(); /// Sends the compressed result
	
};

#endif
