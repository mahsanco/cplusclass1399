#ifndef FILEPRESENDING_H
#define FILEPRESENDING_H

#include <string>
#include <vector>


/***************************************************************************//**
 * This class does some preparation on the file,
 * reading, compressing and splitting file
 ******************************************************************************/

class FilePreSending
{


public:

    /***************************************************************************//**
     * Constructor with two arguments: directory address of a file and file name
     ******************************************************************************/ 
    FilePreSending(const std::string &_file_path, const std::string &_file_name);

    /***************************************************************************//**
     * This member function reads a file, it has two arguments: address of the file 
     * and size of blocks in bytes. It reades the file block by block, and stores them
     * in blocks member field.
     ******************************************************************************/
    void read_file(const std::string &path, size_t block_size);


    /***************************************************************************//**
     * This member function Compresses a file and saves it in the same address as
     * the main file.
     *******************************************************************************/
    void compress_file();
	
   
    /***************************************************************************//**
     * This member function returns file_name member field 
     ******************************************************************************/
    std::string get_file_name();    

    
private:

    std::string file_path; ///< address of file or directory. 
    std::string file_name; ///< name of file or directory.
    std::string file_type;
    std::vector<std::string>* blocks; ///< file is stored in blocks.
    size_t file_size; ///< file size in bytes.
    bool is_directory;

};


#endif
                                                                                                                                                                                                            
