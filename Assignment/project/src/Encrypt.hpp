/**
 * Child class of Encryptor class.
 * Returns a encrypted version of a input string.
 * Encrypted an input string using the ... algorithm.
 */

#ifndef _Encrypt_
#define _Encrypt_ 

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include "Encryptor.hpp"
#include "structures.hpp"

class Encrypt : public Encryptor
{
private :

public :

    Encrypt();
    
    ~Encrypt();
    
    /// Encrypt the data in the received directory
    std::string encrypt_file_input(char input[1024]); 
	
};

#endif