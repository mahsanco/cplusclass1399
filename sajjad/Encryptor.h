#ifndef UNTITLED_ENCRYPTOR_H
#define UNTITLED_ENCRYPTOR_H
#include <string>

class Encryptor {
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
    void Encrypt(const std::string& input_path, const std::string& output_path, std::string const& key) const noexcept;

    /**
    * Decrypt a file
    *
    * @param input_path path of file
    * @param output_path path of decrypted file
    *
    */
    void Decrypt(const std::string& input_path, const std::string& output_path, std::string const& key) const noexcept;
};


#endif //UNTITLED_ENCRYPTOR_H
