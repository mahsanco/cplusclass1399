#include "data_receiver.h"
#include <sys/types.h> 
#include <sys/socket.h> 
#include <vector>
#include <string.h>
#include <unistd.h>   //close  
#include <arpa/inet.h>    //close  
#include <netinet/in.h> 
#include <iostream>
/*
 *define static members of class
 */
int data_receiver::master_socket,data_receiver::addrlen ;
struct sockaddr_in data_receiver::address; 
bool data_receiver::end ;
std::stack<std::pair<std::string,std::string> > data_receiver::data_received ;
std::thread data_receiver::demon_thread ;
std::mutex data_receiver::stack_use_safe ;

//based on geeksforgeeks
data_receiver::data_receiver(int port)
{
    end=false ;
    master_socket = socket(AF_INET , SOCK_STREAM , 0) ;
    if(master_socket==0)
    {
        //exception 
    } 
    int opt=true ;
    if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,  sizeof(opt)) < 0 ) 
    {
        //exception 
    }
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( port ); 

    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        //exception 		
    } 
    if (listen(master_socket, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    //accept the incoming connection 
    addrlen = sizeof(address); 

    demon_thread=std::thread(demon) ;

}

data_receiver::~data_receiver()
{
    demon_thread.join() ;
}
void data_receiver::demon()
{
    std::vector<std::thread> all_runnings ;
    while(!end)
    {
        int new_socket=accept(master_socket,(struct sockaddr *)& address,(socklen_t*) &addrlen) ;
        if(new_socket<0)
        {
            //exception 
        }
        else
            all_runnings.push_back(std::thread(receiver,new_socket)) ;
    }
    for(auto &i:all_runnings)
        i.join() ;
}

void data_receiver::receiver(int socket)
{
    std::string sz_str(21,0) ;

    char buffer[1025] ;
     
    int valread ;
    valread = read( socket , &sz_str[0], 20) ;
    if(valread<0)
    {
        //exception 
        close(socket) ;
        return ;
    }
    int sz=std::stoi(sz_str) ;
    std::string input(sz+1,0) ;
    valread = read( socket , &input[0], sz) ;
    if(valread<0)
    {
        //exception 
        close(socket) ;
        return ;
    }
    std::string socket_info="data received from socket number:"+std::to_string(socket) + 
        " and size is:"+sz_str+"\n" ;
    stack_use_safe.lock() ;
    data_received.push(std::make_pair(socket_info,input) ) ;
    stack_use_safe.unlock() ;
    
    close(socket) ;
    /*
    while(true) 
        if ((valread = read( socket , buffer, 1024)) == 0) 
        { 
            //Close the socket and mark as 0 in list for reuse 
            close( socket ); 
            break ; 
        } 

    //Echo back the message that came in 
        else
        { 
            //set the string terminating NULL byte on the end 
            //of the data read 
            std::cout<<buffer<<" " <<socket<<std::endl ;
            buffer[valread] = '\0'; 
            if(std::string(buffer)=="close")
            {
                close(socket) ;
                break ;
            }
            send(socket , buffer , strlen(buffer) , 0 );
            
        }
    //return "hey"; 
    */
}