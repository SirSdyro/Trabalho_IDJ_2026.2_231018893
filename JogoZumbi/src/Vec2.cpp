#include <Vec2.h>

Vec2::Vec2(){
    x = 0, y = 0;
}

Vec2::Vec2(float x, float y) {
    this->x = x, this->y = y;
}

Vec2 Vec2::operator+(const Vec2& v) const{
    return Vec2(x + v.x, y + v.y);
}

Vec2 Vec2::operator-(const Vec2& v) const{
    return Vec2(x - v.x, y - v.y);
}

Vec2 Vec2::operator*(float escalar) const{
    return Vec2(x*escalar, y*escalar);
}

Vec2& Vec2::operator+=(const Vec2& v){
    y += v.x;
    y += v.y;

    return *this;
}

Vec2& Vec2::operator-=(const Vec2& v){
    y -= v.x;
    y -= v.y;

    return *this;
}

float Vec2::magnitude() const {
    return sqrt(x * x + y * y);
}

Vec2 Vec2::normalized() const{
    float mag = magnitude();

    if(mag == 0){
        return Vec2(0,0);
    }

    return Vec2(x/mag, y/mag);
}

float Vec2::distance(const Vec2& v) const{
    return (*this - v).magnitude();
}

float Vec2::angle() const{
    return atan2(y, x);
}

Vec2 Vec2::rotated(float angle) const{
    float cosAngle = cos(angle);
    float sinAngle = sin(angle);

    return Vec2(x*cosAngle - y*sinAngle, y*cosAngle + x*sinAngle);
}