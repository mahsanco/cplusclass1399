#include <compressor.h>
#include <encryptor.h>
#include <sys/socket.h> 
#include <fstream>

class FileSender{
    public:     
        FileSender() = default;

        //method that compress and encrypt a file and then send it via Socket
        void send(fstream file, Socket socket);

        //method that recieve a file from socket and then decompress and decrypt it and return it
        fstream receive(Socket socket);

}



