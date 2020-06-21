/* console.h
 * * mocha::cout_client
 * * mocha::cin_client
 * *
 * *
 * *
 * *
 */
#pragma once
#include "mocha.h"
#include <stdio.h>
#include <string>
namespace mocha {
    /* mocha::cout_client */
    class cout_client {
      protected:
        /* mocha::cout_client
         * * TEMPLATE: { "T": "Typename to use" }
         * * "_subject": "Object to print"
         */
        template<typename T>
        void log(const T& _subject) const {
            printf((char*)_subject); 
        }
      public:
        template<typename T>
        cout_client& operator<<(const T             i) { log(i); return *this; }
        cout_client& operator<<(const char*         c) { log(c); return *this; }
        cout_client& operator<<(std::string         s) { log(s.c_str()); return *this; }
        cout_client& operator<<(const cout_client   c) { return *this; }
        cout_client& operator<<(const cerr_client   c) { return *this; }
        cout_client& operator<<(const cwarn_client  c) { return *this; }

        template<typename T>
        cout_client& operator()(const T           i) { log(i);            return *this; }
        cout_client& operator()(const char*       c) { printf(c);         return *this; }
        cout_client& operator()(const std::string s) { printf(s.c_str()); return *this; }
    };
    /* mocha::cin_client */
    class cin_client {
      public:
        /* mocha::cout_client */
        const char* get() const {
            char* ret;
            scanf("%s", ret);
            return ret;
        }

        template<typename T>
        void operator>>(T& var)           { var = (T)get(); }
        void operator>>(std::string& var) { var = get(); }
    };
    /* mocha::cerr_client */
    class cerr_client : cout_client {
        template<typename T>
        void err(const T& _subject) {
            printf("[ERROR]: " + (char*)_subject);
        }
    public:
        template<typename T>
        cerr_client& operator<<(const T             i) { err(i); return *this; }
        cerr_client& operator<<(const char*         c) { err(c); return *this; }
        cerr_client& operator<<(const std::string   s) { err(s.c_str()); return *this; }
        cerr_client& operator<<(const cout_client   c) { return *this; }
        cerr_client& operator<<(const cerr_client   c) { return *this; }
        cerr_client& operator<<(const cwarn_client  c) { return *this; }

        template<typename T>
        cerr_client& operator()(const T            i) { err(i); return *this; }
        cerr_client& operator()(const char*        c) { err(c); return *this; }
        cerr_client& operator()(const std::string  s) { err(s); return *this; }
    };
    /* mocha::warn_client */
    class cwarn_client : cout_client {
        template<typename T>
        void warn(const T& _subject) {
            printf("[WARNING]: " + (char*)_subject);
        }
    public:
        template<typename T>
        cwarn_client& operator<<(const T             i) { warn(i); return *this; }
        cwarn_client& operator<<(const char*         c) { warn(c); return *this; }
        cwarn_client& operator<<(const std::string   s) { warn(s.c_str()); return *this; }
        cwarn_client& operator<<(const cout_client   c) { return *this; }
        cwarn_client& operator<<(const cerr_client   c) { return *this; }
        cwarn_client& operator<<(const cwarn_client  c) { return *this; }

        template<typename T>
        cwarn_client& operator()(const T            i) { warn(i); return *this; }
        cwarn_client& operator()(const char*        c) { warn(c); return *this; }
        cwarn_client& operator()(const std::string  s) { warn(s); return *this; }
    };

    /* Console Output */
    cout_client  clog;
    /* Console Input */
    cin_client   cin;
    /* Console Error Output */
    cerr_client  cerr;
    /* Console Error Output */
    cwarn_client cwarn;
}