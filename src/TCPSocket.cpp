
#include "TCPSocket.hpp"

namespace Networking {

TCPSocket::TCPSocket() {};

TCPSocket& TCPSocket::getInstance() {
    static Networking::TCPSocket instance;
    return instance;
}

}