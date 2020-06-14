
#ifndef SINA_SFILESENDER_FILESENDER_H
#define SINA_SFILESENDER_FILESENDER_H

using fs = boost::filesystem;

#define PORT 8080

class FileSender {


public:

    FileSender();
    ~FileSender();
    int sendDirectory();
    void setPath(fs::path& path);
    void sendingPreparation();

private:

    const fs::path& path;
    int server_fd;
    int new_socket;
    int valread;

};


#endif
