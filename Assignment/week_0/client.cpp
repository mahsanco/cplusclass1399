#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define UNSUCCESSFUL -1

int main(int argc, char const *argv[]) {
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char buffer[1024] = {0};
	std::string filename = argv[2];
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		std::cout << "Socket creation error" << std::endl;
		return UNSUCCESSFUL;
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi(argv[1]));

	// Convert IPv4 and IPv6 addresses from text to binary form
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
		std::cout << "Invalid address / Address not supported" << std::endl;
		return UNSUCCESSFUL;
	}
	if (connect(sock,(struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		std::cout << "Connection Failed" << std::endl;
		return UNSUCCESSFUL;
	} else {
		std::cout << "Connection Successful" << std::endl;
	}

	// Sending filename
	send(sock , filename.c_str(), filename.size(), 0);

	// Sending file
	FILE* file_ptr = fopen(filename.c_str(), "rb");
	while ((valread = fread(buffer, 1, sizeof(buffer), file_ptr)))
		send(sock, buffer, valread, 0);
	fclose(file_ptr);
	std::cout << "The " << filename << " was sent successfully " << std::endl;
	return 0;
}

