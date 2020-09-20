/* string/join.h
 * * mocha::strjoin()
 */
#pragma once
#include "../mocha.h"
#include <sstream>
#include <vector>
namespace mocha {
    /* mocha::strjoin()
     * "strarr": Vector to join
     * "joinchar": Character to join with
     */
    std::string strjoin(std::vector<std::string> strarr, char joinchar) {
        std::stringstream ss;
        for (auto& s : strarr) {
            ss << s << joinchar;
        }
        return ss.str().substr(0, strarr.size() - 2);
    }
    std::string strjoin(std::vector<std::string>& strarr, char joinchar) {
        std::stringstream ss;
        for (auto& s : strarr) {
            ss << s << joinchar;
        }
        return ss.str().substr(0, strarr.size() - 2);
    }
}