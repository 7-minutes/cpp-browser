
#define MESSAGE_BUFFER_INITIAL_CAPACITY 8192

namespace Networking {

class TCPSocket {

public:
    static TCPSocket& getInstance();
    
    TCPSocket(const TCPSocket&) = delete;
    TCPSocket& operator=(const TCPSocket&) = delete;
    

private:
    TCPSocket();

};

}