
#include "Url.hpp"
#include "TCPSocket.hpp"
#include <cassert>
#include <iostream>
#include <string>

namespace URL {

Url::Url(std::string &url) {

    std::size_t separator = url.find("://");
    if (separator != std::string::npos) {
        m_scheme = url.substr(0, separator);
        m_url = url.substr(m_scheme.size() + 3, url.size() - 1);
        url = url.substr(separator + 3);
        assert(m_scheme == "http");
    }

    // TODO: error if no separator

    size_t slashPos = url.find("/");
    if (slashPos == std::string::npos) {
        std::cout << "No trailing slash (or any slashes...)\n";
        url = url.append("/");
        slashPos = url.size() - 1;
    }

    m_host = url.substr(0, slashPos);
    m_path = url.substr(slashPos);
};

void Url::print() {
    std::cout << "url: " << m_url << "\n";
    std::cout << "scheme: " << m_scheme << "\n";
    std::cout << "host: " << m_host << "\n";
    std::cout << "path: " << m_path << "\n";
}

const std::vector<unsigned char>& Url::request() {

    Networking::TCPSocket socket;
    socket.connect(m_host, "80"); // FIXME

    std::string httpRequest = "GET " + m_path + " HTTP/1.0\r\n"
        + "Host: " + m_host + "\r\n"
        + "\r\n";

    socket.send(httpRequest);

    auto& response = socket.getResponse();
    return response;
    // response = s.makefile("r", encoding="utf8", newline="\r\n")
}

}