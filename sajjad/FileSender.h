#ifndef UNTITLED_FILESENDER_H
#define UNTITLED_FILESENDER_H
#include <string>

class FileSender {
public:
    ///Constructor
    FileSender() = default;

    /**
    * send a file via socket
    *
    * @param input_path path of file
    * @param port port to listen on
    *
    */
    void send(const char *input_path, int port) const noexcept;

    /**
    * recieve a file from socket
    *s
    * @param output_path path of file to write in it
    * @param port port to listen on
    *
    */
    void receive(const char *output_path, int port) const noexcept;
};


#endif //UNTITLED_FILESENDER_H
