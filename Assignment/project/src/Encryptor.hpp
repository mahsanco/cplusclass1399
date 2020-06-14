/**
 * Base class of Encrypt and Decrypt classes.
 * Returns a encrypted or decrypted version of a input string.
 * Encrypted or Decrypted an input string using the ... algorithm.
 */

#ifndef _Encryptor_
#define _Encryptor_

#include <iostream>
#include <string>
#include <vector>

class Encryptor
{
private :
    
    /// Keeps the directory name
    std::string file_name; 

    /// Keeps the directory data
    std::vector <std::string> data; 

public :
    Encryptor(std::string _file_name);
    
    ~Encryptor();
	
};

#endif