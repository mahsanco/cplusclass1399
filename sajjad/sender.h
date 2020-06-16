#include <compressor.h>
#include <encryptor.h>
#include <sys/socket.h> 
#include <string>

class FileSender{

    public:     
    ///Constructor
    FileSender() = default;

    /**
    * send a file via socket
    *
    * @param param1 path of file 
    * @param param2 socket
    *
    * @return void
    */
    void send(string inputPath, Socket socket);

    /**
    * recieve a file from socket
    *
    * @param param1 path of file to write in it 
    * @param param2 socket
    *
    * @return void
    */
    void receive(string outputPath, Socket socket);

}



