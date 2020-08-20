/* iterator.h
 * * mocha::iterator()
 * * mocha::const_iterator()
 */
#pragma once
#include "mocha.h"
#define MOCHA_ARRAY
namespace mocha {
    /* mocha::iterator */
    template<typename T>
    struct iterator {
      protected:                                                         
        T* content;
      public:
        iterator() = default;
        explicit iterator(T* _ptr)
            : content(_ptr) 
        {}
        ~iterator() = default;

        T                         operator* (                                 )       { return *content; };
        T*                        operator->(                                 )       { return content; }
        mocha::iterator<T>&       operator++(                                 )       { content++; return *this; };
        mocha::iterator<T>        operator++(int                              )       { content++; return *this; };
        mocha::iterator<T>&       operator--(                                 )       { content--; return *this; };
        mocha::iterator<T>        operator--(int                              )       { content--; return *this; };
        mocha::iterator<T>        operator+ (size_t                         _i)       { return mocha::iterator<T>(*this +_i); }
        mocha::iterator<T>        operator- (size_t                         _i)       { return mocha::iterator<T>(*this -_i); }
        void                      operator+=(size_t                         _i)       { return  content += _i; }
        void                      operator-=(size_t                         _i)       { return  content -= _i; }
        bool                      operator==(mocha::iterator<T>&            _r)       { return *content == *_r; };
        bool                      operator!=(mocha::iterator<T>&            _r)       { return *content != *_r; };
        bool                      operator==(T                              _r)       { return *content == _r; };
        bool                      operator!=(T                              _r)       { return *content != _r; };                                             
    };                                                                 
    /* mocha::const_iterator */                                        
    template<typename T>
    struct const_iterator {
      protected:
        T* content;                                            
      public:                                                          
        const_iterator() = default;                                    
        const_iterator(const T* _ptr)                                  
            : content(_ptr)                                            
        {}                                                             
        ~const_iterator() = default;                                   
                                                                       
        const T                         operator* (                           ) const { return *content; };
        const T*                        operator->(                           ) const { return content; }
        const const_iterator<T>&        operator++(                           )       { T i = *this; content++; return *this; };
        const const_iterator<T>         operator++(int                        )       {              content++; return *this; };
        const mocha::const_iterator<T>& operator--(                           )       { T i = *this; content--; return *this; };
        const mocha::const_iterator<T>  operator--(int                        )       {              content--; return *this; };
        const mocha::const_iterator<T>  operator+ (const size_t             _i) const { return mocha::const_iterator<T>(*this + _i); }
        const mocha::const_iterator<T>  operator- (const size_t             _i) const { return mocha::const_iterator<T>(*this - _i); }
        void                            operator+=(const size_t             _i)       { return  content += _i; }
        void                            operator-=(const size_t             _i)       { return  content -= _i; }
        bool                            operator==(const iterator<T>&       _r) const { return *content == *_r; };
        bool                            operator!=(const iterator<T>&       _r) const { return *content != *_r; };
        bool                            operator==(const const_iterator<T>& _r) const { return *content == *_r; };
        bool                            operator!=(const const_iterator<T>& _r) const { return *content != *_r; };
        bool                            operator==(const T                  _r) const { return *content == _r; };
        bool                            operator!=(const T                  _r) const { return *content != _r; };
    };
}