
#ifndef SINA_SFILESENDER_FILESENDER_H
#define SINA_SFILESENDER_FILESENDER_H

using fs = boost::filesystem;

#define PORT 8080

class FileSender {


public:

    /*
    * \mainpage
    * @brief The constructor
    * */
    FileSender();

    /*
     * @brief The destructor
     * */
    ~FileSender();

    /*
     * @brief This function handle the process of sending directory after the sending preparations
     * */
    int sendDirectory();

    /*
    * @brief It prepare directory for sending process by compression and encryption of the directory at first
    * */
    void sendingPreparation();

    /*
    * @brief It sets the path which should be sent by this class
    * */
    void setPath(fs::path& path);


private:

    /*
    * \mainpage
    * @brief The field to save path of directory which should be sent
    * */
    const fs::path& path;

    /*
    * @brief Fields that show the file preparation is finished or not!
    * @note Actually it handles the sending preparation by fields isCompressed and isEncrypted
    * */
    bool isCompreesed;
    bool isEncrypted;

    /*
    * @brief The fields for socket and the process of sending file via socket in c++
    * */
    int server_fd;
    int new_socket;
    int valread;

};


#endif
