#include <compressor.h>
#include <encryptor.h>
#include <sys/socket.h> 
#include <fstream>

class FileSender{

    public:     
    /* Constructor */
    FileSender() = default;

    /* receives a socket and file as input and sends the file via socket */
    void send(fstream file, Socket socket);

    /* receives a socket as input to listen to it to receive a file. returns the file after the file receives compeletly */
    fstream receive(Socket socket);

    private:

    fstream file;
    Socket socket;

}



