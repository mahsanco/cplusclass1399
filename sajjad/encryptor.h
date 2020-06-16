#include <string>

class Encryptor{
    public:
    
    /// Constructor 
    Encryptor() = default;

    /**
    * Encrypt a file
    *
    * @param input_path path of file 
    * @param output_path path of encrypted file
    *
    */
    void Encrypt(const string& input_path, const string& output_path) const nonexcept; 

    /**
    * Decrypt a file
    *
    * @param input_path path of file 
    * @param output_path path of decrypted file 
    *
    */
    void Decrypt(const string& input_path, const string& output_path) const nonexcept;
    

}