/* memory.h
 * * mocha::addressof()
 * * mocha::swap()
 * * mocha::memnull()
 * * mocha::memcpy()
 * * mocha::memset()
 * * mocha::memcmp()
 * * mocha::memtransfer()
 * * mocha::memlock()
 * * mocha::tuple()
 * * mocha::smart_ptr()
 * * mocha::shared_ptr()
 */
#pragma once
#define MOCHA_MEMORY true
#include "mocha.h"
#include "time.h"
namespace mocha {
    /* mocha::addressof()
     * * TEMPLATE: { "T": "Typename to Use" }
     * * "_alloc": "Variable to get address of"
     */
    template<typename T>
    const T* addressof(const T& _alloc) {
        return __builtin_addressof(_alloc);
    }

    /* mocha::swap()
     * * TYPENAME: { "T": "Typename to use" }
     * * "x": "To swap with "_y""
     * * "y": "To be swapped with "x""
     */
    template<typename T>
    void swap(T* x, T* y) {
        T t = *x;
        *x = *y;
        *y = t;
    }
    template<typename T>
    void swap(T& x, T& y) {
        T t = x;
        x = y;
        y = t;
    }

    /* mocha::memnull()
     * * TEMPLATE: { "T": "Typename to Use" }
     * OVERLOADS:
     * * "_obj": "Object to nullify"
     */
    template<typename T>
    T    memnull(             ) { return T{}; }
    template<typename T>
    void memnull(const T& _obj) { _obj = T{}; }

    /* mocha::memcpy() 
     * * TEMPLATE: { "T": "Typename to Use" }
     * * "_dest": "To copy "_src" into"
     * * "_src" : "To copy over to "_dest""
     * * "_from": "Where to start the copying from"
     * * "_to"  : "Where to end the copying"
     */
    template<typename T>
    void memcpy(T* _dest, const T* _src, const size_t _from, const size_t _to) {
        size_t i = _from;
        while (i <= _to) {
            _dest[i] = _src[i];
            i++;
        }
    }
    template<typename T>
    void memcpy(T* _dest, const T* _src, const size_t _to) {
        size_t i{};
        while (i <= _to) {
            _dest[i] = _src[i];
            i++;
        }
    }

    /* mocha::memset()
     * * TEMPLATE: { "T": "Typename to Use" }
     * * "_dest": "To copy "_src" into"
     * * "_src" : "To copy over to "_dest""
     * * "_from": "Where to start the copying from"
     * * "_to"  : "Where to end the copying"
     */
    template<typename T>
    void memset(T* _dest, const T _src, const size_t _from, const size_t _to) {
        size_t i = _from;
        while (i <= _to) {
            _dest[i] = _src;
            i++;
        }
    }
    template<typename T>
    void memset(T* _dest, const T _src, const size_t _to) {
        size_t i{};
        while (i <= _to) {
            _dest[i] = _src;
            i++;
        }
    }

    /* mocha::memcmp()
     * * TEMPLATE: { "T": "Typename to Use" }
     * * "_x"   : "To compare "_y" from"
     * * "_y"   : "To compare over to "_x""
     * * "_from": "Where to start the comparing from"
     * * "_to"  : "Where to end the comparing"
     */
    template<typename T>
    long memcmp(const T* _x, const T* _y, const size_t _from, const size_t _to) {
        /* <0 = first byte of _x is lower
         * 0  = first byte of _x is equal to _y
         * >0 = first byte of _x is greater
         */
        long ret{};
        for (long i = _from; i < _to; i++) {
            ret +=
            ((_x < _y) * *_y  +    // _x[i] is lesser than _y[i]  : returns <0 (if true)
             (_x > _y) * *_x) *    // _x[i] is greater than _y[i] : returns >0 (if true)
             (_x[i] != _y[i]);     // _x[i] is equal to _y[i]     : returns  0 (if true)
        }
        return ret;
    }
    template<typename T>
    long memcmp(const T* _x, const T* _y, const size_t _to) {
        long ret{};
        for (long i = 0; i < _to; i++) {
            ret +=
            ((_x < _y) * * _y  +    // _x[i] is lesser than _y[i]  : returns <0 (if true)
             (_x > _y) * * _x) *    // _x[i] is greater than _y[i] : returns >0 (if true)
             (_x[i] != _y[i]);      // _x[i] is equal to _y[i]     : returns  0 (if true)
        }
        return ret;
    }

    /* mocha::memtransfer()
     * * TEMPLATE: { "T": "Typename to Use" }
     * * "_dest": "To copy "_src" into"
     * * "_src" : "To copy over to "_dest""
     * * "_from": "Where to start the copying from"
     * * "_to"  : "Where to end the copying"
     */
    template<typename T>
    void memtransfer(T* _dest, T* _src, const size_t _from, const size_t _to) {
        T temp;
        for (int i = _from; i < _to; i++) {
            temp     = _src [i];
            _src [i] = _dest[i];
            _dest[i] = temp;
        }
    }
    template<typename T>
    void memtransfer(T* _dest, T* _src, const size_t _to) {
        T temp;
        for (int i = 0; i < _to; i++) {
            temp     = _src [i];
            _src [i] = _dest[i];
            _dest[i] = temp;
        }
    }

    /* mocha::memlock */
    template<typename T>
    struct memlock {
      protected:
        const T data;
        T* data_arr = new T[0];
        T& src;
      public:
        memlock() {}
        explicit memlock(T& _data)
            : data(_data),
              src (_data) 
        {
              src = T{};
        }
        explicit memlock(T& _data, const T _tmp)
            : data(_data),
              src (_data) 
        {
            src = _tmp;
        }
        explicit memlock(T* _data, const size_t _size, const size_t _tmp = T{})
            : data(*_data),
              src (*_data)
        {
            data_arr = new T[_size];
            size_t i{};
            while (i < _size) {
                data_arr[i] = _data[i];
                _data[i] = i;
                i++;
            }
        }
        ~memlock() {
            src = data;
            delete[] data_arr;
        }

        bool operator!=(const memlock& _data) const { return _data.data != this->data; }
        bool operator==(const memlock& _data) const { return _data.data == this->data; }
        bool operator> (const memlock& _data) const { return _data.data >  this->data; }
        bool operator>=(const memlock& _data) const { return _data.data >= this->data; }
        bool operator< (const memlock& _data) const { return _data.data <  this->data; }
        bool operator<=(const memlock& _data) const { return _data.data <= this->data; }

    };

    /* mocha::tuple */
    template<typename...>
    struct tuple;
    template<typename T1, typename T2>
    struct tuple<T1, T2> {
    private:
        T1 data1;
        T2 data2;
    public:
        tuple() {}
        explicit tuple(const T1 t) 
            : data1(t)
        { }
        explicit tuple(const T1 t1, const T2 t2)
            : data1(t1),
              data2(t2)
        { }
        
        void operator()(const T1 _x             ) { data1 = _x; }
        void operator()(const T1 _x, const T2 _y) { data1 = _x; data2 = _y; }

        T1& first =  data1;
        T2& second = data2;

        /* mocha::tuple::reverse() */
              mocha::tuple<T2, T1> reverse()       { return mocha::tuple<T2, T1>(data2, data1); }
        const mocha::tuple<T2, T1> reverse() const { return mocha::tuple<T2, T1>(data2, data1); }
    };
    template<typename T1, typename T2, typename T3>
    struct tuple<T1, T2, T3> {
    private:
        T1 data1{};
        T2 data2{};
        T3 data3{};
    public:
        tuple() {}
        explicit tuple(const T1 t)
            : data1(t)
        { }
        explicit tuple(const T1 t1, const T2 t2)
            : data1(t1),
              data2(t2) 
        { }
        explicit tuple(const T1 t1, const T2 t2, const T3 t3)
            : data1(t1),
              data2(t2),
              data3(t3)
        { }

        void operator()(const T1 _x                          ) { data1 = _x; }
        void operator()(const T1 _x, const T2 _y             ) { data1 = _x; data2 = _y; }
        void operator()(const T1 _x, const T2 _y, const T3 _z) { data1 = _x; data2 = _y; data3 = _z; }

        T1& first  = data1;
        T2& second = data2;
        T3& third  = data3;

        /* mocha::tuple::reverse() */
              mocha::tuple<T3, T2, T1> reverse()       { return mocha::tuple<T3, T2, T1>(data3, data2, data1); }
        const mocha::tuple<T3, T2, T1> reverse() const { return mocha::tuple<T3, T2, T1>(data3, data2, data1); }
    };

    /* mocha::smart_ptr */
    template<typename T>
    struct smart_ptr {
      private:
      protected:
        T* ptr;
      public:
        smart_ptr() {}
        explicit smart_ptr(T* _ptr) 
            : ptr(_ptr)
        {  }
        ~smart_ptr() { delete ptr; }
        void     null      (               )       noexcept {         ptr = nullptr; }
        const T* data      (               ) const noexcept { return  ptr; }
              T  operator* (               ) const          { return *ptr       ; }
              T* operator->(               ) const          { return  ptr       ; }
              T& operator+ (const size_t _i) const          { return  ptr +  _i ; }
        const T& operator[](const size_t _i) const          { return  ptr   [_i]; }
              T& operator[](const size_t _i)                { return  ptr   [_i]; }
        void     operator= (const T      _r)                {        *ptr =  _r ; }
        bool     operator==(const T      _r) const          { return  ptr == _r ; }
        bool     operator!=(const T      _r) const          { return  ptr != _r ; }
        bool     operator< (const T      _r) const          { return  ptr <  _r ; }
        bool     operator<=(const T      _r) const          { return  ptr <= _r ; }
        bool     operator> (const T      _r) const          { return  ptr >  _r ; }
        bool     operator>=(const T      _r) const          { return  ptr >= _r ; }
    };

    /* mocha::shared_ptr */
    template<typename T>
    class shared_ptr : public mocha::smart_ptr<T> {
      protected:
        const T* ptr = nullptr;
        mocha::shared_ptr<T>* parent = nullptr;
        mutable unsigned int count{};
      public:
                 shared_ptr() = default;
                 shared_ptr(const shared_ptr<T>&  _ptr);
        explicit shared_ptr(T*                    _ptr) 
            : ptr(_ptr)
        {}
        explicit shared_ptr(mocha::shared_ptr<T>& _ptr) 
            : ptr   (_ptr.ptr),
              parent(_ptr.parent),
              unique(false)
        {
            _ptr.count++;
        }
        const bool unique = true;
        const size_t& useCount() const { return count; }
    };

    /* mocha::shared_ptr */
    template<typename T>
    class timed_ptr : public mocha::smart_ptr<T> {
      protected:
        T* ptr = nullptr;
        time_t begint;
      public:
        timed_ptr() = default;
        explicit timed_ptr(T* _ptr)
            : ptr(_ptr)
        {
            this->start();
        }
        time_t start() { return begint = ::time(0); }
        time_t time () { return begint; }
    };
}