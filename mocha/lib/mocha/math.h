/* math.h
 * * mocha::null()
 * * mocha::PI()
 * * mocha::e()

 * * mocha::mmin()
 * * mocha::mmax()
 * * mocha::even()
 * * mocha::odd()

 * * mocha::power()
 * * mocha::sqrt()
 * * mocha::abs()
 * * mocha::floor()
 * * mocha::ceil()
 * * mocha::round()

 * * mocha::median()
 * * mocha::mode()
 * * mocha::mean()
 * * mocha::range()
 */
#pragma once
#define MOCHA_MATH true
#include "mocha.h"
#define MOCHA_PI 3.14159265358979323846
#define MOCHA_e  2.71828182845904523536
namespace mocha {
    //////////////////////////
    //                      //
    //   VARIABLE GETTERS   //
    //                      //
    //////////////////////////


    /* mocha::null() */
    template<typename T>
    T null() {
        return 0;
    }
    
    /* mocha::PI() */
    double PI() {
        return MOCHA_PI;
    }

    /* mocha::e() */
    double e() {
        return MOCHA_e;
    }


    /////////////////////////
    //                     //
    //   NUMBER CHECKING   //
    //                     //
    /////////////////////////

    /* mocha::mmin()
     * * TEMPLATE: { "T": "Typename to use" }
     * * "_left": "Argument to compare"
     * * "_right": "Argument to compare to"
     */
    template<typename T>
    T mmin(const T _left, const T _right) {
        return _left * (_left < _right) + 
               _right * (_right <= _left);
    }
    /* mocha::mmax() 
     * * TEMPLATE: { "T": "Typename to use" }
     * * "_left": "Argument to compare to"
     * * "_right": "Argument to compare to"
     */
    template<typename T>
    T mmax(const T _left, const T _right) {
        return _left * (_left > _right) +
               _right * (_right >= _left);
    }

    /* mocha::even()
     * * TEMPLATE: { "T": "Typename to use" }
     * * "_num": "Number to check"
     */
    template<typename T>
    bool even(const T _num) {
        return (_num % 2 == 0);
    }
    /* mocha::odd()
     * * TEMPLATE: { "T": "Typename to use" }
     * * "_num": "Number to check"
     */
    template<typename T>
    bool odd(const T _num) {
        return !mocha::even(_num);
    }


    /////////////////////////
    //                     //
    // NUMBER MANIPULATION //
    //                     //
    /////////////////////////


    /* mocha::power()
     * * TEMPLATE: { "T": "Typename to use" }
     * * "_base": "Base"
     * * "_powr": "Power"
     */
    template<typename T>
    T power(const T _base, const unsigned int _powr) {
        T base = _base;
        int i{};
        while (i < _powr -1) {
            base = base * _base;
            i++;
        }
        return base;
    }
    /* mocha::sqrt()
     * * NOTE: "USE THE STANDARD LIBRARY'S "sqrt()""
     * * TEMPLATE: { "T": "Typename to use" }
     * * "_square": "Number to square root"
     */
    template<typename T>
    T sqrt(const T _square) {
        if (_square < 2)
            return _square;
        size_t i = 1;
        while (true) {
            if (_square / i == i || _square / i < i)
                return i;
            i++;
        }
        return (T)i;
    }

    /* mocha::abs()
     * * TEMPLATE: { "T": "Typename to use" }
     * * "_num": "Number to absolute"
     */
    template<typename T>
    T abs(const T _num) {
        return (_num < 0) ? -_num : _num;
    }

    /* mocha::floor()
     * * "_num": "Number to round down"
     */
    float floor(const float _num) {
        return (int)_num;
    }
    /* mocha::ceiling()
     * * "_num": "Number to round up"
     */
    float ceil(const float _num) {
        return (int)_num +1;
    }
    /* mocha::round()
     * * "_num": "Number to round"
     */
    float round(const float _num) {
        bool cond = (_num - floor(_num) <= 0.5);
        return ceil(_num)  * !cond +
               floor(_num) * cond;

    }


    //////////////////////
    //                  //
    //    STATISTICS    //
    //                  //
    //////////////////////


    /* mocha::largest()
     * * TEMPLATE: { "T": "Typename to use" }
     * * "_arr": "Array to get highest value of"
     * * "_size": "Size of array"
     */
    template<typename T>
    T largest(const T* _arr, const size_t _size) {
        T highest = _arr[0];
        for (int i = 1; i < _size; i++) {
            if (highest < _arr[i]) {
                highest = _arr[i];
            }
        }
        return highest;
    }
    /* mocha::smallest()
     * * TEMPLATE: { "T": "Typename to use" }
     * * "_arr": "Array to get highest value of"
     * * "_size": "Size of array"
     */
    template<typename T>
    T smallest(const T* _arr, const size_t _size) {
        T tiniest = _arr[0];
        for (int i = 1; i < _size; i++) {
            if (tiniest > _arr[i]) {
                tiniest = _arr[i];
            }
        }
        return tiniest;
    }

    /* mocha::median()
     * * TEMPLATE: { "T": "Typename to use" }
     * * "_arr": "Array to get middle of"
     * * "_size": "Array size"
     */
    template<typename T>
    T median(T _arr[], const size_t _size) {
        mocha::sort::get()(_arr, 0, _size);
        return (even(_size) == 0) ?
            ((_arr[_size / 2] + _arr[_size /2 +1]) / 2.0)
            : _arr[_size / 2];
    }

    /* mocha::mode()
     * * TEMPLATE: { "T": "Typename to use" }
     * * "_arr": "Array to get middle of"
     * * "_size": "Array size"
     */
    template<typename T>
    T& mode(T* _arr, const size_t _size) {
        T &highVal = _arr[0],
          max{};
        for (int i = 0; i < _size; i++) {
            unsigned long amount{};
            for (int j = 0; j < _size; j++) {
                if (_arr[j] == _arr[i])
                    amount++;
            }
            if (amount > max) {
                max = amount;
                highVal = _arr[i];
            }
        }
        return highVal;
    }

    /* mocha::mean()
     * * TEMPLATE: { "T": "Typename to use" }
     * * "_arr": "Array to get middle of"
     * * "_size": "Array size"
     */
    template<typename T>
    T mean(const T* _arr, const size_t _size) {
        long val{};
        for (int i = 0; i < _size; i++) {
            val += _arr[i];
        }
        return val / _size;
    }

    /* mocha::range()
     * * TEMPLATE: { "T": "Typename to use" }
     * * "_arr": "Array to get range of"
     * * "_size": "Size of Array"
     */
    template<typename T>
    T range(const T* _arr, const size_t _size) {
        return largest(_arr, _size) - smallest(_arr, _size);
    }
}
