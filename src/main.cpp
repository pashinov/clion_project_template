#include <iostream>
#include <functional>

#include "handler.hpp"
#include "swap.hpp"

int main(int argc, char* argv[])
{
    std::string str1 = "World!!!"; std::string str2 = "Hello, ";

    std::function<void(std::string&, std::string&)> callback = std::bind(
            &cpp_project_template::swap<std::string>,
            std::placeholders::_1,
            std::placeholders::_2);

    cpp_project_template::handler<std::string>(str1, str2, callback);

    std::cout << str1 << str2 << std::endl;

    return 0;
}
