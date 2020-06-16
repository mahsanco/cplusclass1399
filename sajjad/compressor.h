#include <string>

class Compressor{
    public:

    /// Constructor 
    Compressor() = default;

    /**
    * Compress a file
    *
    * @param param1 path of file  
    * @param param1 path of compressed file  
    *
    * @return void
    */
    void Compress(string inputPath, string outputPath);

    /**
    * Decompress a file
    *
    * @param param1 path of file  
    * @param param1 path of decompressed file 
    *
    * @return void
    */
    void Decompress(string inputPath, string outputPath);
}
