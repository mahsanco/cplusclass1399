/// Class Network.
#include <string>

class Network
{
public:
    /// Constructor of class.
    Network();

    /// socket is started.
    int create_socket();
    
    /// The connection is established.
    int connect_socket();


    /// encrypted file is sent.
    int send_file(std::string filename /**< [in] Name of the file to be sent. */);

    /// encrypted file is received and saved.
    int receive_file();
};