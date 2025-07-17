#include "bigint.hpp"
#include <sstream> // For ostringstream
#include <algorithm> // For reverse

// Constructors
bigint::bigint() : digits("0") {}

bigint::bigint(unsigned int num) {
    std::ostringstream oss;
    oss << num; // Convert number to string
    digits = oss.str();
    std::reverse(digits.begin(), digits.end()); // Reverse to make it "least significant digit first"
}

bigint::bigint(const std::string& str) {
    if (str.empty() || !std::all_of(str.begin(), str.end(), ::isdigit)) {
        digits = "0";
    } else {
        digits = str;
        std::reverse(digits.begin(), digits.end()); // Reverse for internal storage
        removeLeadingZeros();
    }
}

// Private helper: Add two reversed-digit strings
std::string bigint::addStrings(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0, sum = 0;
    size_t len = std::max(a.size(), b.size());

    for (size_t i = 0; i < len; ++i) {
        int digitA = i < a.size() ? a[i] - '0' : 0;
        int digitB = i < b.size() ? b[i] - '0' : 0;
        sum = digitA + digitB + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    if (carry) result.push_back(carry + '0');
    return result;
}

void bigint::removeLeadingZeros() {
    while (digits.size() > 1 && digits.back() == '0') {
        digits.pop_back();
    }
}

// Addition operators
bigint bigint::operator+(const bigint& other) const {
    bigint result;
    result.digits = addStrings(this->digits, other.digits);
    return result;
}

bigint& bigint::operator+=(const bigint& other) {
    *this = *this + other;
    return *this;
}

// Comparison operators
bool bigint::operator==(const bigint& other) const {
    return this->digits == other.digits;
}

bool bigint::operator!=(const bigint& other) const {
    return !(*this == other);
}

bool bigint::operator<(const bigint& other) const {
    if (this->digits.size() != other.digits.size()) 
        return this->digits.size() < other.digits.size();
    return std::lexicographical_compare(this->digits.rbegin(), this->digits.rend(),
                                        other.digits.rbegin(), other.digits.rend());
}

bool bigint::operator>(const bigint& other) const {
    return other < *this;
}

bool bigint::operator<=(const bigint& other) const {
    return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const {
    return !(*this < other);
}

// Digit shift operators
bigint bigint::operator<<(unsigned int shift) const {
    if (*this == 0) return *this;
    bigint result = *this;
    result.digits.insert(result.digits.begin(), shift, '0');
    return result;
}

bigint bigint::operator>>(unsigned int shift) const {
    if (shift >= digits.size()) return bigint(0);
    bigint result = *this;
    result.digits.erase(result.digits.begin(), result.digits.begin() + shift);
    result.removeLeadingZeros();
    return result;
}

std::string bigint::getDigits(void) const
{
	return (this->digits);
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const bigint& num) {
    std::string str(num.getDigits());
    std::reverse(str.begin(), str.end());
    os << str;
    return os;
}




///This is a test main! not part of the exercise
void print_test(const std::string &desc, const bigint &value, const std::string &expected) {
	std::cout << desc << "\n";
	std::cout << "Expected: " << expected << "\n";
	std::cout << "Actual  : " << value << "\n";
	std::cout << (value.getDigits() == std::string(expected.rbegin(), expected.rend()) ? "✅ PASS" : "❌ FAIL") << "\n\n";
}

int main() {
	// Constructor tests
	bigint a(0);
	bigint b(12345);
	bigint c("987654321");
	bigint invalid("12a3"); // should default to 0

	print_test("Construct from 0", a, "0");
	print_test("Construct from 12345", b, "12345");
	print_test("Construct from string \"987654321\"", c, "987654321");
	print_test("Construct from invalid string \"12a3\"", invalid, "0");

	// Addition
	bigint d = bigint("999999999999999999") + bigint("1");
	print_test("Addition: 999999999999999999 + 1", d, "1000000000000000000");

	bigint e("12345");
	e += bigint("55");
	print_test("Addition with += : 12345 += 55", e, "12400");

	// Comparisons
	bigint x("123456789");
	bigint y("987654321");

	std::cout << "Comparisons:\n";
	std::cout << "123456789 == 123456789 → " << (x == bigint("123456789") ? "✅ PASS" : "❌ FAIL") << "\n";
	std::cout << "123456789 != 987654321 → " << (x != y ? "✅ PASS" : "❌ FAIL") << "\n";
	std::cout << "123456789 < 987654321  → " << (x < y ? "✅ PASS" : "❌ FAIL") << "\n";
	std::cout << "987654321 > 123456789  → " << (y > x ? "✅ PASS" : "❌ FAIL") << "\n";
	std::cout << "123456789 <= 123456789 → " << (x <= x ? "✅ PASS" : "❌ FAIL") << "\n";
	std::cout << "987654321 >= 123456789 → " << (y >= x ? "✅ PASS" : "❌ FAIL") << "\n\n";

	// Shift Left
	bigint shiftLeft("42");
	bigint sl = shiftLeft << 3; // Expected 42000
	print_test("Shift left: 42 << 3", sl, "42000");

	// Shift Right
	bigint shiftRight("1337");
	bigint sr = shiftRight >> 2; // Expected 13
	print_test("Shift right: 1337 >> 2", sr, "13");

	// Shift edge case
	bigint shiftMax("999");
	bigint sr2 = shiftMax >> 5; // All digits gone => 0
	print_test("Shift right overflow: 999 >> 5", sr2, "0");

	return 0;
}
