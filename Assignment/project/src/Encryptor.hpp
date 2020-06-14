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
private:
    std::string file_name; /// Keeps the directory name
    std::vector <std::string> data; /// Keeps the directory data

public:
    Encryptor(std::string _file_name);
    ~Encryptor();
	
};

#endif
