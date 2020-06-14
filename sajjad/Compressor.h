/**
 * \class Compressor
 *
 * \ingroup sajjad
 *
 * \brief compresses a file
 *
 * this class is for compressing a file and
 * reducing its size
 *
 * \author (last to touch it) $Author: ali $
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2020/05/14 22:16:20 $
 *
 * Contact: alipourghasemi78@gmail.com
 *
 * Created on: sun jun 14 22:16:37 2020
 *
 *
 */
#ifndef cplusclass1399_sajjad_COMPRESSOR_H
#define cplusclass1399_sajjad_COMPRESSOR_H

#include<string>

class Compressor {
private:
    std::string m_input; ///< keeps path of input file
    std::string m_output; ///< keeps path of output file
public:
    /**
     * constructor
     * @param input path of input file
     * @param output path of output file
     */
    Compressor(std::string input, std::string output);

    /**
     * \brief compress m_input file
     * reads file from path m_input and compresses it to path m_output
     */
    void compress();
};


#endif
