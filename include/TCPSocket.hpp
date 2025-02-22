
#pragma once

#include <netdb.h>
#include <string>
#include <vector>
#define IN_BUFFER_INITIAL_CAPACITY 2048

namespace Networking {

class TCPSocket {

public:

    TCPSocket();

    void connect(std::string &host, const char* port);
    void send(std::string& httpRequest);
    const std::vector<unsigned char>& getResponse() const;

private:

    int m_sfd;
    struct addrinfo hints;
    std::vector<unsigned char> buf;

};

}