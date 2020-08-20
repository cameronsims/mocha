/* sort.h
 * * mocha::sort()
 */
#pragma once
#define MOCHA_SORT true
#include "mocha.h"
#ifdef MOCHA_MATH
#include "math.h"
#endif
#include "memory.h"
#include "array.h"
#include "darray.h"
namespace mocha {
    /* defined in <mocha/math.h> */
    float ceil (const float);
    float floor(const float);
    template<typename T>
    bool  even (const T);

    /* mocha::sort_c:::get() */
    class sort_c {
        // VARIABLES AND FUNCTIONS
      public:
        /* mocha::sort_c::algorithms */
        enum class algorithm : unsigned int { 
            BUBBLE = 0,
            SELECTION,
            INSERTION
        };
          
        /* mocha::sort_c::reverse */
        static bool reverse;

        /* mocha::sort_c::instance */
        const static sort_c instance;

        /* mocha::sort::mode */
        mutable algorithm mode = algorithm::BUBBLE;

        /* mocha::sort_c::bubble()
         * * TYPENAME: { "T": "Typename to use" }
         * * "_arr": "Array to sort"
         * * "_i": "Where to start in the array"
         * * "_n": "Array size"
         */
        template<typename T>
        const sort_c& bubble     (T* _arr, const size_t _i, const size_t _n) const {
            for (int i = _i; i < _n; i++)
            for (int j = _i; j < _n -i -1; j++) {
                if (_arr[j] > _arr[j + 1])
                    swap(&_arr[j], &_arr[j +1]);
            }
            return instance;
        }
        /* mocha::sort_c::bubbler()
        * * TYPENAME: { "T": "Typename to use" }
        * * "_arr": "Array to sort backwards"
        * * "_i": "Where to start in the array"
        * * "_n": "Array size"
        */
        template<typename T>
        const sort_c& bubbler    (T* _arr, const size_t _i, const size_t _n) const {
            for (int i = _i; i < _n; i++)
            for (int j = _i +1; j < _n; j++) {
                if (_arr[j] < _arr[j +1])
                    swap(&_arr[j], &_arr[j +1]);
            }
            return instance;
        }

        /* mocha::sort_c::selection()
        * * TYPENAME: { "T": "Typename to use" }
        * * "_arr": "Array to sort"
        * * "_i": "Where to start in the array"
        * * "_n": "Array size"
        */
        template<typename T>
        const sort_c& selection  (T* _arr, const size_t _i, const size_t _n) const {
            int k;
            for (int i = _i; i < _n; i++) {
                k = i;
                for (int j = i + 1; j < _n; j++)
                if (_arr[j] < _arr[k])
                    k = j;
                swap(_arr[k], _arr[i]);
            }
            return instance;
        }
        /* mocha::sort_c::selectionr()
        * * TYPENAME: { "T": "Typename to use" }
        * * "_arr": "Array to sort"
        * * "_i": "Where to start in the array"
        * * "_n": "Array size"
        */
        template<typename T>
        const sort_c& selectionr (T* _arr, const size_t _i, const size_t _n) const {
            int k;
            for (int i = _n -1; i >= _i; i--) {
                k = i;
                for (int j = _n -1; j >= i +1; j--)
                if (_arr[j] > _arr[k])
                    k = j;
                swap(_arr[k], _arr[i]);
            }
            return instance;
        }
        
        /* mocha::sort_c::insertion()
         * * TYPENAME: { "T": "Typename to use" }
         * * "_arr": "Array to sort"
         * * "_i": "Where to start in the array"
         * * "_n": "Array size"
         */
        template<typename T>
        const sort_c& insertion  (T* _arr, const size_t _i, const size_t _n) const {
            T k;
            int j;
            for (int i = _i +1; i < _n; i++) {
                k = _arr[i];
                j = i -1;
                while (j >= _i && _arr[j] > k) {
                    _arr[j +1] = _arr[j];
                    j = j -1;
                }
                _arr[j +1] = k;
            }
            return instance;
        }
        /* mocha::sort_c::insertion()
         * * TYPENAME: { "T": "Typename to use" }
         * * "_arr": "Array to sort"
         * * "_i": "Where to start in the array"
         * * "_n": "Array size"
         */
        template<typename T>
        const sort_c& insertionr (T* _arr, const size_t _i, const size_t _n) const {
            T k;
            int j;
            for (int i = _i +1; i < _n; i++) {
                k = _arr[i];
                j = i -1;
                while (j >= _i && _arr[j] < k) {
                    _arr[j + 1] = _arr[j];
                    j = j -1;
                }
                _arr[j + 1] = k;
            }
            return instance;
        }
        
        // CONSTRUCTORS AND DESTRUCTORS
        sort_c(            ) {}
        sort_c(const sort_c& ) = delete;
        sort_c(const sort_c&&) = delete;

        template<typename T>
        const sort_c& run(T* _arr, const size_t _first, const size_t _size, const bool _rev = reverse) const {
            switch (mode) {
                case algorithm::BUBBLE: {
                    return (_rev)
                        ? bubbler(_arr, _first, _size)
                        : bubble (_arr, _first, _size);
                }
                case algorithm::SELECTION: {
                    return (_rev)
                        ? selectionr(_arr, _first, _size)
                        : selection (_arr, _first, _size);
                }
                case algorithm::INSERTION: {
                    return (_rev)
                        ? insertionr(_arr, _first, _size)
                        : insertion (_arr, _first, _size);
                }

                default: throw exception("MOCHA SORTING ALGORITHM NOT KNOWN!");
            }
        }

        template<typename T>
        T* operator()(T* _arr, const size_t _first, const size_t _size, const bool _rev = reverse) const {
            size_t len = _size - _first,
                i{};
            run(_arr, _first, _size +_first, _rev);
            return _arr;
        }
        template<typename T>
        T* operator()(const T* _arr, const size_t _first, const size_t _size, const bool _rev = reverse) const { 
            size_t len = _size - _first,
                   i{};
            T* arr = new T[len];
            while (i < len) {
                arr[i] = _arr[i];
                i++;
            }
            run(arr, _first, _size +_first, _rev);
            return arr;
        }
    };

    template<typename T>
    const T* sort(const T* _arr, const size_t _first, const size_t _size, const bool _rev = mocha::sort_c::reverse) { return mocha::sort_c::instance(_arr, _first, _size, _rev); };
    template<typename T>
    T* sort(T* _arr, const size_t _first, const size_t _size, const bool _rev = mocha::sort_c::reverse) { return mocha::sort_c::instance(_arr, _first, _size, _rev); };
    const mocha::sort_c& sort(const mocha::sort_c::algorithm _alg) { 
        mocha::sort_c::instance.mode = _alg; 
        return mocha::sort_c::instance;
    }
    const mocha::sort_c& sort(const bool _bl) {
        mocha::sort_c::instance.reverse = _bl;
        return mocha::sort_c::instance;
    }
}

const mocha::sort_c mocha::sort_c::instance;
bool mocha::sort_c::reverse = false;