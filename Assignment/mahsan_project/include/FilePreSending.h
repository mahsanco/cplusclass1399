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
     * Constructor with one argument: directory or file path
     ******************************************************************************/ 
    FilePreSending(const std::string &_file_path);
	
    /***************************************************************************//**
     * This member function reads a file, it has two arguments: file path and block size
     ******************************************************************************/
    void read_file(const std::string &_file_path, size_t block_size);


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
    std::string file_data;
    std::vector<std::string> blocks; ///< file is stored in blocks.
    size_t file_size; ///< file size in bytes.
    bool is_directory;

};


#endif
                                                                                                                                                                                                            
