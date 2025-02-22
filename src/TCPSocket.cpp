
#include "TCPSocket.hpp"
#include <cstring>
#include <iostream>
#include <netdb.h>
#include <unistd.h>

namespace Networking {

    TCPSocket::TCPSocket() {

        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_CANONNAME;
        hints.ai_protocol = 0;
    }

    void TCPSocket::connect(std::string &host, const char* port) {
        
        int s;
        struct addrinfo *result, *rp;

        s = getaddrinfo(host.c_str(), port, &hints, &result);
        if (s != 0) {
            std::cerr << "getaddrinfo: " << gai_strerror(s) << std::endl;
            exit(EXIT_FAILURE);
        }

        for (rp = result; rp != NULL; rp = rp->ai_next) {
            m_sfd = socket(rp->ai_family, rp->ai_socktype,
                         rp->ai_protocol);

            if (m_sfd == -1) {
                continue;
            }

            if (::connect(m_sfd, rp->ai_addr, rp->ai_addrlen) != -1) {
                std::cout << "Connected\n";
                break;       /* Success */
            }

        }

        freeaddrinfo(result);

        if (rp == NULL) { /* No address succeeded */
            std::cerr << "Could not connect\n";
            close(m_sfd);
            exit(EXIT_FAILURE);
        }

    }

    void TCPSocket::send(std::string& httpRequest) {
        // Send HTTP request
        if (::send(m_sfd, httpRequest.c_str(), httpRequest.size() + 1, 0) == -1) {
            perror("send");
            close(m_sfd);
            exit(EXIT_FAILURE);
        }

        // Receive and print response
        ssize_t bytesReceived;
        unsigned char bufferArray[IN_BUFFER_INITIAL_CAPACITY];
        buf.reserve(IN_BUFFER_INITIAL_CAPACITY); // Reserve to avoid resizing vector over and over again
        
        while ((bytesReceived = recv(m_sfd, bufferArray, IN_BUFFER_INITIAL_CAPACITY - 1, 0)) > 0) {

            buf.insert(buf.end(), bufferArray, bufferArray + bytesReceived);
            std::cout << "Bytes received\n";
            
        }
        buf.emplace_back('\0');
        // std::cout << buf.data() << "\n";

        if (bytesReceived == -1) {
            perror("recv");
        }

    }

    const std::vector<unsigned char>& TCPSocket::getResponse() const {
        return buf;
    }



}