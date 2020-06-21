/* string/join.h
 * * mocha::str::join()
 */
#pragma once
#include "../mocha.h"
#include <sstream>
#include <string>
#include <vector>
namespace mocha {
    namespace str {
        /* mocha::str::join()
         * "strarr": Vector to join
         * "joinchar": Character to join with
         */
        std::string join(std::vector<std::string> strarr, char joinchar) {
            std::stringstream ss;
            for (auto& s : strarr) {
                ss << s << joinchar;
            }
            return ss.str().substr(0, strarr.size() - 2);
        }
        std::string join(std::vector<std::string>& strarr, char joinchar) {
            std::stringstream ss;
            for (auto& s : strarr) {
                ss << s << joinchar;
            }
            return ss.str().substr(0, strarr.size() - 2);
        }
    }
}