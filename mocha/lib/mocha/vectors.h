/* vectors.h
 * * mocha::basic_vector()
 * * mocha::vector2()
 * * mocha::vector3()
 */
#pragma once
#include "mocha.h"
namespace mocha {
    /* mocha::basic_vector */
    struct basic_vector {
        // VARIABLES & FUNCTIONS
        float x = 0.0f,
              y = 0.0f;
        // CONSTRUCTORS & DESTRUCTORS
        basic_vector() {}
        basic_vector(float x, float y) : x(x), y(y) {}
    };
    struct vector2 : basic_vector {
        // VARIABLES & FUNCTIONS

        // CONSTRUCTORS & DESTRUCTORS
        vector2(const float x, const float y) { this->x = x; this->y = y; }
        inline vector2 operator +(const vector2& v2) const { return vector2(x + v2.x, y + v2.y); }
        inline vector2 operator -(const vector2& v2) const { return vector2(x - v2.x, y - v2.y); }
        inline vector2 operator *(const vector2& v2) const { return vector2(x * v2.x, y * v2.y); }
        inline vector2 operator /(const vector2& v2) const { return vector2(x * v2.x, y * v2.y); }
        inline vector2 operator +(const float f)     const { return vector2(x + f   , y + f   ); }
        inline vector2 operator -(const float f)     const { return vector2(x - f   , y - f   ); }
        inline vector2 operator *(const float f)     const { return vector2(x * f   , y * f   ); }
        inline vector2 operator /(const float f)     const { return vector2(x * f   , y * f   ); }

        inline void operator =(const vector2& v2) { x = v2.x;  y = v2.y;  }
        inline void operator+=(const vector2& v2) { x += v2.x; y += v2.y; }
        inline void operator-=(const vector2& v2) { x -= v2.x; y -= v2.y; }
        inline void operator*=(const vector2& v2) { x *= v2.x; y *= v2.y; }
        inline void operator/=(const vector2& v2) { x /= v2.x; y /= v2.y; }
        inline void operator =(const float f)     { x = f;     y = f;     }
        inline void operator+=(const float f)     { x += f;    y += f;    }
        inline void operator-=(const float f)     { x -= f;    y -= f;    }
        inline void operator*=(const float f)     { x *= f;    y *= f;    }
        inline void operator/=(const float f)     { x /= f;    y /= f;    }

        inline bool operator==(const vector2& v2) const { return (x == v2.x && y == v2.y); }
        inline bool operator!=(const vector2& v2) const { return (x != v2.x && y != v2.y); }
        inline bool operator==(const float f)     const { return (x == f    && y == f   ); }
        inline bool operator!=(const float f)     const { return (x != f    && y != f   ); }
    };
    struct vector3 : basic_vector {
        // VARIABLES & FUNCTIONS
        float z = 0.0f;
        // CONSTRUCTORS & DESTRUCTORS
        vector3(float x, float y, float z) : z(z) { this->x = x; this->y = y; }
        inline vector3 operator +(const vector3& v3) const { return vector3(x + v3.x, y + v3.y, z + v3.z); }
        inline vector3 operator -(const vector3& v3) const { return vector3(x - v3.x, y - v3.y, z - v3.z); }
        inline vector3 operator *(const vector3& v3) const { return vector3(x * v3.x, y * v3.y, z * v3.z); }
        inline vector3 operator /(const vector3& v3) const { return vector3(x / v3.x, y / v3.y, z / v3.z); }
        inline vector3 operator +(const float f    ) const { return vector3(x + f   , y + f   , z + f   ); }
        inline vector3 operator -(const float f    ) const { return vector3(x - f   , y - f   , z - f   ); }
        inline vector3 operator *(const float f    ) const { return vector3(x * f   , y * f   , z * f   ); }
        inline vector3 operator /(const float f    ) const { return vector3(x / f   , y / f   , z / f   ); }

        inline void operator =(const vector3& v3) { x = v3.x;  y = v3.y;  z /= v3.z;}
        inline void operator+=(const vector3& v3) { x += v3.x; y += v3.y; z /= v3.z;}
        inline void operator-=(const vector3& v3) { x -= v3.x; y -= v3.y; z /= v3.z;}
        inline void operator*=(const vector3& v3) { x *= v3.x; y *= v3.y; z /= v3.z;}
        inline void operator/=(const vector3& v3) { x /= v3.x; y /= v3.y; z /= v3.z;}
        inline void operator =(const float f    ) { x = f;     y = f;     z /= f;}
        inline void operator+=(const float f    ) { x += f;    y += f;    z /= f; }
        inline void operator-=(const float f    ) { x -= f;    y -= f;    z /= f;}
        inline void operator*=(const float f    ) { x *= f;    y *= f;    z /= f;}
        inline void operator/=(const float f    ) { x /= f;    y /= f;    z /= f;}

        inline bool operator==(const vector3& v3) const { return (x == v3.x && y == v3.y && z == v3.z); }
        inline bool operator!=(const vector3& v3) const { return (x != v3.x && y != v3.y && z != v3.z); }
        inline bool operator==(const float f    ) const { return (x == f    && y == f    && z == f   ); }
        inline bool operator!=(const float f    ) const { return (x != f    && y != f    && z != f   ); }
    };
}