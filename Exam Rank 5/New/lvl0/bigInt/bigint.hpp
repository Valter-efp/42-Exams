#pragma once

#include <iostream>
#include <string>
#include <sstream>

class bigint {
private:
    std::string str; // Stores digits as string, most significant digit first

public:
    // Constructors
    bigint();                    // Default to "0"
    bigint(unsigned int num);   // From integer
    bigint(const bigint& other); // Copy constructor

    bigint& operator=(const bigint& other); // Copy assignment

    std::string getStr() const;

    // Arithmetic
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);
    bigint& operator++();     // Prefix
    bigint operator++(int);   // Postfix

    // Digit shift (base-10) with unsigned int
    bigint operator<<(unsigned int n) const;
    bigint operator>>(unsigned int n) const;
    bigint& operator<<=(unsigned int n);
    bigint& operator>>=(unsigned int n);

    // Digit shift (base-10) with bigint
    bigint operator<<(const bigint& other) const;
    bigint operator>>(const bigint& other) const;
    bigint& operator<<=(const bigint& other);
    bigint& operator>>=(const bigint& other);

    // Comparisons
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    bool operator<(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;
};

// Stream output
std::ostream& operator<<(std::ostream& os, const bigint& obj);
