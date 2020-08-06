/* string/case.h
 * * mocha::str::lowercase();
 * * mocha::str::uppercase();
 */
#pragma once
#include "../mocha.h"
#include "../generic/string.h"
namespace mocha {
    /* mocha::lowercase() */
    /*std::string lowercase(const char* s) {
        std::string str = s;
        return lowercase(s);
    }*/
    /* mocha::lowercase() */
    std::string lowercase(const std::string& s) {
        std::string str = s;
        std::transform(str.begin(), str.end(), str.begin(), [&](unsigned char c) { return std::tolower(c); });
        return str;
    }
    /* mocha::uppercase() */
    /*std::string uppercase(const char* s) {
        std::string str = s;
        return uppercase(str);
    }*/
    /* mocha::uppercase() */
    std::string uppercase(const std::string& s) {
        std::string str = s;
        std::transform(str.begin(), str.end(), str.begin(), [&](unsigned char c) { return std::toupper(c); });
        return str;
    }
}