/**
 * Child class of Encryptor class.
 * Returns a encrypted version of a input string.
 * Encrypted an input string using the ... algorithm.
 */

#ifndef _Encrypt_
#define _Encrypt_ 

#include <iostream>
#include <string>
#include "Encryptor.hpp"

class Encrypt : public Encryptor
{
private:

    Encrypt(std::string _file_name);
    ~Encrypt();

public:
    std::string read_file_data(); /// Reads the data in the received directory
    std::string encrypt_file_input(); /// Encrypt the data in the received directory
    void send_encrypted(); /// Sends the encrypted result
	
};

#endif
