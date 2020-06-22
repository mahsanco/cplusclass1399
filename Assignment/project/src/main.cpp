#include "FileSender.hpp"
#include "FileReciver.hpp"
#include "Client.hpp"
#include "Server.hpp"

int main()
{      
    FileReciver* file_reciver = new Server();  
    FileSender* file_sender = new Client();  

    file_sender -> send_file_name(); 
    file_reciver -> recive_file_name();

    file_sender -> send_file_data(); 
    file_reciver -> recive_file_data();
}    