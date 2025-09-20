#pragma once
#include <iostream>

class vect2{
    private:
        int x, y;
    public:
        vect2(int x = 0, int y = 0);
        vect2(const vect2 &other);
        vect2 &operator=(const vect2 &other);
        ~vect2();

        int operator[](int index)const;
        int &operator[](int index);

        vect2 operator-();
        vect2 operator*(int scalar)const;
        vect2 &operator*=(int scalar);

        vect2 operator+(const vect2 &other)const;
        vect2 operator-(const vect2 &other)const;
        vect2 operator*(const vect2 &other)const;

        vect2 &operator+=(const vect2 &other);
        vect2 &operator-=(const vect2 &other);
        vect2 &operator*=(const vect2 &other);

        vect2 &operator++();
        vect2 operator++(int);
        vect2 &operator--();
        vect2 operator--(int);

        bool operator==(const vect2 &other)const;
        bool operator!=(const vect2 &other)const;
};

vect2 operator*(int scalar, const vect2 &v);
std::ostream &operator<<(std::ostream &os, const vect2 &v);