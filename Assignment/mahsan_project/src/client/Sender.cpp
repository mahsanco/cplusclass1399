#include "Sender.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <vector>

Sender::Sender(size_t port)
{
    m_socket = socket(AF_INET, SOCKET_STREAM, 0)

    reciever_info.sin_family = AF_INET;
    reciever_info.sin_port = htons(port);

    inet_pton(AF_INET, "127.0.0.1", &reciever_info.sin_addr);

    connect(m_socket, (struct sockaddr *)&reciever_info)

}


void Sender::send_size(size_t size)
{
    unit32_t value = htonl(size);
    send(m_socket, &value, sizeof(value), 0);

}



void Sender::send_file(std::vector<std::string> &blocks)
{
    for (int num_block = 0; num_block < blocks.size(); num_block++)
        send_block(blocks[num_block]); 
}



void Sender::send_block(const std::string &block)
{
    char *buffer = block.c_str();
    send(m_socket, buffer, sizeof(buffer), 0);


}





