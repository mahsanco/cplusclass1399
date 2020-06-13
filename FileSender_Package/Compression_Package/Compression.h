#ifndef SINA_SFILESENDER_COMPRESSION_H
#define SINA_SFILESENDER_COMPRESSION_H


#include <dirent.h>

class Compression {

public:
    Compression(  );
    void compress();
    void decompress(DIR);
};


#endif
