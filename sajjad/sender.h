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
    * @param input_path path of file 
    * @param port port to listen on
    *
    */
    void send(const string& input_path, int port);

    /**
    * recieve a file from socket
    *s
    * @param output_path path of file to write in it 
    * @param port port to listen on
    *
    */
    void receive(const string&   output_path, int port);

}



