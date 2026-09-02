#ifndef VEC2_H
#define VEC2_H

#include <cmath>
using namespace std;

class Vec2{
    public:
        float x;
        float y;

        Vec2();
        Vec2(float x, float y);

        Vec2 operator+(const Vec2& v) const;
        Vec2 operator-(const Vec2& v) const;
        Vec2 operator*(float escalar) const;

        Vec2& operator+=(const Vec2& v);
        Vec2& operator-=(const Vec2& v);

        float magnitude() const;
        Vec2 normalized() const;

        float distance(const Vec2& v) const;
        float angle() const;

        Vec2 rotated(float angle) const;
};

#endif