#include <iostream>
#include <fstream>
#include "Encryptor.h"


void Encryptor::Encrypt(const std::string &input_path, const std::string &output_path,
                        const std::string &key) const noexcept {
    std::ifstream fl(input_path);
    fl.seekg( 0, std::ios::end );
    size_t len = fl.tellg();
    char *msg = new char[len];
    fl.seekg(0, std::ios::beg);
    fl.read(msg, len);
    fl.close();
    for (std::string::size_type i = 0; i < len; ++i)
        msg[i] ^= key[i%key.size()];
    std::ofstream output_file(output_path);
    output_file << msg;

}

void Encryptor::Decrypt(const std::string &input_path, const std::string &output_path,
                        const std::string &key) const noexcept {
    Encrypt(input_path, output_path, key);

}
