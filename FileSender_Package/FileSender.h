
#ifndef SINA_SFILESENDER_FILESENDER_H
#define SINA_SFILESENDER_FILESENDER_H

#define PORT 8080

class FileSender {


public:

    FileSender();

    int sendDirectory();

private:

    int server_fd;
    int new_socket;
    int valread;

};


#endif
