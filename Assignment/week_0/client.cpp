
// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#define PORT 8080



int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Client: Hello, I'm sending a file";
    char file_name[1000];
    FILE *file;
    char buffer[1024] = {0};
    char* ack[1000];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    printf("Enter the name of your file:\n");
    scanf("%s", file_name);

    file = fopen(file_name, "rb");

    send(sock , hello , strlen(hello) , 0 );

    while (!feof(file))
    {

       fread(buffer, sizeof(buffer), 1, file);
       send(sock , buffer , strlen(buffer) , 0 );

     }

    fclose(file);

    printf("file sent\n");

    valread = read( sock , ack, sizeof(ack));
    printf("%s\n",ack );

    return 0;
}

