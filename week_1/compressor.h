/// Class Compressor.
#include <string>

class Compressor
{
public:
    /// class Constructor.
    Compressor();
    
    /// files and directories are compressed.
    /// Return value is name of the compressed file.
    std::string compress(std::vector<string> addresses /**< [in] Addresses of the files or directories to compress. */);
    
    /// file is decompressed.
    /// Return value is name of the decompressed file that is a directory.
    std::string decompress(std::string filename /**< [out] Name of the file to decompress. */);
};
