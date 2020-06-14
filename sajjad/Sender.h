#ifndef cplusclass1399_sajjad_SENDER_H
#define cplusclass1399_sajjad_SENDER_H

#include<string>

class Sender {
private:
    int m_port;
    std::string m_input;
public:
    Sender(int port, std::string input);

    void send_data(); // reads data from m_input and sends it to port m_port
};


#endif
