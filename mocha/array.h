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
        T content[S];
    public:
        constexpr size_t size()  const noexcept { return S; }
        constexpr size_t bytes() const noexcept { return S * sizeof(T); }

              MOCHA               iterator<T>  begin()       noexcept { return MOCHA               iterator<T>(& content[0]); }
        const MOCHA         const_iterator<T>  begin() const noexcept { return MOCHA         const_iterator<T>(& content[0]); }
              MOCHA               iterator<T>    end()       noexcept { return MOCHA               iterator<T>(&(content[S])); }
        const MOCHA         const_iterator<T>    end() const noexcept { return MOCHA         const_iterator<T>(&(content[S])); }

              MOCHA       reverse_iterator<T> rbegin()       noexcept { return MOCHA       reverse_iterator<T>(&(content[S -1])); }
        const MOCHA const_reverse_iterator<T> rbegin() const noexcept { return MOCHA const_reverse_iterator<T>(&(content[S -1])); }
              MOCHA       reverse_iterator<T>   rend()       noexcept { return MOCHA       reverse_iterator<T>(& content[-1]); }
        const MOCHA const_reverse_iterator<T>   rend() const noexcept { return MOCHA const_reverse_iterator<T>(& content[-1]); }

              T* data()       { return content; }
        const T* data() const { return content; }

        template<typename PT>
        void set(const PT _val) { 
            size_t i{};
            while (i < S) {
                content[i] = _val;
                i++;
            }
        }
        void set(const std::initializer_list<T>& _arr) {
            int itr{};
            for (const T& t : _arr) {
                content[itr] = t;
                itr++;
            }
        }
        template<typename PT>
        void set(const PT* _arr, const size_t& _size) {
            for (int i = 0; i < _size; i++) {
                content[i] = (*_arr) +i;
            }
        }
        template<size_t PS>
        void set(const MOCHA array<T, S> _arr) {
            for (size_t i = 0; i < S; i++) {
                content[i] = _arr[i];
            }
        }

        array() {}
        array(const std::initializer_list<T>&   _arr) { set(_arr); }
        template<typename PT, size_t PS>
        array(const MOCHA array<PT, PS>&        _arr) {
            set(_arr.data(), _arr.size());
        }

              T& operator[](const size_t&                      i)       { return content[i]; }
        const T& operator[](const size_t&                      i) const { return content[i]; }
        void     operator= (const std::initializer_list<T>& _arr) { set(_arr); }
        template<typename PT>
        void     operator= (const PT                      _arr[]) { set(_arr); }
        template<size_t S>
        void     operator= (const MOCHA array<T, S>        _arr) { set(_arr); }
    };
}