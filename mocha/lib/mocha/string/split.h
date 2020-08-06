/* string/split.h
 * * mocha::strsplit()
 */
#pragma once
#include "../mocha.h"
#include "../generic/string.h"
namespace mocha {
    /* mocha::strsplit()
     * * "str": String to split
     * * "del": Character to delimate
     */
    const char* strsplit(const char* str, char del[]) {
        return strtok((char*)str, del);
    }
    std::string* strsplit(std::string& str, char del[]) {
        return (std::string*)strtok((char*)str.c_str(), del);
    }
}