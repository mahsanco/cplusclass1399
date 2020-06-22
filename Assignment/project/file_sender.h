#ifndef FILESENDER_H
#define FILESENDER_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define  UNSUCCESSFUL -1
#define  BUFFER_SIZE 1024

class FileSender {
private:
  int sock;
  int valread;
  struct sockaddr_in server_address;
  int port;
  char buffer[1024];

  bool socket_creation(); // Creating socket
  bool convert_address_text_to_binary();  // Convert IPv4 and IPv6 addresses from text to binary form
  bool connect_server();
  void send_filename(std::string);  // send filename

public:
  FileSender (int);
  void send_file(std::string);
};

#endif
