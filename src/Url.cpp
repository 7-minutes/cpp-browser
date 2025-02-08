
#include "Url.hpp"
#include <iostream>
#include <string>

namespace URL {

Url::Url(std::string &url) {

    std::size_t separator = url.find("://");
    if (separator != std::string::npos) {
        std::cout << "Found separator \n";
        m_scheme = url.substr(0, separator);
        m_url = url.substr(m_scheme.size() + 3, url.size() - 1);
        url = url.substr(separator + 3);
    }

    // TODO: error if no separator

    size_t slash_pos = url.find("/");
    if (slash_pos == std::string::npos) {
        std::cout << "No trailing slash (or any slashes...)\n";
        url = url.append("/");
        slash_pos = url.size() - 1;
    }

    m_host = url.substr(0, slash_pos);
    m_path = url.substr(slash_pos);
};

void Url::print() {
    std::cout << "url: " << m_url << "\n";
    std::cout << "scheme: " << m_scheme << "\n";
    std::cout << "host: " << m_host << "\n";
    std::cout << "path: " << m_path << "\n";
}

}