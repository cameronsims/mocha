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
namespace mocha {
    /* defined in <mocha/math.h> */
    float ceil (const float);
    float floor(const float);
    template<typename T>
    bool  even (const T);

    /* mocha::sort::get() */
    class sort {
        // VARIABLES AND FUNCTIONS

        /* mocha::sort::instance */
        static sort instance;

      public:
          
        /* sort_algorithms */
        enum class algorithm : unsigned int { 
            BUBBLE = 0,
            SELECTION,
            INSERTION
        };
          
        /* mocha::sort::reverse */
        static bool reverse;

        /* mocha::sort::mode */
        static algorithm mode;

        /* mocha::sort::get()
         * OVERLOADS:
         * * "_i": "Algorithm to Use"
         * * "_b": "To reverse sorting"
         */
        static sort& get() { 
            return instance;
        }
        static sort& get(const bool _b, const algorithm& _i = mode) {
            reverse = _b;
            mode = _i;
            return instance;
        }
        static sort& get(const algorithm& _i, const bool _b = reverse) {
            return get(_b, _i);
        }

        /* mocha::sort::bubble()
         * * TYPENAME: { "T": "Typename to use" }
         * * "_arr": "Array to sort"
         * * "_i": "Where to start in the array"
         * * "_n": "Array size"
         */
        template<typename T>
        sort& bubble     (T* _arr, const size_t _i, const size_t _n) const {
            for (int i = _i; i < _n; i++)
            for (int j = _i; j < _n -i -1; j++) {
                if (_arr[j] > _arr[j + 1])
                    swap(&_arr[j], &_arr[j +1]);
            }
            return instance;
        }
        /* mocha::sort::bubbler()
        * * TYPENAME: { "T": "Typename to use" }
        * * "_arr": "Array to sort backwards"
        * * "_i": "Where to start in the array"
        * * "_n": "Array size"
        */
        template<typename T>
        sort& bubbler    (T* _arr, const size_t _i, const size_t _n) const {
            for (int i = _i; i < _n; i++)
            for (int j = _i +1; j < _n; j++) {
                if (_arr[j] < _arr[j +1])
                    swap(&_arr[j], &_arr[j +1]);
            }
            return instance;
        }

        /* mocha::sort::selection()
        * * TYPENAME: { "T": "Typename to use" }
        * * "_arr": "Array to sort"
        * * "_i": "Where to start in the array"
        * * "_n": "Array size"
        */
        template<typename T>
        sort& selection  (T* _arr, const size_t _i, const size_t _n) const {
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
        /* mocha::sort::selectionr()
        * * TYPENAME: { "T": "Typename to use" }
        * * "_arr": "Array to sort"
        * * "_i": "Where to start in the array"
        * * "_n": "Array size"
        */
        template<typename T>
        sort& selectionr (T* _arr, const size_t _i, const size_t _n) const {
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
        
        /* mocha::sort::insertion()
         * * TYPENAME: { "T": "Typename to use" }
         * * "_arr": "Array to sort"
         * * "_i": "Where to start in the array"
         * * "_n": "Array size"
         */
        template<typename T>
        sort& insertion  (T* _arr, const size_t _i, const size_t _n) {
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
        /* mocha::sort::insertion()
         * * TYPENAME: { "T": "Typename to use" }
         * * "_arr": "Array to sort"
         * * "_i": "Where to start in the array"
         * * "_n": "Array size"
         */
        template<typename T>
        sort& insertionr (T* _arr, const size_t _i, const size_t _n) {
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
        sort(            ) {}
        sort(const sort& ) = delete;
        sort(const sort&&) = delete;

        template<typename T>
        void run(T* _arr, const size_t _first, const size_t _size, const bool _rev = reverse) {
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
        T* operator()(const T* _arr, const size_t _first, const size_t _size, const bool _rev = reverse) const { 
            size_t len = _size - _first,
                   i{};
            T* t = new T[len];
            while (i < len) {
                t[i] = _arr[i];
                i++;
            }
            run(t, _first, _size, _rev);
            delete[] t;
            return t;
        }
    };
}

mocha::sort mocha::sort::instance;
bool mocha::sort::reverse = false;
mocha::sort::algorithm mocha::sort::mode = mocha::sort::algorithm::BUBBLE;