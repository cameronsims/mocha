/* foreach.h
 * * mocha::foreach()
 */
#pragma once
#include "mocha.h"
#include <vector>
namespace mocha {
    /* mocha::foreach()
     * * template { "T": "Typename used for "arr" and "f"" }
     * * "_arr": Vector or Array to look through
     * * "f": Lambda or function to use if found
     */
    template<typename T>
    void foreach(const std::vector<T>& _arr, void(*f)(T)) {
        for (T& a : _arr) f(a);
    }
    template<typename T>
    void foreach(const T* _arr, void(*f)(T)) {
        for (T& a : _arr) f(a);
    }
}