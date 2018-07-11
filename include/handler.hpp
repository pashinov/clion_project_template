/**
 * File: handler.hpp
 *
 * Description: Handler function
*/

#ifndef HANDLER_HPP_
#define HANDLER_HPP_

#include <functional>


namespace cpp_project_template
{
    template<typename T>
    void handler(T& a, T& b, std::function<void(T&, T&)> callback)
    {
        callback(a, b);
    }
}

#endif //HANDLER_HPP_
