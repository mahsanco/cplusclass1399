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
private :

public :

    Encrypt(std::string _file_name);
    
    ~Encrypt();

     /// Reads the data in the received directory
    std::string read_file_data();
    
    /// Encrypt the data in the received directory
    std::string encrypt_file_input(); 
    
    /// Sends the encrypted result
    void send_encrypted(); 
	
};

#endif