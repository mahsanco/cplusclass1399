
#ifndef SINA_SFILESENDER_ENCRYPTION_H
#define SINA_SFILESENDER_ENCRYPTION_H

using fs = boost::filesystem;

class Encryption {

public:

    /*
     * \mainpage
     * @note The constructor of the Encryption Class
     * */
    Encryption(const fs::path& path);

    /*
    * @note The Destructor of the Encryption Class
    * */
    ~Encryption();

    /*
    * @brief This function encrypts the directory "path" of Class
    * */
    void encryptDirectory();

    /*
    * @brief This function decrypts the directory of field "path"
    * */
    void decryptDirectory();

private:

    /*
   * \mainpage
   * @brief The field to save path of directory which should be encrypted
   * */
    const fs::path& path;

    /*
  * @brief Use it at Constructor to set the value of path
  * @note Its advantage is that the code will be cleaner
  * */
    void setPath(const fs::path& path);

    /*
   * @brief Getter to get the value of directory path after its encryption process
   * */
    fs::path& getPath();
};


#endif
