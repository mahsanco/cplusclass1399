#include <fstream>

class Compressor{
    public:

    /// Constructor 
    Compressor() = default;

    /**
    * Compress a file
    *
    * @param param1 file to compress
    *
    * @return compressed file 
    */
    fstream Compress(fstream& file);

    /**
    * Decompress a file
    *
    * @param param1 file to Decompress
    *
    * @return Decompressed file 
    */
    fstream Decompress(fstream& file);
}
