#include "vect2.hpp"

vect2::vect2(int x, int y) : x(x), y(y) {}

vect2::vect2(const vect2& other) = default;

vect2& vect2::operator=(const vect2& other) = default;

int vect2::operator[](int index) const {
    return index == 0 ? x : y;
}

int& vect2::operator[](int index) {
    return index == 0 ? x : y;
}

vect2 vect2::operator-() const {
    return vect2(-x, -y);
}

vect2 vect2::operator*(int scalar) const {
    return vect2(x * scalar, y * scalar);
}

vect2& vect2::operator*=(int scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

vect2 vect2::operator+(const vect2& rhs) const {
    return vect2(x + rhs.x, y + rhs.y);
}

vect2 vect2::operator-(const vect2& rhs) const {
    return vect2(x - rhs.x, y - rhs.y);
}

vect2 vect2::operator*(const vect2& rhs) const {
    return vect2(x * rhs.x, y * rhs.y);
}

vect2& vect2::operator+=(const vect2& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

vect2& vect2::operator-=(const vect2& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

vect2& vect2::operator*=(const vect2& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

vect2& vect2::operator++() {
    ++x; ++y;
    return *this;
}

vect2 vect2::operator++(int) {
    vect2 temp(*this);
    ++(*this);
    return temp;
}

vect2& vect2::operator--() {
    --x; --y;
    return *this;
}

vect2 vect2::operator--(int) {
    vect2 temp(*this);
    --(*this);
    return temp;
}

bool vect2::operator==(const vect2& rhs) const {
    return x == rhs.x && y == rhs.y;
}

bool vect2::operator!=(const vect2& rhs) const {
    return !(*this == rhs);
}

vect2 operator*(int scalar, const vect2& v) {
    return v * scalar;
}

std::ostream& operator<<(std::ostream& os, const vect2& v) {
    return os << "{" << v[0] << ", " << v[1] << "}";
}
