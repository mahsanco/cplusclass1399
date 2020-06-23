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
     * Constructor with three arguments: name and size of recieved file and recieved blocks
     ******************************************************************************/
    FilePostSending(const std::string &_file_name);


    /***************************************************************************//**
     * This member function writes a file, it two arguments: address of the file and
     * a vector of strings (blocks of data)
     ******************************************************************************/
    void write_file(const std::string &file_path, std::vector<std::string> &blocks); 



private:
 
    std::string file_name; ///< name of file.

};


#endif
