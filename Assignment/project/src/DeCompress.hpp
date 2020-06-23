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
private :

public :

    DeCompress(std::string _file_name);

    ~DeCompress();

    /// Reads the data in the received directory
    std::string read_file_data(); 

    /// Decompresses the data in the received directory
    std::string decompress_file_input(); 
    
     /// Sends the decompressed result
    void send_decompressed();
	
};

#endif