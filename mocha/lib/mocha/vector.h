/* vector.h
 * * mocha::vector()
 * * mocha::out_of_range()
 */
#pragma once
#include "mocha.h"
#include "array.h"
#include "darray.h"
#include "iterator.h"
#include <stdarg.h>
#define MOCHA_VECTOR true
namespace mocha {
    /* mocha::out_of_range */
    class out_of_range {
    protected:
        static size_t iterations;
        const char* what;
    public:
                 
                 out_of_range(const mocha::out_of_range&) noexcept {};
        out_of_range()
            : what("Vector has gone out of Size Range") {
        #ifdef MOCHA_DEBUG
            printf("[mocha]: Exception created!\n");
        #endif
            iterations++;
        };
        virtual ~out_of_range();
        const char*    reason() { return what; }
        static size_t& amount() { return iterations; }
    };
    /* mocha::vector()
     * * TEMPLATE: {
     * * * "T": "Typename to use" 
     * * }
     */
    template<typename T>
    struct vector {
      protected:
        size_t resolution = 8;
        size_t elemsize{};
        T* arr = new T[resolution];

        void check(const size_t& _i) {
            if (_i >= resolution) {
                this->realloc(_i);
            }
            if (_i >= elemsize) {
                throw mocha::out_of_range();
            }
        }
      private:
        void realloc(const size_t& _s) {
            T* temp = new T[resolution];
            for (size_t i = 0; i < resolution; i++)
                temp[i] = arr[i];
            this->resolution = _s + 8;
            delete[] arr;
            arr = new T[resolution];
            for (size_t i = 0; i < resolution; i++)
                arr[i] = temp[i];
            this->elemsize = _s;
            delete[] temp;
        }
      public:
        size_t                  size (          ) const noexcept { return this->elemsize; }
        size_t                  res  (          ) const noexcept { return this->resolution; }
        size_t                  bytes(          ) const noexcept { return this->resolution * sizeof(T); }
              T*                data (          )                { return arr; }
        const T*                data (          ) const          { return arr; }
                    iterator<T> begin(          )       noexcept { return       iterator<T>(arr); }
                    iterator<T> end  (          )       noexcept { return       iterator<T>(arr +elemsize -1); }
        const const_iterator<T> begin(          ) const noexcept { return const_iterator<T>(arr); }
        const const_iterator<T> end  (          ) const noexcept { return const_iterator<T>(arr +elemsize -1); }
             T*                 push (      T _d)                { check(elemsize + 1); arr[elemsize++] = _d; return arr; }
             T*                 pop  (          )                { arr[elemsize - 1] = T{}; elemsize = elemsize -1;                 return arr; }
             T*                 clear(          )                { delete[] arr;            elemsize = 0;           resolution = 8; return arr = new T[8]; }

              T& operator[](const size_t& _i)       { check(_i); return arr[_i]; }
        const T& operator[](const size_t& _i) const { check(_i); return arr[_i]; }

        void set(const T _val) {
            size_t i{};
            while (i < resolution) {
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
            for (size_t i = 0; i < PX * PY; i++) {
                arr[i] = _arr[i];
            }
        }

        vector() = default;
        template<size_t _x>
        vector(T _arr[_x]) {
            for (size_t i = 0; i < _x; i++) {
                arr[i] = _arr[i];
            }
        }
        vector(const std::initializer_list<T>& _arr) {
            size_t i{};
            for (const T& t : _arr) {
                arr[i] = (T)t;
            }
        }
        template<size_t PS>
        vector(mocha::array<T, PS>& _arr) {
            for (int i = 0; i < PS; i++) {
                arr[i] = _arr[i];
            }
        }
        template<size_t PX, size_t PY>
        vector(mocha::darray<T, PX, PY>& _arr) {
            for (int i = 0; i < PX * PY; i++) {
                arr[i] = _arr[i];
            }
        }
        explicit vector(const unsigned int _size) 
            : resolution(_size +8),
              elemsize  (_size)
        {
            for (int i = 0; i < _size; i++)
                arr[i] = T{};
        }
        ~vector() { delete[] arr; }
    };
}
size_t mocha::out_of_range::iterations = 0;