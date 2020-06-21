//server

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <iostream>

#define PORT 8080

using namespace std;
int main(int argc, char const *argv[])
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    cout << "socket created" << endl;

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );


    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    cout << "socket accepted" << endl;
    //
    cout << "sending file..." << endl;
    int from;
    from= open("/home/ali/CLionProjects/pr1/data.txt",O_RDONLY);
    if(from<0){
        cout<<"Error opening file\n";
        return 0;
    }
    int n=1;
    int s;
    char buf[100]={' '};
    while((n=read(from,buf,sizeof(buf)))!=0){
        //s=send(fd2,buf,sizeof(buf),0);
        s=write(new_socket,buf,n);
        if(s<0){cout<<"error sending\n";return 0;}
    }
    cout << "sending file finished" << endl;
    close(server_fd);
    close(new_socket);
    shutdown(server_fd,0);
    shutdown(new_socket,0);
    cout << "connection closed" << endl;
    return 0;


}

