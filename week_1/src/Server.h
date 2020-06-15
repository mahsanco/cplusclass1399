/***************************************************************************//**
 * Class server
 *
 * Start socket server and save file from client
 * 
 *
 * Auther: mahdigh
 *
 * Cntact: mahdigh113@gmail.com
 *
 * Created on: june 11 2020
 *
 ******************************************************************************/

#ifndef Server_H
#define Server_H

#include <iostream>
#include <string>
#include "Compressor.h"
#include "Encryptor.h"

class server
{
public:

    Server();
    
    /**
    * Create socket
    *
    * @param {int} port - create socket server on that port
    *
    * @return Server status
    */
    bool start_server(int port);
    
    /**
    * Receive and save file in a server directory
    *
    * @return file saving status
    */
    bool receive_file();
};
