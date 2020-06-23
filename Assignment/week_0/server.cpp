#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(atoi(argv[1]));

	// Forcefully attaching socket to the port
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
	 (socklen_t*)&addrlen)) < 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}

	//Receiving filename
	read(new_socket, buffer, 1024);

	// Find file extention
 	std::string filename = buffer;
	std::size_t new_indx = filename.find('.');
	std::size_t previous_indx = std::string::npos;
	while (new_indx != previous_indx)
		previous_indx = new_indx;
		new_indx = filename.find('.', previous_indx);
		filename = filename.substr(new_indx, filename.size());
 	filename = argv[2] + filename + '\0';

	// Receiving file
 	FILE* file_ptr = fopen(filename.c_str(), "wb");
 	while ((valread = read(new_socket, buffer, 1024)))
 		fwrite (buffer, 1, valread, file_ptr);
 	fclose (file_ptr);
	std::cout << "The " << filename << " was received successfully" << std::endl;
 	return 0;
}

