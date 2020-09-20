/* time/timer.h 
 * * mocha::timer()
 */
#pragma once
#include "../mocha.h"
#include <time.h>
#include <stdio.h>
namespace mocha {
    /* mocha::timer */
    class timer {
    protected:
        time_t _start,
               _stop;
    public:
        /* mocha::timer::now() */
        time_t now() const { return time(0); }

        /* mocha::timer::begin() */
        void begin() { _start = now(); }

        /* mocha::timer::end() */
        void stop () { _stop = now();  }

        /* mocha::timer::since() */
        time_t since() const {
            return now() - _start;
        }

        /* mocha::timer::start() */
        const time_t start() const { return _start; }
        /* mocha::timer::end() */
        const time_t end()   const { return _stop; }

        // CONTRUCTORS AND DESTRUCTORS

        timer()
            : _start(now()) 
        { }
        timer(const mocha::timer& _t)
            : _start(_t._start),
              _stop (_t._stop)
        { }
        timer(const time_t& _t)
            : _start(_t)
        { }
        
        ~timer() {
            stop();
        }


        #define MOCHA_TIME_OPERATOR_BOOL1(op, p) now() op p
        #define MOCHA_TIME_OPERATOR_BOOL2(op, p) _start op p

        bool   operator==(const mocha::time_t& t) const { return MOCHA_TIME_OPERATOR_BOOL1(==, t); }
        bool   operator!=(const mocha::time_t& t) const { return MOCHA_TIME_OPERATOR_BOOL1(!=, t); }
        bool   operator <(const mocha::time_t& t) const { return MOCHA_TIME_OPERATOR_BOOL1(< , t); }
        bool   operator >(const mocha::time_t& t) const { return MOCHA_TIME_OPERATOR_BOOL1(> , t); }
        bool   operator>=(const mocha::time_t& t) const { return MOCHA_TIME_OPERATOR_BOOL1(>=, t); }
        bool   operator<=(const mocha::time_t& t) const { return MOCHA_TIME_OPERATOR_BOOL1(>=, t); }

        time_t operator+ (const mocha::time_t& t) const { return MOCHA_TIME_OPERATOR_BOOL1(+ , t); }
        time_t operator- (const mocha::time_t& t) const { return MOCHA_TIME_OPERATOR_BOOL1(-, t); }
        time_t operator* (const mocha::time_t& t) const { return MOCHA_TIME_OPERATOR_BOOL1(*, t); }
        time_t operator/ (const mocha::time_t& t) const { return MOCHA_TIME_OPERATOR_BOOL1(/, t); }
        void   operator+=(const mocha::time_t& t)       { MOCHA_TIME_OPERATOR_BOOL2(+=, t); }
        void   operator-=(const mocha::time_t& t)       { MOCHA_TIME_OPERATOR_BOOL2(-=, t); }
        void   operator*=(const mocha::time_t& t)       { MOCHA_TIME_OPERATOR_BOOL2(*=, t); }
        void   operator/=(const mocha::time_t& t)       { MOCHA_TIME_OPERATOR_BOOL2(/=, t); }
        void   operator= (const mocha::time_t& t)       { _start = t; }

        bool   operator==(const mocha::timer&  t) const { return MOCHA_TIME_OPERATOR_BOOL2(==, t._start); }
        bool   operator!=(const mocha::timer&  t) const { return MOCHA_TIME_OPERATOR_BOOL2(!=, t._start); }
        bool   operator <(const mocha::timer&  t) const { return MOCHA_TIME_OPERATOR_BOOL2(< , t._start); }
        bool   operator >(const mocha::timer&  t) const { return MOCHA_TIME_OPERATOR_BOOL2(> , t._start); }
        bool   operator>=(const mocha::timer&  t) const { return MOCHA_TIME_OPERATOR_BOOL2(>=, t._start); }
        bool   operator<=(const mocha::timer&  t) const { return MOCHA_TIME_OPERATOR_BOOL2(>=, t._start); }

        time_t operator+ (const mocha::timer&  t) const { return MOCHA_TIME_OPERATOR_BOOL2(+ , t._start); }
        time_t operator- (const mocha::timer&  t) const { return MOCHA_TIME_OPERATOR_BOOL2(- , t._start); }
        time_t operator* (const mocha::timer&  t) const { return MOCHA_TIME_OPERATOR_BOOL2(* , t._start); }
        time_t operator/ (const mocha::timer&  t) const { return MOCHA_TIME_OPERATOR_BOOL2(/ , t._start); }
        void   operator+=(const mocha::timer&  t)       { MOCHA_TIME_OPERATOR_BOOL2(+=, t._start); }
        void   operator-=(const mocha::timer&  t)       { MOCHA_TIME_OPERATOR_BOOL2(-=, t._start); }
        void   operator*=(const mocha::timer&  t)       { MOCHA_TIME_OPERATOR_BOOL2(*=, t._start); }
        void   operator/=(const mocha::timer&  t)       { MOCHA_TIME_OPERATOR_BOOL2(/=, t._start); }
        void   operator= (const mocha::timer&  t)       { _start = t._start; }

        #undef MOCHA_TIME_OPERATOR_BOOL
        #undef define MOCHA_TIME_OPERATOR_BOOL2
    };
}