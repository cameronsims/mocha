/* iterator.h
 * * mocha::iterator()
 * * mocha::const_iterator()
 * * mocha::reverse_iterator()
 * * mocha::const_reverse_iterator()
 */
#pragma once
#include "mocha.h"
#define MOCHA_ITERATOR true
namespace mocha {
    /* mocha::iterator */
    template<typename T>
    class iterator {
      protected:
        T* content;
      public:
                 iterator(       ) 
            : content(nullptr)
        {}
        explicit iterator(T* _ptr)
            : content(_ptr)
        {}
        explicit iterator(T& _ptr)
            : content(&_ptr) 
        {}
                 iterator(MOCHA iterator<T>& _it)
            : content(_it.content) 
        {}
                 iterator(const MOCHA iterator<T>& _it)
            : content(_it.content)
        {}
        MOCHA iterator<T>&        operator++(                            )       { MOCHA iterator<T> it = *this; content++; return it; }
        MOCHA iterator<T>&        operator--(                            )       { MOCHA iterator<T> it = *this; content--; return it; }
        MOCHA iterator<T>         operator+ (size_t                    _i) const { return MOCHA iterator<T>(content +_i); }
        MOCHA iterator<T>         operator- (size_t                    _i) const { return MOCHA iterator<T>(content -_i); }
        MOCHA iterator<T>         operator+ (MOCHA iterator<T>&  const _r) const { return MOCHA iterator<T>(this->content + (&this->content - &_r.content)); }
        MOCHA iterator<T>         operator- (MOCHA iterator<T>&  const _r) const { return MOCHA iterator<T>(this->content - (&this->content - &_r.content)); }
        bool                      operator==(MOCHA iterator<T>   const _r) const { return this->content == _r.content; }
        bool                      operator!=(MOCHA iterator<T>   const _r) const { return this->content != _r.content; }
        bool                      operator<=(MOCHA iterator<T>   const _r) const { return this->content <= _r.content; }
        bool                      operator>=(MOCHA iterator<T>   const _r) const { return this->content >= _r.content; }
        bool                      operator< (MOCHA iterator<T>   const _r) const { return this->content <  _r.content; }
        bool                      operator> (MOCHA iterator<T>   const _r) const { return this->content >  _r.content; }

              T&                  operator* (                            )       { return *this->content; }
        const T&                  operator* (                            ) const { return *this->content; }
              T*                  operator->(                            )       { return  this->content; }
        const T*                  operator->(                            ) const { return  this->content; }
              T&                  operator[](const size_t              _i)       { return *(content + _i); }
        const T&                  operator[](const size_t              _i) const { return *(content + _i); }
                                                                      
        void                      operator= (T* const                  _i)       {        this->content = _i; }
        void                      operator+=(size_t                    _i)       { return this->content += _i; }
        void                      operator-=(size_t                    _i)       { return this->content -= _i; }
        void                      operator++(int                         )       {       *this->content++; }
        void                      operator--(int                         )       {       *this->content--; }
        size_t                      distance(MOCHA iterator<T>&& const _i) const { return abs(content - _i.content); }
        size_t                      distance(MOCHA iterator<T>&  const _i) const { return abs(content - _i.content); }
    };
    /* mocha::const_iterator */                                        
    template<typename T>
    class const_iterator {
      protected:
        T* const content;                                            
      public:                                                          
                 const_iterator() = delete;
        explicit const_iterator(const T* const _ptr)
            : content(_ptr)                                            
        {}   
        explicit const_iterator(T& _ptr)
            : content(&_ptr) 
        {}
                 const_iterator(const_iterator& _it) 
            : content(_it.content)
        {}
                 const_iterator(const MOCHA const_iterator<T>& _it)
            : content(_it.content) 
        {}
        ~const_iterator() = default;
        size_t                         distance  (MOCHA const_iterator<T>&&      _i) const { return abs(content - _i.content); }
        size_t                         distance  (MOCHA const_iterator<T>&       _i) const { return abs(content - _i.content); }
        const MOCHA const_iterator<T>& operator++(                                 )       { const  MOCHA const_iterator<T> it = *this; content++; return it; };
        const MOCHA const_iterator<T>& operator--(                                 )       { const  MOCHA const_iterator<T> it = *this; content--; return it; };
              MOCHA const_iterator<T>  operator+ (const size_t                   _i) const { return MOCHA const_iterator(content + _i); }
              MOCHA const_iterator<T>  operator- (const size_t                   _i) const { return MOCHA const_iterator(content - _i); }
        bool                           operator==(const MOCHA const_iterator<T>  _r) const { return this->content == _r.content; }
        bool                           operator!=(const MOCHA const_iterator<T>  _r) const { return this->content != _r.content; }
        bool                           operator<=(const MOCHA const_iterator<T>  _r) const { return this->content <= _r.content; }
        bool                           operator>=(const MOCHA const_iterator<T>  _r) const { return this->content >= _r.content; }
        bool                           operator< (const MOCHA const_iterator<T>  _r) const { return this->content <  _r.content; }
        bool                           operator> (const MOCHA const_iterator<T>  _r) const { return this->content >  _r.content; }

              T&                       operator* () { return *this->content; }
        const T&                       operator* () const { return *this->content; }
              T*                       operator->() { return  this->content; }
        const T*                       operator->() const { return  this->content; }
              T*                       operator& () { return &this->content; }
        const T*                       operator& () const { return &this->content; }
              T&                       operator[](const size_t             _i) { return *(content + _i); }
        const T&                       operator[](const size_t             _i) const { return *(content + _i); }

        void                           operator= (T* const                 _i) { this->content = _i; }
        void                           operator+=(size_t                   _i) { return  this->content += _i; }
        void                           operator-=(size_t                   _i) { return  this->content -= _i; }
        void                           operator++(int                        ) { *this->content++; }
        void                           operator--(int                        ) { *this->content--; }
    };
    /* mocha::reverse_iterator */
    template<typename T>
    class reverse_iterator {
      protected:
        T* content;
      public:
                 reverse_iterator()
              : content(nullptr) 
        {}
        explicit reverse_iterator(T* _ptr)
            : content(_ptr) 
        {}
        explicit reverse_iterator(T& _ptr)
            : content(&_ptr) 
        {}
                 reverse_iterator(MOCHA reverse_iterator<T> & _it)
            : content(_it.content) 
        {}
                 reverse_iterator(const MOCHA reverse_iterator<T>& _it)
            : content(_it.content) 
        {}
        MOCHA reverse_iterator<T>& operator++(                                    )       { MOCHA reverse_iterator<T> it = *this; content--; return it; }
        MOCHA reverse_iterator<T>& operator--(                                    )       { MOCHA reverse_iterator<T> it = *this; content++; return it; }
        MOCHA reverse_iterator<T>  operator+ (size_t                            _i) const { return MOCHA reverse_iterator<T>(content - _i); }
        MOCHA reverse_iterator<T>  operator- (size_t                            _i) const { return MOCHA reverse_iterator<T>(content + _i); }
        MOCHA reverse_iterator<T>  operator+ (MOCHA reverse_iterator<T>&  const _r) const { return MOCHA reverse_iterator<T>(this->content - (&this->content - &_r.content)); }
        MOCHA reverse_iterator<T>  operator- (MOCHA reverse_iterator<T>&  const _r) const { return MOCHA reverse_iterator<T>(this->content + (&this->content - &_r.content)); }
        bool                       operator==(MOCHA reverse_iterator<T>   const _r) const { return this->content == _r.content; }
        bool                       operator!=(MOCHA reverse_iterator<T>   const _r) const { return this->content != _r.content; }
        bool                       operator<=(MOCHA reverse_iterator<T>   const _r) const { return this->content >= _r.content; }
        bool                       operator>=(MOCHA reverse_iterator<T>   const _r) const { return this->content <= _r.content; }
        bool                       operator< (MOCHA reverse_iterator<T>   const _r) const { return this->content >  _r.content; }
        bool                       operator> (MOCHA reverse_iterator<T>   const _r) const { return this->content <  _r.content; }
                                   
              T&                   operator* (                                    )       { return *this->content; }
        const T&                   operator* (                                    ) const { return *this->content; }
              T*                   operator->(                                    )       { return  this->content; }
        const T*                   operator->(                                    ) const { return  this->content; }
              T&                   operator[](const size_t                      _i)       { return *(content - _i); }
        const T&                   operator[](const size_t                      _i) const { return *(content - _i); }
                                                                                
        void                       operator= (T* const                          _i)       {        this->content = _i; }
        void                       operator+=(size_t                            _i)       { return this->content -= _i; }
        void                       operator-=(size_t                            _i)       { return this->content += _i; }
        void                       operator++(int                                 )       {       *this->content--; }
        void                       operator--(int                                 )       {       *this->content++; }
        size_t                       distance(MOCHA reverse_iterator<T>&& const _i) const { return abs(content - _i.content); }
        size_t                       distance(MOCHA reverse_iterator<T>&  const _i) const { return abs(content - _i.content); }
    };
    /* mocha::const_reverse_iterator */
    template<typename T>
    class const_reverse_iterator : public virtual MOCHA const_iterator<T> {
      protected:
        T* const content;
      public:
                 const_reverse_iterator() = delete;
        explicit const_reverse_iterator(T* _ptr)
            : content(_ptr) 
        {}
        explicit const_reverse_iterator(T& _ptr)
            : content(&_ptr) 
        {}
                 const_reverse_iterator(const_reverse_iterator<T>& _it)
            : content(_it.content) 
        {}
                 const_reverse_iterator(const MOCHA const_reverse_iterator<T>& _it)
            : content(_it.content) 
        {}
        size_t                           distance(MOCHA const_reverse_iterator<T>&& _i) const { return abs(content - _i.content); }
        size_t                           distance(MOCHA const_reverse_iterator<T>&  _i) const { return abs(content - _i.content); }
        MOCHA const_reverse_iterator<T>& operator++(                                  )       { MOCHA const_reverse_iterator<T> it = *this; this->content--; return it; }
        MOCHA const_reverse_iterator<T>& operator--(                                  )       { MOCHA const_reverse_iterator<T> it = *this; this->content++; return it; }
        MOCHA const_reverse_iterator<T>  operator+ (size_t                          _i) const { return MOCHA const_reverse_iterator<T>(content - _i); }
        MOCHA const_reverse_iterator<T>  operator- (size_t                          _i) const { return MOCHA const_reverse_iterator<T>(content + _i); }

        const T&                         operator[](const size_t                    _i) const { return *(content - _i); }

        void                             operator++(int                               )       { *this->content--; }
        void                             operator--(int                               )       { *this->content++; }
        void                             operator+=(size_t                          _i)       { return content -= _i; }
        void                             operator-=(size_t                          _i)       { return content += _i; }
        
    };

    template<typename T, class IT>
    void iter_swap(IT& _l, IT& _r) {
        T temp = *_l;
        *_l = *_r;
        *_r = temp;
    };
}