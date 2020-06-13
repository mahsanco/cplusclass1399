/// Class Encryptor.
#include <string>

class Encryptor
{
public:
    /// class Constructor.
    Encryptor();

    /// The file is encrypted.
    /// Return value is name of the encrypted file.
    std::string encrypt(std::string filename /**< [in] Name of the file to encrypt. */);
    
    /// The file is decrypted.
    /// Return value is name of the decrypted file.
    std::string decrypt(std::string filename /**< [out] Name of the file to decrypt. */);
};