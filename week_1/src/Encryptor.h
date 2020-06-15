/***************************************************************************//**
 * Class encryptor
 *
 * This class encrypt compressed file for sending to server
 * and decrypt file to decompressing
 *
 * Auther: mahdigh
 * 
 * Cntact: mahdigh113@gmail.com 
 *
 * Created on: june 11 2020
 * 
 ******************************************************************************/

#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <string>

class Encryptor
{
public:

    Encryptor();

    /**
    * Encrypte compressed file
    *
    * @param {string} filename - file name.
    *
    * @return Encrypted file name
    */
    std::string encrypt(std::string filename );
    
    /**
   * Decrypte file
   *
   * @param {string} filename - file name.
   *
   * @return Encrypted file name
   */
    std::string decrypt(std::string filename );
};