/* mocha.h
 * * mocha::size_t
 * * mocha::time_t
 * * mocha::size()
 * * mocha::exception()
 */
#pragma once
#define MOCHA true
namespace mocha {
    /* mocha::size_t */
    typedef unsigned int size_t;
    /* mocha::time_t */
    typedef __int64      time_t;

    /* mocha::size()
     * * NOTE: USE "MOCHA_SIZE()" FOR STACK DEFINED ARRAY
     * * "_arr": "Get size of"
     */
    #define MOCHA_SIZE(_arr) sizeof(_arr) / sizeof(*_arr)
    size_t size (const char* _arr) {
        size_t l{};
        while (_arr[l] != '\0') l++;
        return l;
    }   
    size_t bytes(const char* _arr) {
        return size(_arr) * sizeof(char);
    }

    #ifdef _ARRAY_
    template<typename T, const int l>
    size_t size(const std::array<T, l>& a) {
        return l;
    }
    template<typename T, const int l>
    size_t bytes(const std::array<T, l>& a) {
        return l * sizeof(T);
    }
    #ifdef _VECTOR_
    template<typename T>
    size_t size(const std::vector<T>& v) {
        return v.size();
    }
    template<typename T>
    size_t bytes(const std::vector<T>& v) {
        return v.size() * sizeof(T);
    }
    #endif
    #endif

    /* mocha::exception() */
    class exception {
      protected:
        static size_t iterations;
        const char*   what;
      public:
        exception(                ) = delete;
        exception(const exception&) noexcept { };
        explicit exception(const char* _what) 
            : what(_what) 
        { 
            #ifdef MOCHA_DEBUG
            printf("[mocha]: Exception created!\n");
            #endif
            iterations++; 
        };
        virtual ~exception();
        const char*    reason() { return what; }
        static size_t& amount() { return iterations; }
    };
}

mocha::size_t mocha::exception::iterations = 0;