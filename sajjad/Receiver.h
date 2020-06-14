#ifndef cplusclass1399_sajjad_RECIEVER_H
#define cplusclass1399_sajjad_RECIEVER_H

#include<string>

class Receiver {
private:
    int m_port;
    std::string m_output;
public:
    Receiver(int port, std::string input);

    void receiver_data(); // receives data from port m_port and writes it to path m_output
};


#endif
