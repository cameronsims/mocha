/* math.h
 * * mocha::add()
 */
#pragma once
#include "mocha.h"
//#include <math.h>
namespace mocha {
    /* mocha::PI */
    const long float PI = 3.14159265358979323846;
    /* mocha::e */
    const long float e = 2.71828182845904523536;

    /* mocha::min()
     * * "_left": "Argument to compare"
     * * "_right": "Argument to compare to"
     */
    float min(const float _left, const float _right) {
        return (_left < _right) ? _left : _right;
    }
    /* mocha::max() 
     * * "_left": "Argument to compare to"
     * * "_right": "Argument to compare to"
     */
    float max(const float _left, const float _right) {
        return (_left > _right) ? _left : _right;
    }

    /* mocha::abs()
     * * "_num": "Number to absolute"
     */
    float abs(const float _num) {
        return (_num < 0) ? -_num : _num;
    }
}