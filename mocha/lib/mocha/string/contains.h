/* string/case.h
 * * mocha::lowercase();
 */
#pragma once
#include "../mocha.h"
#include <string>
#include <algorithm>
namespace mocha {
    namespace str {
        /* mocha::str::contains()
         * "str": String to check
         * "has": If "str" contains "has"
         */
        
        bool contains(const std::string str, const char* has) {
            return (str.find(has) != std::string::npos);
        }
        bool contains(const char* str, const char* has) {
            return contains(str, has);
        }
        bool contains(const std::string& str, const char* has) {
            return (str.find(has) != std::string::npos);
        }
        bool contains(const std::string& str, const std::string& has) {
            return (str.find(has) != std::string::npos);
        }
    }
}