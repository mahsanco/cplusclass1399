#ifndef FILEPOSTSENDING_H
#define FILEPOSTSENDING_H

#include <string>
#include <vector>


/***************************************************************************//**
 * This class writes the file after it has been sended
 ******************************************************************************/

class FilePostSending
{


public:

    /***************************************************************************//**
     * Constructor with three arguments: name and type of recieved file and recieved blocks
     ******************************************************************************/
    FilePostSending(const std::string &_file_name, const std::string &_file_type, std::vector<std::string> &_blocks);

    /***************************************************************************//**
     * This member function writes a file, it has one argument: address of the file.
     ******************************************************************************/
    void write_file(const std::string &address); 

    /***************************************************************************//**
     * This member function decompresses a compressed file and saves it,
     * it has one argument: address of compressed file
     ******************************************************************************/
    void decompress_file(const std::string &address);



private:
 
    std::string file_name; ///< name of file.
    std::string file_type; ///< type of file.
    std::vector<std::string>* blocks; ///< the whole file in blocks.
};


#endif
