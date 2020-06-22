#ifndef UNTITLED_COMPRESSOR_H
#define UNTITLED_COMPRESSOR_H
#include <string>

class Compressor {
public:
/// Constructor
    Compressor() = default;

    /**
    * Compress a file
    *
    * @param input_path path of file
    * @param output_path path of compressed file
    *
    */
    void Compress(const std::string& input_path,const std::string& output_path) const noexcept;

    /**
    * Decompress a file
    *
    * @param input_path path of file
    * @param output_path path of decompressed file
    *
    */
    void Decompress(const std::string& input_path,const std::string& output_path) const noexcept;
};


#endif //UNTITLED_COMPRESSOR_H
