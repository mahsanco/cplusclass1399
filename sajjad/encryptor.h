#include <fstream>

class Encryptor{
    public:
    
    /// Constructor 
    Encryptor() = default;

    /**
    * Encrypt a file
    *
    * @param param1 file to encrypt
    *
    * @return encrypted file 
    */
    fstream Encrypt(fstream& file); 

    /**
    * Decrypt a file
    *
    * @param param1 file to decrypt
    *
    * @return decrypted file 
    */
    fstream Decrypt(fstream& file);
    

}