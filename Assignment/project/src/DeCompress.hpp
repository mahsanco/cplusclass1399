/**
 * Child Class of Compressor class.
 * Returns a decompressed version of a input string.
 * decompresses an input string using the ... algorithm.
 */

#ifndef _DeCompress_
#define _DeCompress_ 

#include <iostream>
#include <string>
#include <vector>
#include "Compressor.hpp"

class DeCompress : public Compressor
{
private:

    DeCompress(std::string _file_name);
    ~DeCompress();

public:
    std::string read_file_data(); /// Reads the data in the received directory
    std::string decompress_file_input(); /// /// Decompresses the data in the received directory
    void send_decompressed(); /// Sends the decompressed result
	
};

#endif
