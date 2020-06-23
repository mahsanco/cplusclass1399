/***************************************************************************//**
 * Class FileReceiver Interface.
 ******************************************************************************/

#ifndef _FILERECEIVER_HPP_
#define _FILERECEIVER_HPP_

#include "Encryptor.hpp"
#include "Compressor.hpp"
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

class FileReceiver
{
private:
    int PORT; /**< The Port that server listens to. */
    Compressor* compressor; /**< Instance to decompress file. */
    Encryptor* encryptor;   /**< Instance to decrypt file. */

    /** Start server.
     *  If starting server was successful returns true else throw STARTING FAILED.
    */
    bool start() const;

    /** Save compressed and encrypted file on server.
     *  If saving on server was successful returns true else throw SAVING_FAILED.
    */
    bool save_on_server() const;

public:
    /** Get Compressor* and Encryptor* instances.
     *  Set PORT
    */ 
    FileReceiver(int port);

    /** Decryptes and decompresses file and save on server.
    *   Return value is file name.
    *   Multi thread reciever.
    */
    std::string receive() const noexcept;
};

#endif