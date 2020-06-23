#include <string>
#include "file/Compressor.cpp"


using namespace std;


const string prj_path = "/home/ali/Desktop/cpp/mahsan/pr3/";

void testForCheckingCompressor(){
    string input = prj_path + "test.jpg";
    string output = prj_path + "testc.jpg";
    string outputDecom = prj_path + "testd.jpg";

    Compressor comp = Compressor(input, output);
    comp.compress();
    Compressor dec = Compressor(output, outputDecom);
    dec.decompress();

}



int main()
{
    testForCheckingCompressor();
    return 0;
}

