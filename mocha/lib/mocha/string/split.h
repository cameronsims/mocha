/* string/split.h
 * * mocha::str::split()
 */
#pragma once
#include "../mocha.h"
#include <string>
namespace mocha {
    namespace str {
        /* mocha::str::split()
         * "str": String to split
         * "del": Character to delimate
         */
        const char* split(const char* str, char del[]) {
            return strtok((char*)str, del);
        }
        std::string* split(std::string& str, char del[]) {
            return (std::string*)strtok((char*)str.c_str(), del);
        }
    }
}