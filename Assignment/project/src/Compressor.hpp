/**
 * Base Class of Compress and DeCompress classes.
 * Returns a compressed or decompressed version of a input string.
 * Compresses or decompresses an input string using the ... algorithm.
 */

#ifndef _Compressor_
#define _Compressor_ 

#include <iostream>
#include <string>
#include <vector>

class Compressor
{
private :

    /// Keeps the directory name
    std::string file_name; 
    
    /// Keeps the directory data
    std::vector <std::string> data; 
    
public :

    Compressor(std::string filename);

    ~Compressor();
	
};

#endif