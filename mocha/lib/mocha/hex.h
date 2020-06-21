/* hex.h
 * * mocha::hex
 */
#pragma once
#include "mocha.h"
#include "string/case.h"
namespace mocha {
    /* mocha::hexValues */
    const enum hexValues : unsigned int {
        A = 10,
        B = 11,
        C = 12,
        D = 13,
        E = 14,
        F = 15
    };
    /* mocha::hex */
    struct hex {
        // VARIABLES & FUNCTIONS
        const char* value;
        static const char* values;

        /* mocha::hex::decode */
        unsigned int decode() const {
            long ret = 0;
            int len = size();
            for (int i = 0; i < len; i++) {
                char* curr = (char*)strchr(this->values, value[i]);
                ret += ((long)curr) ? (long)(curr) : 0;
            }
            return ret;
        }
        const char* encode(const unsigned int l) const {
            char* buffer{};
            sprintf(buffer, "%X", l);
            return buffer;
        }

        /* mocha::hex::size() */
        size_t size() const {
            return mocha::size(value);
        }

        const char* add(const long l) {
            return encode(decode() + l);
        }

        // CONSTRUCTORS AND DESTRUCTORS

        template<typename T>
        void operator= (T             _val)       { this->value = (char*)_val;           }
        void operator= (std::string&  _val)       { this->value = (char*)(_val.c_str()); }
        void operator= (char          _val)       { this->value = &_val;                 }
        void operator= (mocha::hex&   _val)       { this->value = _val.value;            }

        long operator+ (const long       i) const { return decode() + i; }
        long operator- (const long       i) const { return decode() - i; }
        long operator* (const long       i) const { return decode() * i; }
        long operator/ (const long       i) const { return decode() / i; }


        #define mocha_hex_operator_func(op) unsigned int l = decode(); value = encode(l op)
        void operator+=(const long       i)       { mocha_hex_operator_func(+= i); }
        void operator-=(const long       i)       { mocha_hex_operator_func(-= i); }
        void operator*=(const long       i)       { mocha_hex_operator_func(*= i); }
        void operator/=(const long       i)       { mocha_hex_operator_func(/= i); }
        void operator++(                  )       { mocha_hex_operator_func(++); }
        void operator--(                  )       { mocha_hex_operator_func(--); }
        #undef mocha_hex_func

        hex(                              )       { value = (char*)"0"; }
        template<typename T>
        hex(T                            s)       { value = s; }
        hex(char                         c)       { value = &c; }
        hex(char*                        s)       { value = s; }
        hex(std::string&                 s)       { this->value = (char*)(s.c_str()); }
        hex(mocha::hex&                  h)       { this->value = h.value; }
    };
}

const char* mocha::hex::values = "0123456789ABCDEF";