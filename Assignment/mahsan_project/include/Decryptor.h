#ifndef DECRYPTOR_H
#define DECRYPTOR_H

#include <string>

  
/***************************************************************************//**
 * This class decrypts the block of data which is from sender,
 * key is also sended by sender. 
 ******************************************************************************/

class Decryptor
{

public:

    /***************************************************************************//**
     * This constructor has one argument: the sended key from sender
     ******************************************************************************/
    explicit Decryptor(const std::string &_key);

    /***************************************************************************//**
     * This member function decrypts the block of data,
     * it has one argument: the block of data by reference,
     * it decrypts in place.
     *t****************************************************************************/
    void decrypt(std::string& block);
    

    /***************************************************************************//**
     * This member function returns the key.
     ******************************************************************************/
    std::string get_key();

private:
    std::string key; ///< sended key

}


#endif
      
