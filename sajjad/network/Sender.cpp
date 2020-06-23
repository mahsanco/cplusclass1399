//
// Created by ali on 6/22/20.
//
#include "Sender.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <fcntl.h>

using namespace std;
Sender::Sender(int port, const std::string& input) const noexcept{
    m_input = port;
    m_input = input;
}


bool Sender:: send_data() const noexcept{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        return false;
    }
    cout << "socket created" << endl;

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        return false;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( m_port );


    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        return false;
    }
    if (listen(server_fd, 3) < 0)
    {
        return false;
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        return false;
    }
    // socket accepted

    // sending file...
    int from;
    from= open(m_input, O_RDONLY);
    if(from<0){
        return false;
    }
    int n=1;
    int s;
    char buf[100]={' '};
    while((n=read(from,buf,sizeof(buf)))!=0){
        s=write(new_socket,buf,n);
        if(s<0){
            return false;
        }
    }

    close(server_fd);
    close(new_socket);
    shutdown(server_fd,0);
    shutdown(new_socket,0);

    return true;
}
