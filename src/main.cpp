#include <iostream>

#include <swap.hpp>

int main(int argc, char* argv[])
{
    int a =10; int b =5;

    cpp_project_template::swap(a, b);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}
