/* darray.h
 * * mocha::darray()
 */
#pragma once
#include "mocha.h"
#include "array.h"
#include "iterator.h"
#include <stdarg.h>
#include <initializer_list>
#define MOCHA_DARRAY true
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
      public:
        constexpr size_t size (                               ) const noexcept { return X * Y; };
        constexpr size_t bytes(                               ) const noexcept { return (X * Y) * sizeof(T); }
                  T*     data (                               )                { return arr; }
        const     T*     data (                               ) const          { return arr; }

                    iterator<T>& begin(                       )       noexcept { return iterator<T>      (arr); }
                    iterator<T>&   end(                       )       noexcept { return iterator<T>      (arr + (X*Y)); }
        const const_iterator<T>& begin(                       ) const noexcept { return const_iterator<T>(arr); }
        const const_iterator<T>&   end(                       ) const noexcept { return const_iterator<T>(arr + (X*Y)); }
        
        void set(const T _val) {
            size_t i{};
            while (i < X*Y) {
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
        void set(const T* _arr, const size_t& _size) {
            for (int i = 0; i < _size; i++) {
                arr[i] = *_arr[i];
            }
        }
        template<size_t PS>
        void set(const mocha::array<T, PS>& _arr) {
            for (size_t i = 0; i < PS; i++) {
                arr[i] = _arr[i];
            }
        }
        template<size_t PX, size_t PY>
        void set(const mocha::darray<T, PX, PY>& _arr) {
            for (size_t i = 0; i < X * Y; i++) {
                arr[i] = _arr[i];
            }
        }
        
        void     operator= (const std::initializer_list<T>& _arr) { set(_arr); }
        void     operator= (const T                       _arr[]) { set(_arr); }
        template<size_t S>
        void     operator= (const mocha::array<T, S>        _arr) { set(_arr); }
        template<size_t X, size_t Y>
        void     operator= (const mocha::darray<T, X, Y>    _arr) { set(_arr); }
              T& operator()(const size_t& _x, const size_t& _y)                { return arr[(_y * X) + _x]; }
        const T& operator()(const size_t& _x, const size_t& _y) const          { return arr[(_y * X) + _x]; }
              T& operator[](const size_t& _i                  )                { return arr[_i]; }
        const T& operator[](const size_t& _i                  ) const          { return arr[_i]; }

        darray() {}
        template<size_t _x, size_t _y>
        darray(T _arr[_x][_y]) {
            for (size_t i = 0; i < X; i++)
            for (size_t j = 0; j < Y; j++) {
                arr[i] = _arr[i][j];
            }
        }
        darray(const std::initializer_list<T>& _arr) {
            size_t i{};
            for (const T& t : _arr) {
                arr[i] = (T)t;
            }
        }
        darray(mocha::darray<T, X, Y>& _arr) {
            for (int i = 0; i < X + Y; i++) {
                arr[i] = _arr[i];
            }
        }
      protected:
        T arr[X * Y];
    };
}