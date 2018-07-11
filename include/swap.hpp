/**
 * File: swap.hpp
 *
 * Description: Swap function
*/

#ifndef SWAP_HPP_
#define SWAP_HPP_

#include <tuple>


namespace cpp_project_template
{
    template<typename T>
    void swap(T& a, T& b)
    {
        std::tie(a, b) = std::make_tuple(b, a);
    }
}

#endif //SWAP_HPP_
