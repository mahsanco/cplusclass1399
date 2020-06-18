
// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <fcntl.h>

#define PORT 8080
using namespace std;
int main(int argc, char const *argv[])
{
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    cout << "socket created" << endl;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
 
    int rec;
    char buf[1000]={' '};
    int dest;
    dest=creat("/home/hossein-hosseini/Desktop/mahsan/cplusclass1399/Assignment/source.txt",0777);

    int write_data;
    while(rec=recv(sock,buf,sizeof(buf),0)){
        write_data=write(dest,buf,rec);
    }
    close(sock);

    return 0;
}
