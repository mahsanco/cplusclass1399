#ifndef SINA_SFILESENDER_COMPRESSION_H
#define SINA_SFILESENDER_COMPRESSION_H

using fs = boost::filesystem;

class Compression {

public:

    /*
     * \mainpage
     * @note The constructor of the Compression Class
     * */
    Compression(const fs::path& path);

    /*
     * @note The Destructor of the Compression Class
     * */
    ~Compression();

    /*
     * @brief This function compresses the directory that is saved in the "path" field of Class
     * */
    void compress();

    /*
     * @brief This function decompresses the directory of field "path"
     * */
    void decompress();

private:

    /*
    * \mainpage
    * @brief The field to save path of directory which should be compressed
    * */
    const fs::path& path;

    /*
    * @brief Use it at Constructor to set the value of path
    * @note Its advantage is that the code will be cleaner
    * */
    void setPath(const fs::path& path);

    /*
    * @brief Getter to get the value of directory path after its compression
    * */
    fs::path& getPath();
};


#endif
