/**
 * Child class of Decryptor class.
 * Returns a decrypted or version of a input string.
 * Decrypted an input string using the ... algorithm.
 */

#ifndef _Decrypt_
#define _Decrypt_ 

#include <iostream>
#include <string>
#include "Encryptor.hpp"

class Decrypt : public Encryptor
{
private:
    Decrypt(std::string _file_name);
    ~Decrypt();

public:
    std::string read_file_data(); /// Reads the data in the received directory
    std::string encrypt_file_input(); /// Decrypt the data in the received directory
    void send_encrypted(); /// Sends the Decrypted result
	
};

#endif
