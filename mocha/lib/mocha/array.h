/* array.h
 * * mocha::array()
 */
#pragma once
#include "mocha.h"
#include "iterator.h"
#include <stdarg.h>
#define MOCHA_ARRAY true
namespace mocha {
    /* mocha::array()
     * * TEMPLATE: {
     * * * "T": "Typename to use" 
     * * * "S": "Size of Array"   }
     */
    template<typename T, size_t S>
    struct array {
    protected:
        T arr[S];
    public:
        constexpr size_t size()  const noexcept { return S; }
        constexpr size_t bytes() const noexcept { return S * sizeof(T); }

              MOCHA       iterator<T> begin()       { return       iterator<T>(arr[0]); }
              MOCHA       iterator<T>   end()       { return       iterator<T>(arr[S]); }
        const MOCHA const_iterator<T> begin() const { return const_iterator<T>(arr[0]); }
        const MOCHA const_iterator<T>   end() const { return const_iterator<T>(arr[S]); }

              T* data()       { return arr; }
        const T* data() const { return arr; }

        template<typename PT>
        void set(const PT _val) { 
            size_t i{};
            while (i < S) {
                arr[i] = _val;
                i++;
            }
        }
        void set(const std::initializer_list<T>& _arr) {
            int itr{};
            for (const T& t : _arr) {
                arr[itr] = t;
                itr++;
            }
        }
        template<typename PT>
        void set(const PT* _arr, const size_t& _size) {
            for (int i = 0; i < _size; i++) {
                arr[i] = *_arr[i];
            }
        }
        template<size_t PS>
        void set(const MOCHA array<T, S> _arr) {
            for (size_t i = 0; i < S; i++) {
                arr[i] = _arr[i];
            }
        }

        array() {}
        array(const T*                          _arr) { set(_arr, S); }
        array(const std::initializer_list<T>&   _arr) { set(_arr); }
        template<typename PT, size_t PS>
        array(const MOCHA array<PT, PS>&        _arr) {
            set(_arr.data(), _arr.size());
        }

              T& operator[](const size_t&                      i)       { return arr[i]; }
        const T& operator[](const size_t&                      i) const { return arr[i]; }
        void     operator= (const std::initializer_list<T>& _arr) { set(_arr); }
        template<typename PT>
        void     operator= (const PT                      _arr[]) { set(_arr); }
        template<size_t S>
        void     operator= (const MOCHA array<T, S>        _arr) { set(_arr); }
    };
}