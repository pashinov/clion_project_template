#include <iostream>

#include <swap.hpp>

int main(int argc, char* argv[])
{
    auto str1 = "Hello"; auto str2 = "World";

    cpp_project_template::swap(str1, str2);

    std::cout << str2 << ", " << str1 << "!!!" << std::endl;

    return 0;
}
