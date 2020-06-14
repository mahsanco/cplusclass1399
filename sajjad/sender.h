#include <compressor.h>
#include <encryptor.h>
#include <sys/socket.h> 
#include <fstream>

class FileSender{

    public:     
    ///Constructor
    FileSender() = default;

    /**
    * send a file via socket
    *
    * @param param1 file to send
    * @param param2 socket
    *
    * @return void
    */
    void send(fstream file, Socket socket);

    /**
    * recieve a file from socket
    *
    * @param param1 socket
    *
    * @return file
    */
    fstream receive(Socket socket);

}



