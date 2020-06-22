#include "Reciever.h"
#include "FilePostSending.h"
#include <string>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>

Reciever::Reciever(size_t _port)
{
    port = _port
    reciever_info.sin_family = AF_INET;
    reciever_info.sin_addr.s_addr = INADDR_ANY;
    reciever_info.sin_port = htons(port);

    master_socket = socket(AF_INET, SOCK_STREAM, 0);
    bind(master_socket, (struct sockaddr *)&reciever_info, sizeof(reciever_info));


}



void Reciever::handle_sender(int socket)
{
    hello = "hello";
    send(socket, hello, hello.size(), 0);

}



void Reciever::run()
{
    while(true)
    {
        listen(master_socket, max_senders);
	int new_socket = accept(master_socket, (struct sockaddr *)&reciever_info,
			(socklen_t)&info_len);

	handle_sender();
	senders.push_back(new_socket);

    }

}
