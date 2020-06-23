//
// Created by ali on 6/22/20.
//
#include "Receiver.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <fcntl.h>
using namespace std;

Receiver::Receiver(int port, const std::string& input){
    m_port = port;
    m_output = input
}


Receiver::bool receiver_data() const noexcept{
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return false;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        return false;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        return false;
    }
    //

    int rec;
    char buf[100]={' '};
    int to;
    to=creat(m_output,0777);
    if(to<0){
        return false;
    }

    int w;
    while(rec=recv(sock,buf,sizeof(buf),0)){
        if(rec<0){
            return false;
        }
        w=write(to,buf,rec);
    }

    close(sock);
    shutdown(sock,0);


    return true;
}


