/* string/case.h
 * * mocha::str::findAll
 */
#pragma once
#include "../mocha.h"
#include <string>
#include <vector>
#include <algorithm>
namespace mocha {
    namespace str {
        /* mocha::str::findAll
         * * "haystack": "String to look through"
         * * "needle": "String to find in "haystack""
         */
        size_t* findAll(std::string& haystack, std::string needle) {
            std::vector<size_t> starr;
            int foundItems = 0;
            for (int i = 0; i < (haystack.size() - needle.size()); i++) {
                if (haystack.substr(i, needle.size() - 2) == needle) {
                    starr.push_back(i);
                    foundItems++;
                }
            }
            return starr.data();
        }
        size_t* findAll(const char* haystack, const char* needle) {
            std::string h = haystack, n = needle;
            return findAll(h, n); 
        }
    }
}