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
        const char* what = "Vector has gone out of size range";
    public:
        out_of_range(const MOCHA out_of_range&) noexcept {};
        out_of_range() {
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
        T* content = new T[resolution];

        void check(const size_t& _i) {
            if (_i >= resolution) {
                this->realloc(_i);
            }
            if (_i >= elemsize) {
                elemsize += _i - elemsize;
            }
        }
        void check(const size_t& _i) const {
            if (_i >= resolution || _i >= elemsize) {
                throw out_of_range();
            }
        }
      private:
        void realloc(const size_t& _s) {
            T* temp = new T[resolution];
            for (size_t i = 0; i < resolution; i++)
                temp[i] = content[i];
            delete[] content;
            this->resolution = _s + 8;
            content = new T[resolution];
            for (size_t i = 0; i < resolution; i++)
                content[i] = temp[i];
            this->elemsize = _s;
            delete[] temp;
        }
      public:
        size_t                        size (          ) const noexcept { return this->elemsize; }
        size_t                     capacity(          ) const noexcept { return this->resolution; }
              T*                      data (          )                { return content; }
        const T*                      data (          ) const          { return content; }

              MOCHA               iterator<T>   begin(          )       noexcept { return MOCHA               iterator<T>(content[0]); }
              MOCHA               iterator<T>     end(          )       noexcept { return MOCHA               iterator<T>(content[elemsize]); }
        const MOCHA         const_iterator<T>   begin(          ) const noexcept { return MOCHA         const_iterator<T>(content[0]); }
        const MOCHA         const_iterator<T>     end(          ) const noexcept { return MOCHA         const_iterator<T>(content[elemsize]); }

        MOCHA             reverse_iterator<T>  rbegin(          )       noexcept { return MOCHA       reverse_iterator<T>(content[elemsize -1]); }
        MOCHA             reverse_iterator<T>    rend(          )       noexcept { return MOCHA       reverse_iterator<T>(content[-1]); }
        const MOCHA const_reverse_iterator<T>  rbegin(          ) const noexcept { return MOCHA const_reverse_iterator<T>(content[elemsize -1]); }
        const MOCHA const_reverse_iterator<T>    rend(          ) const noexcept { return MOCHA const_reverse_iterator<T>(content[-1]); }

              T*                      push (T       _d)                { check(elemsize);         content[elemsize++] = _d;                   return content; }
              T*                      pop  (          )                { content[elemsize - 1] = T{}; elemsize = elemsize -1;                 return content; }
              T*                      clear(          )                { delete[] content;            elemsize = 0;           resolution = 8; return content = new T[8]; }

              T& operator[](const size_t          _i)       { check(_i); return content[_i]; }
        const T& operator[](const size_t          _i) const { check(_i); return content[_i]; }

        template<size_t tS>
        void     operator=(mocha::array<T, tS>& _arr) {
            for (int i = 0; (i < tS && i < resolution); ++i)
                content[i] = _arr[i];
        }
        template<size_t tX, size_t tY>
        void     operator=(mocha::darray<T, tX, tY> & _arr) {
            for (int i = 0; (i < (tX * tY) && i < resolution); ++i)
                content[i] = _arr[i];
        }
        void     operator=(mocha::vector<T>& _arr) {
            for (int i = 0; (i < _arr.resolution && i < resolution); ++i)
                content[i] = _arr[i];
        }

        void set(const T _val) {
            size_t i{};
            while (i < resolution) {
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
        void set(const T* _arr, const size_t& _size) {
            for (int i = 0; i < _size; i++) {
                content[i] = *_arr[i];
            }
        }
        template<size_t PS>
        void set(const MOCHA array<T, PS>& _arr) {
            for (size_t i = 0; i < PS; i++) {
                content[i] = _arr[i];
            }
        }
        template<size_t PX, size_t PY>
        void set(const MOCHA darray<T, PX, PY>& _arr) {
            for (size_t i = 0; i < PX * PY; i++) {
                content[i] = _arr[i];
            }
        }

        vector() = default;
        template<size_t _x>
        vector(T _arr[_x]) {
            for (size_t i = 0; i < _x; i++) {
                content[i] = _arr[i];
            }
        }
        vector(const std::initializer_list<T>& _arr)
            : resolution(_arr.size() +8),
              elemsize(_arr.size())
        {
            size_t i{};
            for (size_t i = 0; i < _arr.size(); i++) {
                this->content[i] = *(_arr.begin() + i);
            }
        }
        template<size_t PS>
        vector(MOCHA array<T, PS>& _arr)
            : resolution(elemsize + 8),
              elemsize(_arr.size())
        {
            for (int i = 0; i < PS; i++) {
                content[i] = _arr[i];
            }
        }
        template<size_t PX, size_t PY>
        vector(MOCHA darray<T, PX, PY>& _arr)
            : elemsize(_arr.size())
        {
            for (int i = 0; i < PX * PY; i++) {
                content[i] = _arr[i];
            }
        }
        explicit vector(const unsigned int _size) 
            : resolution(elemsize + 8),
              elemsize  (_size)
        {
            for (int i = 0; i < _size; i++)
                content[i] = T{};
        }
        ~vector() { delete[] content; }
    };
}
size_t MOCHA out_of_range::iterations = 0;