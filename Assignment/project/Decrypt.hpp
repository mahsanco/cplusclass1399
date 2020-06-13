#ifndef _Decrypt_
#define _Decrypt_ 

#include <iostream>
#include <string>
#include "Encryptor.hpp"

class Decrypt : public Encryptor
{
private:
    Decrypt(std::string filename);
    ~Decrypt();

public:
	
};

#endif
