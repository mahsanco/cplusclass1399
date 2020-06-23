/***************************************************************************//**
 * Class Compressor Interface.
 ******************************************************************************/
#ifndef _COMPRESSOR_HPP_
#define _COMPRESSOR_HPP_

#include <string>

class Compressor
{
private:
    Compressor();

    static Compressor* instance; /**< Instance of Compressor to avoid making multiple objects. */
    
public:
    static Compressor* get_instance() const noexcept;
    
    /** Compress a specific file and return the compressed file name.
     *  @param {string} filename - Name of the file.
    */
    static std::string compress(std::string filename) const;
    
    /** Decompress a specific file and return the decompressed file name.
     *  @param {string} filename - Name of the file.
    */
    static std::string decompress(std::string filename) const;
};

#endif