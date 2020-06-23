#ifndef _COMPOSER_H_
#define _COMPOSER_H_


#include <string>
class compress
{

    public:
        /*
         * This library would decrease size of string.
         * To send to server.
         * I will use an okay method that i made!
         * the size would be the same or less.
         */

        /*
         * Compress a string
         * @param uncompressed string (this would be from Serialization)
         * @return compressed string
         */
        static std::string compressor(std::string) ;

        /*
         * Decompress a string
         * @param compressed string
         * @return uncompressed string
         */
        static std::string decompress(std::string) ;

        /*
         * Constructor
         */
        compress() ;

    private:

};

#endif
