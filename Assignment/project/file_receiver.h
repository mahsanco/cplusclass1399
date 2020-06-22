#ifndef FILERECEIVERT_H
#define FILERECEIVERT_H

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define  BUFFER_SIZE 1024

class FileReceiver {
private:
  int server_fd;
  int new_socket;
  int valread;
  int port;
  struct sockaddr_in address;
  int opt;
	int addrlen;
	char buffer[1024];

  void socket_creation(); // Creating socket file descriptor
  void force_attach_socket_to_port(); // Forcefully attaching socket to the port
  void server_listen();
  void server_accept();
  std::string receive_filename(); //Receiving filename
  std::string change_filename(std::string, std::string);  // change filename

public:
  FileReceiver (int);
  void receive_file(std::string); // Receiving file
};

#endif
