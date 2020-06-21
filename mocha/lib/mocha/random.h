/* random.h
 * * mocha::random()
 */
#pragma once
#include "mocha.h"
#include <random>
namespace mocha {
    std::default_random_engine randEngine;
    /* mocha::random()
     * * TEMPLATE: { "type": RETURN AND INPUT TYPE }
     * * "ceiling": Highest possible number
     * * "floor":  Lowest possible number
     */
    template<typename T>
    T random(const T _floor, const T _ceiling) {
        std::uniform_int_distribution<T> r(_floor, _ceiling);
        return r(randEngine);
    }
    template<typename T>
    T random(const T _ceiling) {
        std::uniform_int_distribution<T> r(0, _ceiling);
        return r(randEngine);
    };
    template<typename T>
    T random() {
        std::uniform_int_distribution<T> r(0, 256);
        return r(randEngine);
    }
    
}