/**
 * File Reciver
 * Connect to the server.
 * Recive a compressed and encrypted directory from server.
 */

#ifndef _FileReciver_
#define _FileReciver_ 

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Exceptions.hpp"


class FileReciver
{
private :

    /// Keeps the name of recived file
    std::string file_name;

    /// Keeps the data of recived file
    std::vector <std::string> file_data;


public :

    /// Make server
    FileReciver();

    //~FileReciver();

    /// Return file name
    std::string return_file_name();

    /// Prepare the server to recive and save the directory
    virtual void make_ready_server() = 0; 

    /// Save the downloaded directory
    void save_on_server(); 

    /// Get name of file from socket
    virtual std::string get_name_from_socket() = 0;

    /// Get data of file from socket
    virtual std::vector <std::string> get_data_from_socket() = 0;

    /// Recive the compresed and encrypted directory
    void recive_file_name();

    /// Recive the compresed and encrypted directory
    void recive_file_data();

};

#endif