/* time/point.h 
 * * mocha::time_point()
 */
#pragma once
#include "../mocha.h"
#include "timer.h"
#include <time.h>
#include <stdio.h>
namespace mocha {
    /* mocha::time_point */
    struct time_point {
    private:
        time_t point{};
    public:
        
        time_t since()      const { return time(0) - point; }
        time_t operator()() const { return point; }
        
        #define MOCHA_TIME_OPERATOR_BOOL1(op, p) point op p
        #define MOCHA_TIME_OPERATOR_BOOL2(op, p) point op p

        time_t operator+ (const mocha::timer& t) const { return MOCHA_TIME_OPERATOR_BOOL2(+ , t.since()); }
        time_t operator- (const mocha::timer& t) const { return MOCHA_TIME_OPERATOR_BOOL2(- , t.since()); }
        time_t operator* (const mocha::timer& t) const { return MOCHA_TIME_OPERATOR_BOOL2(* , t.since()); }
        time_t operator/ (const mocha::timer& t) const { return MOCHA_TIME_OPERATOR_BOOL2(/ , t.since()); }
        void   operator+=(const mocha::timer& t)       {        MOCHA_TIME_OPERATOR_BOOL2(+=, t.since()); }
        void   operator-=(const mocha::timer& t)       {        MOCHA_TIME_OPERATOR_BOOL2(-=, t.since()); }
        void   operator*=(const mocha::timer& t)       {        MOCHA_TIME_OPERATOR_BOOL2(*=, t.since()); }
        void   operator/=(const mocha::timer& t)       {        MOCHA_TIME_OPERATOR_BOOL2(/=, t.since()); }
        void   operator =(const time_t&      _t)       { point = _t; }
        void   operator =(const timer&       _t)       { point = _t.since(); }

        #undef MOCHA_TIME_OPERATOR_BOOL1
        #undef MOCHA_TIME_OPERATOR_BOOL2
            
        bool operator==(const time_t& _t) const { return point == _t; }
        bool operator!=(const time_t& _t) const { return point != _t; }
        bool operator> (const time_t& _t) const { return point >  _t; }
        bool operator< (const time_t& _t) const { return point <  _t; }
        bool operator>=(const time_t& _t) const { return point >= _t; }
        bool operator<=(const time_t& _t) const { return point <= _t; }

        time_point() { }
        time_point(const time_t& _t)
            : point(_t) 
        { }
        time_point(const mocha::timer& _t) 
            : point(_t.since())
        { }
    };
}