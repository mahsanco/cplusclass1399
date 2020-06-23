#include "Server.hpp"

Server::Server()
{
	decrypt = new Decrypt();

	try
	{	
		make_ready_server();
	}

	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void Server::make_ready_server() 
{
	int _setsockopt, _bind, _listen, opt = 1; 
	int addrlen = sizeof(serv_addr); 
	
	sock_fd = socket(AF_INET, SOCK_STREAM, IP_PROTOCOL);

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_addr.s_addr = INADDR_ANY; 
	serv_addr.sin_port = htons(PORT); 
	
	_setsockopt = setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
	
	_bind = bind(sock_fd, (struct sockaddr *)&serv_addr, addrlen);

	_listen = listen(sock_fd, 3);

	if(sock_fd == 0)
    {
        throw SocketFailed();
    }
	else if(_setsockopt == 1)
    {
        throw SetSockOptFailed();
    }
	else if(_bind < 0)
    {
        throw BindFailed();
    }
	else if(_listen < 0)
    {
        throw ListenFailed();
    }
}

std::string Server::get_name_from_socket()
{	
	std::string file_name;

	char buffer[1024] = {0};
	int addrlen = sizeof(serv_addr); 

	new_socket = accept(sock_fd, (struct sockaddr *)&serv_addr, (socklen_t*)&addrlen);
	read(new_socket, buffer, 1024);

	file_name = (std::string)buffer; 

	return file_name;
}

std::vector <std::string> Server::get_data_from_socket()
{	
	std::ofstream outfile(return_file_name(), std::ios::binary);
	char buffer[1024];
	int addrlen = sizeof(serv_addr); 

	while (read(new_socket, buffer, 1024))
	{	
		std::string data = decrypt -> decrypt_file_input(buffer);
		//std::string data = (std::string)buffer;
		file_data.push_back(data);	
		outfile << file_data[file_data.size()-1] << std::endl;
	}
	return file_data;
}
