/**
 * \class Receiver
 *
 * \ingroup sajjad
 *
 * \brief receives a file by socket
 *
 * this class is for receiving a file that has been
 * sent by Sender class
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
#ifndef cplusclass1399_sajjad_RECIEVER_H
#define cplusclass1399_sajjad_RECIEVER_H

#include<string>

class Receiver {
private:
    int m_port; ///< port of receiving data
    std::string m_output; ///< writes file to this path
public:
    /**
     * constructor
     * @param port port of receiving data
     * @param input path of input file
     */
    Receiver(int port, std::string input);

    /**
     * \brief starts receiving data
     * receives data from port m_port and writes it to path m_output
     * \return finished successfully
    */
    bool receiver_data();
};

#endif
