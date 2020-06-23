/**
 * Child class of Decryptor class.
 * Returns a decrypted or version of a input string.
 * Decrypted an input string using the ... algorithm.
 */

#ifndef _Decrypt_
#define _Decrypt_ 

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Encryptor.hpp"
#include "structures.hpp"


class Decrypt : public Encryptor
{
private :

public :

    Decrypt();
    
    ~Decrypt();
    
    /// Decrypt the data in the received directory
    std::string decrypt_file_input(char input[1024]); 
	
};

#endif