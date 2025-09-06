#pragma once

#include <sstream>
#include <string>
#include <iostream>

class bigint{
    private:
        std::string str;
    public:
        bigint();
        bigint(unsigned int num);
        bigint(const bigint &other);
        bigint &operator=(const bigint &other);

        std::string getStr()const;

        // --- Arithmetic ---
        bigint operator+(const bigint &other)const;
        bigint &operator+=(const bigint &other);
        bigint &operator++();
        bigint operator++(int);

        // --- Shifting (with unsigned int) ---
        bigint operator<<(unsigned int n)const;
        bigint operator>>(unsigned int n)const;
        bigint &operator<<=(unsigned int n);
        bigint &operator>>=(unsigned int n);

        // --- Shifting (with bigint) ---
        bigint operator<<(const bigint &other)const;
        bigint operator>>(const bigint &other)const;
        bigint &operator<<=(const bigint &other);
        bigint &operator>>=(const bigint &other);

        // --- Comparisons ---
        bool operator==(const bigint &other)const;
        bool operator!=(const bigint &other)const;
        bool operator<(const bigint &other)const;
        bool operator>(const bigint &other)const;
        bool operator<=(const bigint &other)const;
        bool operator>=(const bigint &other)const;
};

// --- Output stream ---
std::ostream &operator<<(std::ostream &os, const bigint &obj);
