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
#include <bits/stdc++.h>
#include <unordered_map>

class Compressor {
private:
    std::string m_input; ///< keeps path of input file
    std::string m_output; ///< keeps path of output file

    static void putVecToFile(const std::string &m_output, const std::vector<int> &output_code) ;

    static std::vector<unsigned char> intToBytes(int paramInt) ;

    static std::vector<int> putFileToVec(const std::string &aa) ;

public:
    /**
     * constructor
     * @param input path of input file
     * @param output path of output file
     */
    Compressor(std::string& input, std::string& output);

    /**
     * \brief compress m_input file
     * reads file from path m_input and compresses it to path m_output
     * \return finished successfully
     */
    bool compress() noexcept;

    /**
     * \brief decompress m_input file
     * reads file from path m_input and decompresses it to path m_output
     * \return finished successfully
 */
    bool decompress() noexcept;
};


#endif
