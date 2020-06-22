/**
 * File Sender
 * Connect to the server.
 * Send a compressed and encrypted directory to server.
 */

#ifndef _FileSender_
#define _FileSender_ 

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Exceptions.hpp"


class FileSender
{
private :

    /// Keeps the name of recived file to sending
    std::string file_name;


public :

    /// Connect the client to the server
    FileSender();

    //~FileSender();

    /// Connect to the server with socket
    virtual void connect_to_server() = 0;
    
    /// Send directory name to the server
    virtual void send_name_to_server() = 0; 

    /// Send directory data to the server
    virtual void send_data_to_server(std::string data) = 0; 

    /// Get file name from user
    void get_file_name_input();

    /// Return file name 
    std::string return_file_name();

    /// Read recived file data
    void read_file_data();

    /// Send directory name
    void send_file_name(); 

    /// Send compressed and encrypted directory
    void send_file_data(); 

};

#endif