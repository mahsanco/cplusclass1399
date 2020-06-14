#ifndef SINA_SFILESENDER_COMPRESSION_H
#define SINA_SFILESENDER_COMPRESSION_H

using fs = boost::filesystem;

#include <dirent.h>

class Compression {

public:
    Compression(const fs::path& path);
    ~Compression();
    void compress();
    void decompress(DIR);

private:
    const fs::path& path;
    void setPath(const fs::path& path); // Use it at Constructor to set the value of path
                                        // - Its advantage is that the code will be cleaner
};


#endif
