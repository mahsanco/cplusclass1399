#include <fstream>

class Encryptor{
    public:
        //constructor that gets the file and initialize the it
        Encryptor() = default;

        //method to encrypt a file into another file 
        fstream Encrypt(fstream file); 

        //method to decrypt a file into another file
        fstream Decrypt(fstream file);

}