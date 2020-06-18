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
    * @param {string} path - main directory.
    * @param {string} addresses - files or directories' Addresses.
    *
    * @return Compressed file name
    */
    bool compress(std::string path, std::vector<string>& addresses);

    /**
    * Decompress file
    *
    * @param {string} dirname - directory file name.
    *
    * @return Deompressed directory name
    */
    bool decompress(std::string filename );
};
