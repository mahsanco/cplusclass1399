/**
 * \class Encryption
 *
 * \ingroup sajjad
 *
 * \brief encrypts a file
 *
 * this class is for encrypting a file that has been
 * compressed by Compressor class
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
 */
#ifndef cplusclass1399_sajjad_ENCRYPTION_H
#define cplusclass1399_sajjad_ENCRYPTION_H

#include<string>

class Encryption {
private:
    std::string m_input; ///< keeps path of input file
    std::string m_output; ///< keeps path of output file
public:
    Encryption(std::string input, std::string output);

    /**
     * \brief encrypts m_input file
     * reads file from path m_input and encrypt it to path m_output
     */
    void encrypt();
};

#endif
