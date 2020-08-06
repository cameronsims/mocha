/* darray.h
 * * mocha::darray()
 */
#pragma once
#include "mocha.h"
#include "sort.h"
#include <stdarg.h>
#include <initializer_list>
#define MOCHA_ARRAY
namespace mocha {
    /* mocha::darray()
     * * TEMPLATE: {
     * * * "T": "Typename to use"
     * * * "X": "X Size of Array"   
     * * * "Y": "Y Size of Array"
     * * }
     */
    template<typename T, size_t X, size_t Y>
    struct darray {
      private:
        struct iterator {
          public:
            iterator() = default;
            iterator(T* _ptr)
                : content(_ptr) 
            {}
            ~iterator() = default;

            T         operator* (   ) const { return *content; };
            T*        operator->(   ) const { return content; }
            iterator& operator++(   )       { content++; return *this; };
            iterator  operator++(int)       { content++; return *this; };

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
            const const_iterator& operator++(   ) { T i = *this; content++; return *this; };
            const const_iterator  operator++(int) { content++; return *this; };

            bool      operator==(const iterator&       _r) const { return *content == *_r; };
            bool      operator!=(const iterator&       _r) const { return *content != *_r; };
            bool      operator==(const const_iterator& _r) const { return *content == *_r; };
            bool      operator!=(const const_iterator& _r) const { return *content != *_r; };
            bool      operator==(const T&              _r) const { return *content == _r; };
            bool      operator!=(const T&              _r) const { return *content != _r; };
        protected:
            T* content;
        };
      public:
        constexpr size_t size () const noexcept { return X * Y; };
        constexpr size_t bytes() const noexcept { return (X * Y) * sizeof(T); }
        const     T*     data () const          { return Array; }

        iterator       begin()       { return iterator      (Array); }
        iterator         end()       { return iterator      (Array + (X*Y)); }
        const_iterator begin() const { return const_iterator(Array); }
        const_iterator   end() const { return const_iterator(Array + (X*Y)); }

              T& operator()(const size_t& _x, const size_t& _y)       { return Array[(_x * _y) + _y]; }
        const T& operator()(const size_t& _x, const size_t& _y) const { return Array[(_x * _y) + _y]; }

              T& operator[](const size_t& _i)       { return Array[_i]; }
        const T& operator[](const size_t& _i) const { return Array[_i]; }

        darray() {}
        template<size_t _x, size_t _y>
        darray(const T _arr[_x][_y]) {
            for (size_t i = 0; i < X; i++)
            for (size_t j = 0; j < Y; j++) {
                Array[i] = _arr[i][j];
            }
        }
        darray(const std::initializer_list<T>& _arr) {
            size_t itr{};
            for (T& t : _arr) {
                Array[itr] = t;
                itr++;
            }
        }
        darray(const mocha::darray<T, X, Y>& _arr) {
            for (int i = 0; i < X + Y; i++) {
                Array[i] = _arr[i];
            }
        }
      protected:
        T Array[X * Y];
      
    };

    template<typename T, size_t X, size_t Y>
    size_t size(const mocha::darray<T, X, Y> arr) { return arr.size(); }
}