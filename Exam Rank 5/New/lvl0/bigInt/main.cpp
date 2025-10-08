#include "bigint.hpp"
#include <iostream>
#include <sstream>
#include <string>

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

void check_result(const std::string& label, const bigint& actual, const std::string& expected) {
    std::ostringstream oss;
    oss << actual;
    if (oss.str() == expected)
        std::cout << GREEN << "[PASS] " << RESET << label << " is " << oss.str() << std::endl;
    else
        std::cout << RED << "[FAIL] " << RESET << label 
                  << " expected " << expected 
                  << " but got " << oss.str() << std::endl;
}

void check_bool(const std::string& label, bool actual, bool expected) {
    if (actual == expected)
        std::cout << GREEN << "[PASS] " << RESET << label << " is " << actual << std::endl;
    else
        std::cout << RED << "[FAIL] " << RESET << label 
                  << " expected " << expected 
                  << " but got " << actual << std::endl;
}

int main(void)
{
    const bigint a(42);
    bigint b(21), c, d(1337), e(d);

    // base test
    check_result("a", a, "42");
    check_result("b", b, "21");
    check_result("c", c, "0");
    check_result("d", d, "1337");
    check_result("e", e, "1337");

    check_result("a + b", a + b, "63");
    check_result("a + c", a + c, "42");
    check_result("c += a", (c += a), "42");

    check_result("b", b, "21");
    check_result("++b", ++b, "22");
    check_result("b++", b++, "22");
    check_result("b after b++", b, "23");

    // decimal append shifts
    check_result("(b << 10) + 42", (b << 10) + 42, "230000000042");
    check_result("(d <<= 4)", (d <<= 4), "13370000");
    check_result("(d >>= 2)", (d >>= (const bigint)2), "133700");

    check_result("a (again)", a, "42");
    check_result("d (after shifts)", d, "133700");

    check_bool("(d < a)", d < a, false);
    check_bool("(d > a)", d > a, true);
    check_bool("(d == d)", d == d, true);
    check_bool("(d != a)", d != a, true);
    check_bool("(d <= a)", d <= a, false);
    check_bool("(d >= a)", d >= a, true);

    // extra
    bigint x(12345678); bigint y(5);
    check_result("(x << y)", (x << y), "1234567800000");
    check_result("(x >>= y)", (x >>= y), "123");
    check_bool("(x >= y)", x >= y, true);

    check_result("x <<= 5", (x <<= 5), "12300000");
    check_result("y <<= 12", (y <<= 12), "5000000000000");
    check_bool("(x >= y)", x >= y, false);

    return 0;
}














































//Original main, mine has a visual validations

// #include "bigint.hpp"

// int main(void)
// {
// 	const bigint a(42);
// 	bigint b(21), c, d(1337), e(d);

// 	// base test
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "b = " << b << std::endl;
// 	std::cout << "c = " << c << std::endl;
// 	std::cout << "d = " << d << std::endl;
// 	std::cout << "e = " << e << std::endl;

// 	std::cout << "a + b = " << a + b << std::endl;
// 	std::cout << "a + c = " << a + c << std::endl;
// 	std::cout << "(c += a) = " << (c += a) << std::endl;

// 	std::cout << "b = " << b << std::endl;
// 	std::cout << "++b = " << ++b << std::endl;
// 	std::cout << "b++ = " << b++ << std::endl;

// 	// b = 23, b << 10 -> 23000000000 + 42 = 23000000042
// 	std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
// 	std::cout << "(d <<= 4) = " << (d <<= 4) << ", d: " << d << std::endl;
// 	std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << ", d: " << d << std::endl;

// 	std::cout << "a = " << a << std::endl; // a = 42
// 	std::cout << "d = " << d << std::endl; // d = 5348

// 	std::cout << "(d < a) = " << (d < a) << std::endl; // (d < a) = 0
// 	std::cout << "(d > a) = " << (d > a) << std::endl; // (d > a) = 1
// 	std::cout << "(d == d) = " << (d == d) << std::endl; // (d == d) = 1
// 	std::cout << "(d != a) = " << (d != a) << std::endl; // (d != a) = 1
// 	std::cout << "(d <= a) = " << (d <= a) << std::endl; // (d <= a) = 0
// 	std::cout << "(d >= a) = " << (d >= a) << std::endl; // (d >= a) = 1

// 	// extra
// 	bigint x(12345678); bigint y(5);
// 	std::cout << "(x << y) = " << (x << y) << ", x: " << x << ", y: " << y << std::endl;
// 	std::cout << "(x >>= y) = " << (x >>= y) << ", x: " << x << ", y: " << y << std::endl;
// 	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

// 	std::cout << "x= " << (x <<= 5) << ", y= " << (y <<= 12) << std::endl;
// 	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

// 	return (0);
// }
