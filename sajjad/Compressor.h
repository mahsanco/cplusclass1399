#ifndef cplusclass1399_sajjad_COMPRESSOR_H
#define cplusclass1399_sajjad_COMPRESSOR_H

#include<string>
class Compressor {
    private:
        std::string m_input;
        std::string m_output;
    public:
        Compressor(std::string input, std::string output);
        void compress();
};


#endif
