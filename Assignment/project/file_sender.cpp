#include "file_sender.h"

FileSender::FileSender(int port_number) {
  sock = 0;
  port = port_number;
  for (int index = 0; index < BUFFER_SIZE; index++)
    buffer[index] = 0;
    if (!is_socket_created())
      throw SocketCreationError();
    if (!has_address_converted_text_to_binary())
      throw InvalidAddress();
    if (!is_connect_server())
      throw ConnectionFailed();
}

bool FileSender::is_socket_created() {
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		return false;
	} else {
    server_address.sin_family = AF_INET;
  	server_address.sin_port = htons(port);
    return true;
  }
}

bool FileSender::has_address_converted_text_to_binary() {
  if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
		return false;
  } else return true;
}

bool FileSender::is_connect_server() {
  if (connect(sock,(struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
		return false;
	} else {
		std::cout << "Connection Successful" << std::endl;
    return true;
	}
}

void FileSender::send_filename(std::string filename) {
  send(sock, filename.c_str(), filename.size(), 0);
}

void FileSender::send_file(std::string client_filename) {
  send_filename(client_filename);
	FILE* file_ptr = fopen(client_filename.c_str(), "rb");
	while ((valread = fread(buffer, 1, sizeof(buffer), file_ptr)))
		send(sock, buffer, valread, 0);
	fclose(file_ptr);
	std::cout << "The " << client_filename << " was sent successfully " << std::endl;
}
