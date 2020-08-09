Mocha is a C++ Library that is designed to be a light-weight standard library!
It includes numerous other additions such as:
>> **new**/**delete** operator allocating logged in the console.
>> 2D array class, with iterators.
>> 
>> and many more!
```cpp
#include <stdio.h>
#include <mocha/debug.h>
#include <mocha/array.h>

int main() {
    // bad 2d float array
    float fa[3][4] = {
        { 9.9f, 9.9f, 9.9f, 9.9f },
        { 9.9f, 9.9f, 9.9f, 9.9f },
        { 9.9f, 9.9f, 9.9f, 9.9f }
    };
    // mocha 2d (3x4) array (12 members)
    mocha::darray<float, 3, 4> da = fa
    for (int i = 0; i < 3; i++) 
    for (int j = 0; j < 4; j++) {
        da(i, j) = ((x * j) + j);
        printf("%f\n", da(i, j));
    }
}

```
