#ifndef cplusclass1399_sajjad_COMPRESSOR_H
#define cplusclass1399_sajjad_COMPRESSOR_H

#include<string>

class Compressor {
private:
    std::string m_input;
    std::string m_output;
public:
    Compressor(std::string input, std::string output);

    void compress(); // reads file from path m_input and compresses it to path m_output
};


#endif
