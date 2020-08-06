/* memory.h
 * * mocha::addressof()
 * * mocha::swap()
 * * mocha::memnull()
 * * mocha::memcpy()
 * * mocha::memset()
 * * mocha::memcmp()
 * * mocha::memmove()
 * * mocha::memlock()
 */
#pragma once
#define MOCHA_MEMORY true
#include "mocha.h"
namespace mocha {
    /* mocha::addressof()
     * * TEMPLATE: { "T": "Typename to Use" }
     * * "_alloc": "Variable to get address of"
     */
    template<typename T>
    const T* addressof(const T& _alloc) {
        return __builtin_addressof(_alloc);
    }

    /* mocha::swap()
     * * TYPENAME: { "T": "Typename to use" }
     * * "x": "To swap with "_y""
     * * "y": "To be swapped with "x""
     */
    template<typename T>
    void swap(T* x, T* y) {
        T t = *x;
        *x = *y;
        *y = t;
    }
    template<typename T>
    void swap(T& x, T& y) {
        T t = x;
        x = y;
        y = t;
    }

    /* mocha::memnull()
     * * TEMPLATE: { "T": "Typename to Use" }
     * OVERLOADS:
     * * "_obj": "Object to nullify"
     */
    template<typename T>
    T    memnull(             ) { return T{}; }
    template<typename T>
    void memnull(const T& _obj) { _obj = T{}; }

    /* mocha::memcpy() 
     * * TEMPLATE: { "T": "Typename to Use" }
     * * "_dest": "To copy "_src" into"
     * * "_src" : "To copy over to "_dest""
     * * "_from": "Where to start the copying from"
     * * "_to"  : "Where to end the copying"
     */
    template<typename T>
    void memcpy(T* _dest, const T* _src, const size_t _from, const size_t _to) {
        size_t i = _from;
        while (i <= _to) {
            _dest[i] = _src[i];
            i++;
        }
    }
    template<typename T>
    void memcpy(T* _dest, const T* _src, const size_t _to) {
        size_t i{};
        while (i <= _to) {
            _dest[i] = _src[i];
            i++;
        }
    }

    /* mocha::memset()
     * * TEMPLATE: { "T": "Typename to Use" }
     * * "_dest": "To copy "_src" into"
     * * "_src" : "To copy over to "_dest""
     * * "_from": "Where to start the copying from"
     * * "_to"  : "Where to end the copying"
     */
    template<typename T>
    void memset(T* _dest, const T _src, const size_t _from, const size_t _to) {
        size_t i = _from;
        while (i <= _to) {
            _dest[i] = _src;
            i++;
        }
    }
    template<typename T>
    void memset(T* _dest, const T _src, const size_t _to) {
        size_t i{};
        while (i <= _to) {
            _dest[i] = _src;
            i++;
        }
    }

    /* mocha::memcmp()
     * * TEMPLATE: { "T": "Typename to Use" }
     * * "_x"   : "To compare "_y" from"
     * * "_y"   : "To compare over to "_x""
     * * "_from": "Where to start the comparing from"
     * * "_to"  : "Where to end the comparing"
     */
    template<typename T>
    long memcmp(const T* _x, const T* _y, const size_t _from, const size_t _to) {
        /* <0 = first byte of _x is lower
         * 0  = first byte of _x is equal to _y
         * >0 = first byte of _x is greater
         */
        long ret{};
        for (long i = _from; i < _to; i++) {
            ret +=
            ((_x < _y) * *_y  +    // _x[i] is lesser than _y[i]  : returns <0 (if true)
             (_x > _y) * *_x) *    // _x[i] is greater than _y[i] : returns >0 (if true)
             (_x[i] != _y[i]);     // _x[i] is equal to _y[i]     : returns  0 (if true)
        }
        return ret;
    }
    template<typename T>
    long memcmp(const T* _x, const T* _y, const size_t _to) {
        long ret{};
        for (long i = 0; i < _to; i++) {
            ret +=
            ((_x < _y) * * _y  +    // _x[i] is lesser than _y[i]  : returns <0 (if true)
             (_x > _y) * * _x) *    // _x[i] is greater than _y[i] : returns >0 (if true)
             (_x[i] != _y[i]);      // _x[i] is equal to _y[i]     : returns  0 (if true)
        }
        return ret;
    }

    /* mocha::memmove()
     * * TEMPLATE: { "T": "Typename to Use" }
     * * "_dest": "To copy "_src" into"
     * * "_src" : "To copy over to "_dest""
     * * "_from": "Where to start the copying from"
     * * "_to"  : "Where to end the copying"
     */
    template<typename T>
    void memmove(T* _dest, T* _src, const size_t _from, const size_t _to) {
        T temp;
        for (int i = _from; i < _to; i++) {
            temp     = _src [i];
            _src [i] = _dest[i];
            _dest[i] = temp;
        }
    }
    template<typename T>
    void memmove(T* _dest, T* _src, const size_t _to) {
        T temp;
        for (int i = 0; i < _to; i++) {
            temp     = _src [i];
            _src [i] = _dest[i];
            _dest[i] = temp;
        }
    }

    /* mocha::memlock */
    template<typename T>
    class memlock {
        const T data;
    public:
        T& src;
        memlock() {}
        explicit memlock(T& _data)
            : data(_data),
              src (_data) 
        {
              src = T{};
        }
        ~memlock() {
            src = data;
        }
    
        bool operator==(const memlock& _data) const { return _data.data == this->data; }
    };
}