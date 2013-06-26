#ifndef ARRAY_HPP
#define ARRAY_HPP

/* 

Multidimensional C-like Arrays in C++11
using template meta-programming

much inspiration taken from:
http://cpptruths.blogspot.de/2011/10/multi-dimensional-arrays-in-c11.html

*/

#include <array>

namespace util {
    
    template <class T, size_t I, size_t... J>
    struct MultiDimArray {
        using Nested = typename MultiDimArray<T, J...>::type;
        // typedef typename MultiDimArray<T, J...>::type Nested;
        using type = std::array<Nested, I>;
        // typedef std::array<Nested, I> type;
    };
 
    template <class T, size_t I>
    struct MultiDimArray<T, I> {
      using type = std::array<T, I>;
      // typedef std::array<T, I> type;
    };

} /* namespace util */

#endif /* end of include guard: ARRAY_HPP */