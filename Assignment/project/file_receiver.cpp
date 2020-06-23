#include "file_receiver.h"

FileReceiver::FileReceiver (int port_number) {
  int opt = 1;
	int addrlen = sizeof(address);
  for (int index = 0; index < BUFFER_SIZE; index++)
    buffer[index] = 0;
  port = port_number;
  socket_creation();
  force_attach_socket_to_port();
  server_listen();
  server_accept();
}

void FileReceiver::socket_creation() {
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		throw SocketCreationError();
	} else {
    address.sin_family = AF_INET;
  	address.sin_addr.s_addr = INADDR_ANY;
  	address.sin_port = htons(port);
  }
}

void FileReceiver::force_attach_socket_to_port() {
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		throw BindFailed();
	}
}

void FileReceiver::server_listen() {
  if (listen(server_fd, 3) < 0) {
		throw ListenFailed();
	}
}

void FileReceiver::server_accept () {
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
	 (socklen_t*)&addrlen)) < 0) {
		throw AcceptFailed();
	}
}

std::string FileReceiver::receive_filename() {
  read(new_socket, buffer, BUFFER_SIZE);
  return buffer;
}

std::string FileReceiver::change_filename(std::string filename, std::string new_name) {
	std::size_t new_indx = filename.find('.');
	std::size_t previous_indx = std::string::npos;
	while (new_indx != previous_indx)
		previous_indx = new_indx;
		new_indx = filename.find('.', previous_indx);
		filename = filename.substr(new_indx, filename.size());
 	filename = new_name + filename + '\0';
  return filename;
}

void FileReceiver::receive_file(std::string new_name) {
  std::string filename = receive_filename();
  new_name = change_filename(filename, new_name);
  FILE* file_ptr = fopen(new_name.c_str(), "wb");
  while ((valread = read(new_socket, buffer, BUFFER_SIZE)))
    fwrite (buffer, 1, valread, file_ptr);
  fclose (file_ptr);
  std::cout << "The " << new_name << " was received successfully" << std::endl;
}
