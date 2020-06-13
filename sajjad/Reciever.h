#ifndef cplusclass1399_sajjad_RECIEVER_H
#define cplusclass1399_sajjad_RECIEVER_H

#include<string>
class Reciever {
private:
    int m_port;
    std::string m_output;
public:
    Reciever(int port, std::string input);
    void receiverData();
};


#endif
