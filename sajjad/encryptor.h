#include <string>

class Encryptor{
    public:
    
    /// Constructor 
    Encryptor() = default;

    /**
    * Encrypt a file
    *
    * @param param1 path of file 
    * @param param2 path of encrypted file
    *
    * @return void 
    */
    void Encrypt(string inputPath, string outputpath); 

    /**
    * Decrypt a file
    *
    * @param param1 path of file 
    * @param param2 path of decrypted file 
    *
    * @return void
    */
    void Decrypt(string inputPath, string outputPath);
    

}