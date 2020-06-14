
#ifndef SINA_SFILESENDER_ENCRYPTION_H
#define SINA_SFILESENDER_ENCRYPTION_H

using fs = boost::filesystem;

class Encryption {

public:
    Encryption(const fs::path& path);
    ~Encryption();
    void encryptDirectory();
    void decryptDirectory();

private:
    const fs::path& path;
    void setPath(const fs::path& path); // Use it at Constructor to set the value of path
                                        // - Its advantage is that the code will be cleaner
};


#endif
