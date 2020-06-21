/* file.h
 * * mocha::file
 */
#pragma once
#include "mocha.h"
#include <string>
#include <fstream>
namespace mocha {
    /* mocha::file */
    class file {
        #define mocha_file_struct std::ifstream
        file() { }
        const char* directory;
        mocha_file_struct* stream;
      public:
        file(const char*  dir) : directory(dir)         { stream = new mocha_file_struct(dir); }
        file(std::string  dir) : directory(dir.c_str()) { stream = new mocha_file_struct(dir); }
        file(std::string& dir) : directory(dir.c_str()) { stream = new mocha_file_struct(dir); }

        /* mocha::file::contents() */
        mocha_file_struct contents() const { return mocha_file_struct(directory); }
        /* mocha::file::size() */
        std::streampos    size()     const { return mocha_file_struct(directory).tellg(); }
        #undef mocha_file_struct
    };
}