/* sort.h
 * * mocha::sort_c
 * * mocha::sort()
 */
#pragma once
#define MOCHA_SORT true
#include "mocha.h"
#include "math.h"
#include "memory.h"
#include "iterator.h"
namespace mocha {
    /* mocha::sort_c:::get() */
    class sort_c {
        // VARIABLES AND FUNCTIONS
      public:
        /* mocha::sort_c::algorithms */
        enum algorithm : unsigned int { 
            algorithmBUBBLE = 0,
            algorithmSELECTION,
            algorithmINSERTION
        };
          
        /* mocha::sort_c::instance */
        const static sort_c instance;

        /* mocha::sort::mode */
        mutable algorithm mode = algorithmINSERTION;

        /* mocha::sort_c::bubble()
         * * TYPENAME: { "T": "Typename to use" }
         * * "_arr": "Array to sort"
         * * "_i": "Where to start in the array"
         * * "_n": "Array size"
         */
        template<typename T>
        const sort_c& bubble     (T* _arr, const size_t _i, const size_t _n) const {
            for (int i = _i; i < _n;       i++) 
            for (int j = _i; j < _n -i -1; j++) {
                if (_arr[j] > _arr[j + 1])
                    MOCHA swap(&_arr[j], &_arr[j +1]);
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
                    MOCHA swap(&_arr[j], &_arr[j +1]);
            }
            return instance;
        }
        /* mocha::sort_c::bubble()
         * * TYPENAME: { "IT": "Iterator to use" }
         * * "_begin": "Beginning of Container"
         * * "_end"  : "Ending of Container"
         * * "_func" : "Function that compares values of comparing iterators"
         */
        template<class IT, typename FUNC>
        const sort_c& bubble(IT& _begin, IT& _end, FUNC& func/*void(*func)(IT&, IT&)*/) const {
            for (IT i = _begin; i < _end; ++i)
            for (IT j = _begin; j < i;    ++j) {
                if (func(i, j))
                    MOCHA swap(*i, *j);
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
        sort_c(              ) = default;
        sort_c(const sort_c& ) = delete;
        sort_c(const sort_c&&) = delete;

        template<typename T>
        void operator()(T* const _arr, const size_t _first, const size_t _size, const bool _rev = false) const { 
            size_t len = _size - _first;
            switch (mode) {
                case algorithmBUBBLE: { 
                    (!_rev) 
                      ? this->bubble (_arr, 0, len)
                      : this->bubbler(_arr, 0, len); 
                }
                case algorithmINSERTION:
                {
                    (!_rev)
                        ? this->insertion (_arr, 0, len)
                        : this->insertionr(_arr, 0, len);
                }
                case algorithmSELECTION:
                {
                    (!_rev)
                        ? this->selection (_arr, 0, len)
                        : this->selectionr(_arr, 0, len);
                }
            }
        }
    };

    void                sort(MOCHA sort_c::algorithm _alg) {
        MOCHA sort_c::instance.mode = _alg;
    }
    template<typename T>
    void                sort(T* _arr, const size_t _first, const size_t _size, const bool _rev = false) { 
        MOCHA sort_c::instance(_arr, _first, _size, _rev); 
    };
    
    template<class IT>
    void                sort(IT _first, IT _last) {
        struct {
            bool operator()(IT& a, IT& b) const { return *a < *b; }
        } default_compare;

        switch (MOCHA sort_c::instance.mode) {
            case MOCHA sort_c::algorithmBUBBLE: { MOCHA sort_c::instance.bubble(_first, _last, default_compare); }
        }
    }
    template<class IT, class FUNC>
    void                sort(IT _first, IT _last, FUNC& func) {
        switch (MOCHA sort_c::instance.mode) {
            case MOCHA sort_c::algorithmBUBBLE: { MOCHA sort_c::instance.bubble(_first, _last, func); }
        }
    }
    
}
const MOCHA sort_c MOCHA sort_c::instance;