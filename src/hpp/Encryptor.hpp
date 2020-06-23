/***************************************************************************//**
 * Class Encryptor Interface.
 ******************************************************************************/

#ifndef _ENCRYPTOR_HPP_
#define _ENCRYPTOR_HPP_

#include <string>

class Encryptor
{
private:
    Encryptor();

    static Encryptor* instance; /**< Instance of Encryptor to avoid making multiple objects. */
       
public:
    static Encryptor* get_instance() const noexcept;

    /** Encrypt a specific file and return the encrypted file name.
     *  @param {string} filename - Name of the file.
    */
    static std::string encrypt(std::string filename) const;
    
    /** Dncrypt a specific file and return the decrypted file name.
     *  @param {string} filename - Name of the file.
    */
    static std::string decrypt(std::string filename) const;
};

#endif