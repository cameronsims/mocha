/* iterator.h
 * * mocha::iterator()
 * * mocha::const_iterator()
 */
#pragma once
#include "mocha.h"
#define MOCHA_ITERATOR true
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
        explicit iterator(T& _ptr)
            : content(&_ptr) 
        {}
        iterator(iterator<T>& _it)
            : content(_it.content) 
        {}
        ~iterator() = default;
        T&                        operator* (                                 ) const { return *content; }
        T*                        operator->(                                 ) const { return  content; }
        MOCHA iterator<T>&        operator++(                                 )       { MOCHA iterator<T> it = *this; content++; return it; }
        MOCHA iterator<T>&        operator--(                                 )       { MOCHA iterator<T> it = *this; content++; return it; }
        void                      operator++(int                              )       {                        *content++; }
        void                      operator--(int                              )       {                        *content++; }
        MOCHA iterator<T>         operator+ (size_t                         _i) const { return (*this +_i); }
        MOCHA iterator<T>         operator- (size_t                         _i) const { return (*this -_i); }
        void                      operator+=(size_t                         _i)       { return   content += _i; }
        void                      operator-=(size_t                         _i)       { return   content -= _i; }
        template<typename Tt>                                                        
        void                      operator= (Tt                            _i)       { ( content) =   &_i; }
        bool                      operator==(const MOCHA iterator<T>&      _r) const { return (*content) == (*_r); }
        bool                      operator!=(const MOCHA iterator<T>&      _r) const { return (*content) != (*_r); } 
        bool                      operator<=(const MOCHA iterator<T>&      _r) const { return (*content) <= (*_r); }
        bool                      operator>=(const MOCHA iterator<T>&      _r) const { return (*content) >= (*_r); }
        bool                      operator< (const MOCHA iterator<T>&      _r) const { return (*content) <  (*_r); }
        bool                      operator> (const MOCHA iterator<T>&      _r) const { return (*content) >  (*_r); }
    };                                                                 
    /* mocha::const_iterator */                                        
    template<typename T>
    struct const_iterator {
      protected:
        T* const content;                                            
      public:                                                          
        const_iterator() = default;                                    
        const_iterator(const T* const _ptr)                                  
            : content(_ptr)                                            
        {}   
        const_iterator(const_iterator& _it) 
            : content(_it.content)
        {}
        ~const_iterator() = default;                                 
        const T&                       operator* (                                 ) const { return *content; };
        const T*                       operator->(                                 ) const { return content; }
        const MOCHA const_iterator<T>& operator++(                                 )       { T i = *this; content++; return *this; };
        const MOCHA const_iterator<T>  operator++(int                              )       {             *content++; return *this; };
        const MOCHA const_iterator<T>& operator--(                                 )       { T i = *this; content--; return *this; };
        const MOCHA const_iterator<T>  operator--(int                              )       {             *content--; return *this; };
        const MOCHA const_iterator<T>  operator+ (const size_t                   _i) const { return MOCHA const_iterator<T>(*this + _i); }
        const MOCHA const_iterator<T>  operator- (const size_t                   _i) const { return MOCHA const_iterator<T>(*this - _i); }
        void                           operator+=(const size_t                   _i)       { return  content += _i; }
        void                           operator-=(const size_t                   _i)       { return  content -= _i; }
        bool                           operator==(const MOCHA const_iterator<T>& _r) const { return (*content) == (*_r); }
        bool                           operator!=(const MOCHA const_iterator<T>& _r) const { return (*content) != (*_r); }
        bool                           operator<=(const MOCHA const_iterator<T>& _r) const { return (*content) <= (*_r); }
        bool                           operator>=(const MOCHA const_iterator<T>& _r) const { return (*content) >= (*_r); }
        bool                           operator< (const MOCHA const_iterator<T>& _r) const { return (*content) <  (*_r); }
        bool                           operator> (const MOCHA const_iterator<T>& _r) const { return (*content) >  (*_r); }
    };
}