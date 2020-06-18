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
#include <sys/socket.h>
#include "Compressor.h"
#include "Encryptor.h"

class client
{
public:

    const int port;  /**< client connect server on this port */

    Client();

    /**
    * Connect to socket
    *
    * @param {int} port - client connect server on this port
    *
    * @return connection status
    */
    bool connect_to_server(int port);

    /**
    * send file to server
    *
    * @return sending status
    */
    bool send_file(std::string path, std::vector<string>& addresses);
};
