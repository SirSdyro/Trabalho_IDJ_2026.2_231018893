#ifndef RECT_H
#define RECT_H

#include <Vec2.h>

class Rect {
    public:
        float x;
        float y;
        float w;
        float h;

        Rect();
        Rect(float x, float y, float w, float h);

        Vec2 center() const;

        float distance(const Rect& rect) const;

        bool contains(const Vec2& ponto) const;

        Rect operator+(const Vec2& v) const;
        Rect& operator+=(const Vec2& v);
};

#endif