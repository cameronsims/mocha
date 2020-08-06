/* sort.h
 * * mocha::array()
 */
#pragma once
#include "mocha.h"
#include "darray.h"
#include "sort.h"
#include <stdarg.h>
#include <initializer_list>
#define MOCHA_ARRAY
namespace mocha {
    /* mocha::array()
     * * TEMPLATE: {
     * * * "T": "Typename to use" 
     * * * "S": "Size of Array"   }
     */
    template<typename T, size_t S>
    struct array {
    private:
        struct iterator {
          public:
            iterator() = default;
            iterator(T* _ptr)
                : content(_ptr) {}
            ~iterator() = default;

            T         operator* () const { return *content; };
            T* operator->() const { return content; }
            iterator& operator++() { content++; return *this; };
            iterator  operator++(int) { content++; return *this; };

            bool      operator==(const iterator& _r) const { return *content == *_r; };
            bool      operator!=(const iterator& _r) const { return *content != *_r; };
            bool      operator==(const T         _r) const { return *content == _r; };
            bool      operator!=(const T         _r) const { return *content != _r; };
          protected:
            T* content;
        };
        struct const_iterator {
        public:
            const_iterator() = default;
            const_iterator(const T* _ptr)
                : content(_ptr) {}
            ~const_iterator() = default;

            T         operator* () const { return *content; };
            T* operator->() const { return content; }
            const const_iterator& operator++() { T i = *this; content++; return *this; };
            const const_iterator  operator++(int) { content++; return *this; };

            bool      operator==(const iterator& _r) const { return *content == *_r; };
            bool      operator!=(const iterator& _r) const { return *content != *_r; };
            bool      operator==(const const_iterator& _r) const { return *content == *_r; };
            bool      operator!=(const const_iterator& _r) const { return *content != *_r; };
            bool      operator==(const T& _r) const { return *content == _r; };
            bool      operator!=(const T& _r) const { return *content != _r; };
          protected:
            T* content;
        };
    protected:
        T Array[S];
    public:
        constexpr size_t size()  const noexcept { return S; }
        constexpr size_t bytes() const noexcept { return S * sizeof(T); }

        iterator       begin()       { return iterator(Array); }
        iterator         end()       { return iterator(Array + S); }
        const_iterator begin() const { return const_iterator(Array); }
        const_iterator   end() const { return const_iterator(Array + S); }

        T* data() { return Array; }
        const T* data() const { return Array; }

        mocha::sort& sort(const mocha::sort::algorithm& _alg = mocha::sort::mode) { return mocha::sort::get()(Array, S); }

        void set(const T _val) { memset(Array, _val, S * sizeof(T)); }
        void set(const size_t _i, const T _val) { Array[_i] = _val; }
        void set(const std::initializer_list<T>& _arr) {
            int itr{};
            for (const T& t : _arr) {
                Array[itr] = t;
                itr++;
            }
        }
        void set(const T* _arr, const size_t& _size) {
            for (int i = 0; i < _size; i++) {
                Array[i] = _arr[i];
            }
        }

        array() {}
        array(const T*                          _arr) {
            set(_arr, S]);
        }
        array(const std::initializer_list<T>&   _arr) { set(_arr); }
        template<typename Ta, size_t S>
        array(const array<Ta, S>&                _arr) {
            set(_arr.data(), _arr.size());
        }
        template<size_t X, size_t Y>
        array(const darray<T, X, Y>&            _arr) {
            set(_arr.data(), _arr.size());
        }

              T& operator[](const size_t&                      i)       { return Array[i]; }
        const T& operator[](const size_t&                      i) const { return Array[i]; }
        void     operator= (const std::initializer_list<T>& _arr) { set(_arr); }
        void     operator= (const T                       _arr[]) { set(_arr); }
    };

    template<typename T, size_t l>
    size_t size(const mocha::array<T, l> arr) { return arr.size(); }
}