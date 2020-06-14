#include <fstream>

class Compressor{
    public:
        Compressor() = default;

        //method to compress a file into another file and return it
        fstream Compress(fstream file);

        //method to decompress a file into another file and return it
        fstream Decompress(fstream file);
}
