/**
 * \class Sender
 *
 * \ingroup sajjad
 *
 * \brief sends a file by socket
 *
 * this class is for sending a file that has been
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
#ifndef cplusclass1399_sajjad_SENDER_H
#define cplusclass1399_sajjad_SENDER_H

#include<string>

class Sender {
private:
    int m_port; ///< port of sending data
    std::string m_input; ///< reads file from this path
public:
    /**
     * constructor
     * @param port port of sending data
     * @param input path of input file
     */
    Sender(int port, std::string input);

    /**
     * \brief starts sending data
     * reads data from m_input and sends it to port m_port
    */
    void send_data();
};


#endif
