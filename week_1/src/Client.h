/***************************************************************************//**
 * Class client
 *
 * Connect client to socket server and send file to server
 * 
 *
 * Auther: mahdigh
 *
 * Cntact: mahdigh113@gmail.com
 *
 * Created on: june 11 2020
 *
 ******************************************************************************/

#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "Compressor.h"
#include "Encryptor.h"

class client
{
public:

    Client();
    
    /**
    * Connect to socket
    *
    * @param {int} port - connect socket client on that port
    *
    * @return connection status
    */
    bool connect_to_server(int port);
    
    /**
    * send file to server with socket
    *
    * @return sending status
    */
    bool send_file();
};
