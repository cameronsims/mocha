/* mocha.h
 * * mocha::endl
 * * mocha::size()
 */
#pragma once
namespace mocha {
    static constexpr char endl = '\n';

    /* mocha::size()
     * * NOTE: ARRAY MUST BE DEFINED IN STACK TO WORK PROPERLY
     * * TEMPLATE: { "T": "Typename to use" }
     * * "arr": "Get size of"
     */
    #define MOCHA_SIZE(_arr) sizeof(_arr) / sizeof(*_arr)
    template<typename T>
    size_t size(const T arr[]) {
        return MOCHA_SIZE(arr);
    }
    size_t size(const char* arr) {
        int l{};
        while (arr[l] != '\0') l++;
        return l;
    }
}