#include <fstream>

class Encryptor{
    public:
    
    /* Constructor */
    Encryptor() = default;

    /* Receives a file as input and returns an Encrypted file */
    fstream Encrypt(fstream file); 

    /* Receives an encrypted file as input and returns a Decrypted file */ 
    fstream Decrypt(fstream file);

    private:

    fstream encryptedFile;
    fstream decryptedFile;

}