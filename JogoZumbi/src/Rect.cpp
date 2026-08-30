#include <Rect.h>

Rect::Rect(){
    x = 0, y = 0, w = 0, h = 0;
}

Rect::Rect(float x, float y, float w, float h){
    this->x = x, this->y = y, this->w = w, this->h = h;
}

Vec2 Rect::center() const{
    return Vec2(x + w/2, y + h/2);
}

float Rect::distance(const Rect& rect) const{
    return center().distance(rect.center());
}

bool Rect::contains(const Vec2& ponto) const{
    return ponto.x >= x && 
           ponto.x <= x+w && 
           ponto.y >= y && 
           ponto.y <= y+h;
}

Rect Rect::operator+(const Vec2& v) const{
    return Rect(x + v.x, y + v.y, w, h);
}

Rect& Rect::operator+=(const Vec2& v){
    x += v.x;
    y += v.y;

    return *this;
}