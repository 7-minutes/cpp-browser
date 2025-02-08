
#include "Url.hpp"
#include "TCPSocket.hpp"

int main() {

    std::string link = "http://example.org/index/yomama.html";

    URL::Url *url = new URL::Url(link);

    url->print();

    auto &socket = Networking::TCPSocket::getInstance();

    return 0;
}
