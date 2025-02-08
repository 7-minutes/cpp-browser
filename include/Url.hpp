
#pragma once

#include <string>

namespace URL {

class Url {
private:
    std::string m_url;
    std::string m_scheme;
    std::string m_host;
    std::string m_path;

public:
    Url(std::string &url);
    void print();
};

} // namespace URL