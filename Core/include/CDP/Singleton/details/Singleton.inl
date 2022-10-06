#pragma once

#include <type_traits>

namespace Kala
{
    template<typename T>
    T& Singleton<T>::getInstance() noexcept(std::is_nothrow_constructible<T>::value)
    {
        static T instance;
        return instance;
    }
}
