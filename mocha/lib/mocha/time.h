/* time.h
 * * mocha::Timer()
 */
#pragma once
#include "mocha.h"
#include <chrono>
#ifdef mocha_debug
#include "console.h"
#endif mocha_debug
namespace mocha {
    /* mocha::Timer */
    class Timer {
      public:
        // CONSTRUCTORS & DESTRUCTORS
        /* mocha::Timer::Timer() 
         * * OVERLOADS:
         * * * "_action": Start Timer Immediently
         * * * "f": Set Timer start to time
         */
        Timer(                                                    ) { reset(); }
        Timer(bool                                         _action) { if (_action) { reset(); } }
        Timer(std::chrono::time_point<std::chrono::steady_clock> f) { set(f); }

        // VARIABLES & FUNCTIONS
      private: std::chrono::time_point<std::chrono::steady_clock> _begin, _final;
      public:

        /* mocha::Timer::getStart() */
        std::chrono::time_point<std::chrono::steady_clock> getStart() const {
            return _begin;
        }

        /* mocha::Timer::_convert() */
        float _convert() const {
            return std::chrono::duration<float>(now() - _begin).count();
        }
        /* mocha::Timer::now() */
        std::chrono::time_point<std::chrono::steady_clock> now() const {
            return std::chrono::high_resolution_clock::now();
        }
        /* mocha::Timer::get() */
        auto get() const {
            return (_convert() * 1000.0f);
        }
        /* mocha::Timer::set() */
        void set(std::chrono::time_point<std::chrono::steady_clock>& point) {
            _begin = point;
        }
        /* mocha::Timer::end() */
        void end() {
            _final = now();
        }
        /* mocha::Timer::reset() */
        void reset() {
            _begin = now();
        }
    };
}