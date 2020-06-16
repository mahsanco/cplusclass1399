#include <string>

class Compressor{
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
    void Compress(const string& input_path,const string& output_path) const nonexcept;

    /**
    * Decompress a file
    *
    * @param input_path path of file  
    * @param output_path path of decompressed file 
    *
    */
    void Decompress(const string& input_path,const string& output_path) const nonexcept;
}
