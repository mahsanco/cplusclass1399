#include "Client.hpp"

Client::Client()
{
	try
	{			
		connect_to_server();		
	}

	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void Client::connect_to_server() 
{
	int _inet_pton, _connect;

	sock_fd = socket(AF_INET, SOCK_STREAM, IP_PROTOCOL);

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT);
	
	_inet_pton = inet_pton(AF_INET, IP_ADDRESS, &serv_addr.sin_addr);

	_connect = connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	if(sock_fd < 0)
    {
        throw SocketFailed();
    }
	else if(_inet_pton <= 0)
    {
        throw AddressFailed();
    }
	else if(_connect < 0)
    {
        throw ConnectionFailed();
    }
}

void Client::send_name_to_server()
{
	const char* file_name = return_file_name().data();
	send(sock_fd, file_name, strlen(file_name), 0);
}

void Client::send_data_to_server(std::string data)
{
	send(sock_fd, data.data(), data.size(), 0);
	send(sock_fd, "\n", 1, 0);
}