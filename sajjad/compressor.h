#include <fstream>

class Compressor{
    public:

    /* Constructor */
    Compressor() = default;

    /* Recieves a file as input and return a compressed file */
    fstream Compress(fstream file);

    /* Receives a compressed file as input and returns decompressed file */
    fstream Decompress(fstream file);

    private:

    fstream compressedFile;
    fstream decompressedFile;
}
