
#include "Url.hpp"
#include <cstdlib>
#include <string>
#include <iostream>

int main() {

    std::string link = "http://example.org/";

    URL::Url url(link);
    url.request();

    std::cout << url.request().data();

    return EXIT_SUCCESS;
}
