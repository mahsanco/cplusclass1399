/***************************************************************************//**
 * Class compressor
 *
 * This class compress file and directories for encrypting
 * and decompress file to files and directories
 *
 * Auther: mahdigh
 *
 * Cntact: mahdigh113@gmail.com
 *
 * Created on: june 11 2020
 *
 ******************************************************************************/

#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <string>

class Compressor
{
public:

    Compressor();
    
    /**
    * Compress files and directories
    *
    * @param {string} addresses - Addresses of the files or directories.
    *
    * @return Compressed file name
    */
    std::string compress(std::vector<string> &addresses );
    
    /**
    * Decompress file
    *
    * @param {string} dirname - directory file name.
    *
    * @return Deompressed directory name
    */
    std::string decompress(std::string dirname );
};
