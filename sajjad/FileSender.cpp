#include "FileSender.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
using namespace std;

void FileSender::send(const char *input_path, int port) const noexcept {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if (!(server_fd = socket(AF_INET, SOCK_STREAM, 0)))
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    else{
        cout << "socket created" << endl;
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt done ");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);


    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("failed in binding");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("failed in listening");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("new socket accepted");
        exit(EXIT_FAILURE);
    }
    cout << "Socket creation done, sending data started";
    int file;
    file = open((const char *) input_path, O_RDONLY);
    if(file < 0)
    {
        cout<<"opening file failed. ";
    }
    int read_data = 1, write_data;
    char buffer[1000000]={' '};
    while((read_data = read(file, buffer, sizeof(buffer)))!=0){
        write_data = write(new_socket, buffer, read_data);
        if(write_data < 0)
        {
            cout << "sending data failed. ";
        }
    }
    cout << "sending data finished";
    close(server_fd);
    close(new_socket);
    shutdown(server_fd,0);
    shutdown(new_socket,0);
}

void FileSender::receive(const char *output_path, int port) const noexcept {
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cout << "socket creation failed. ";
    }
    else
    {
        cout << "socket created. ";
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        cout << "connection esteblished. ";
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        cout << "connection refused. ";
    }
    cout << "socket created, receiving data started. ";

    int file;
    file = creat((const char *) output_path, 0777);
    if(file < 0){
        cout << "creating file failed. ";
    }
    int receive;
    char buffer[1000000]={' '};
    receive = recv(sock, buffer, sizeof(buffer), 0);
    while(receive)
    {
        if(receive < 0){
            cout << "receiving fail . ";
        }
        receive = recv(sock, buffer, sizeof(buffer), 0);
    }
    cout << "writing into file done. ";

    close(sock);
    shutdown(sock,0);
}
