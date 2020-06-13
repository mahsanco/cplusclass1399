#ifndef _DeCompress_
#define _DeCompress_ 

#include <iostream>
#include <string>
#include "Compressor.hpp"

class DeCompress : public Compressor
{
private:
    DeCompress(std::string filename);
    ~DeCompress();

public:
	
};

#endif
