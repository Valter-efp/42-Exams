#include "bigint.hpp"

bigint::bigint() : str("0"){}

bigint::bigint(unsigned int num){
    std::ostringstream oss;
    oss << num;
    str = oss.str();
}

bigint::bigint(const bigint &other) = default;

bigint& bigint::operator=(const bigint& other) = default;

std::string bigint::getStr()const{
    return str;
}

// --- Utility ---
static std::string reverse(const std::string &s){
    return std::string(s.rbegin(), s.rend());
}

static std::string add_strings(const std::string &a, const std::string &b){
    std::string result;
    int carry = 0, sum;
    size_t i = 0, len = std::max(a.length(), b.length());

    while(i < len || carry){
        int digits_a = (i < a.length()) ? a[a.length() - 1 - i] - '0' : 0;
        int digits_b = (i < b.length()) ? b[b.length() - 1 - i] - '0' : 0;
        sum = digits_a + digits_b + carry;
        carry = sum / 10;
        result.push_back((sum %10) + '0');
        i++;
    }

    while(result.length() > 1 && result.back() == '0')
        result.pop_back();
    return reverse(result);
}

// --- Arithmetic ---
bigint bigint::operator+(const bigint &other)const{
    bigint temp;
    temp.str = add_strings(this->str, other.str);
    return temp;
}

bigint &bigint::operator+=(const bigint &other){
    *this = *this + other;
    return *this;
}

bigint &bigint::operator++(){
    return (*this += bigint(1));
}

bigint bigint::operator++(int){
    bigint temp(*this);
    ++(*this);
    return temp;
}

// --- Shifting (with unsigned int) ---
bigint bigint::operator<<(unsigned int n)const{
    if(*this == bigint(0))
        return *this;
    bigint temp(*this);
    temp.str.append(n, '0');
    return temp;
}

bigint bigint::operator>>(unsigned int n)const{
    if(*this == bigint(0))
        return *this;
    bigint temp(*this);
    temp.str.erase(str.size() - n);
    return temp;
}

bigint &bigint::operator<<=(unsigned int n){
    *this = *this << n;
    return *this;
}

bigint &bigint::operator>>=(unsigned int n){
    *this = * this >> n;
    return *this;
}

// --- Shifting (with bigint) ---
static unsigned int to_uint(const std::string &s){
    return static_cast<unsigned int>(std::stoul(s));
}

bigint bigint::operator<<(const bigint &other)const{
    return *this << to_uint(other.str);
}

bigint bigint::operator>>(const bigint &other)const{
    return *this >> to_uint(other.str);
}

bigint &bigint::operator<<=(const bigint &other){
    *this = *this << to_uint(other.str);
    return *this;
}

bigint &bigint::operator>>=(const bigint &other){
    *this = *this >> to_uint(other.str);
    return *this;
}

// --- Comparisons ---
bool bigint::operator==(const bigint &other)const{
    return this->str == other.str;
}

bool bigint::operator!=(const bigint &other)const{
    return !(this == &other);
}

bool bigint::operator<(const bigint &other)const{
    if(str.size() != other.str.size())
        return str.size() < other.str.size();
    return str < other.str;
}

bool bigint::operator>(const bigint &other)const{
    return other < *this;
}

bool bigint::operator<=(const bigint &other)const{
    return !(*this > other);
}

bool bigint::operator>=(const bigint &other)const{
    return !(*this < other);
}

// --- Output stream ---
std::ostream &operator<<(std::ostream &os, const bigint &obj){
    os << obj.getStr();
    return os;
}
