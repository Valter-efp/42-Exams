#include "vect2.hpp"
#include <iostream>

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

void check_result(const std::string& label, const vect2& actual, const vect2& expected) {
    if (actual == expected)
        std::cout << GREEN << "[PASS] " << RESET << label << " is " << actual << std::endl;
    else
        std::cout << RED << "[FAIL] " << RESET << label << " expected " << expected << " but got " << actual << std::endl;
}

void check_not_equal(const std::string& label, const vect2& a, const vect2& b) {
    if (a != b)
        std::cout << GREEN << "[PASS] " << RESET << label << " " << a << " != " << b << std::endl;
    else
        std::cout << RED << "[FAIL] " << RESET << label << " expected " << a << " != " << b << " but they are equal" << std::endl;
}

int main()
{
    vect2 v1; // 0, 0
    vect2 v2(1, 2); // 1, 2
    const vect2 v3(v2); // 1, 2
    vect2 v4 = v2; // 1, 2

    check_result("v1 init", v1, vect2(0, 0));
    check_result("v2 init", v2, vect2(1, 2));
    check_result("v3 copy", v3, vect2(1, 2));
    check_result("v4 copy", v4, vect2(1, 2));

    check_result("v1 == v1", v1, v1);
    check_result("v2 == v3", v2, v3);
    check_result("v3 == v4", v3, v4);

    check_not_equal("v1 != v2", v1, v2);
    check_not_equal("v1 != v3", v1, v3);

    std::cout << v4++ << std::endl; // {1,2}
    check_result("v4 after v4++", v4, vect2(2, 3));

    std::cout << ++v4 << std::endl; // {3,4}
    check_result("v4 after ++v4", v4, vect2(3, 4));

    std::cout << v4-- << std::endl; // {3,4}
    check_result("v4 after v4--", v4, vect2(2, 3));

    std::cout << --v4 << std::endl; // {1,2}
    check_result("v4 after --v4", v4, vect2(1, 2));

    v2 += v3; // {2,4}
    check_result("v2 after += v3", v2, vect2(2, 4));

    v1 -= v2; // {-2,-4}
    check_result("v1 after -= v2", v1, vect2(-2, -4));

    v2 = v3 + v3 * 2; // {3,6}
    check_result("v2 = v3 + v3*2", v2, vect2(3, 6));

    v2 = 3 * v2; // {9,18}
    check_result("v2 = 3*v2", v2, vect2(9, 18));

    v2 += v2 += v3; // v2 = (v2 += v3) += v2 = (10,20) += (10,20) = {20,40}
    check_result("v2 += v2 += v3", v2, vect2(20, 40));

    v1 *= 42; // {-84, -168}
    check_result("v1 *= 42", v1, vect2(-84, -168));

    v1 = v1 - v1 + v1; // {0,0} + {-84,-168} = {-84,-168}
    check_result("v1 = v1 - v1 + v1", v1, vect2(-84, -168));

    check_result("-v2", -v2, vect2(-20, -40));

    return 0;
}



// int main()
// {
//     vect2 v1; // 0, 0
//     vect2 v2(1, 2); // 1, 2
//     const vect2 v3(v2); // 1, 2
//     vect2 v4 = v2; // 1, 2

//     std::cout << "v1: " << v1 << std::endl;
//     std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
//     std::cout << "v2: " << v2 << std::endl;
//     std::cout << "v3: " << v3 << std::endl;
//     std::cout << "v4: " << v4 << std::endl;
//     std::cout << v4++ << std::endl; // 2, 3
//     std::cout << ++v4 << std::endl; // 3, 4
//     std::cout << v4-- << std::endl; // 2, 3
//     std::cout << --v4 << std::endl; // 1, 2
//     v2 += v3; // 2, 4
//     v1 -= v2; // -2, -4
//     v2 = v3 + v3 *2; // 3, 6
//     v2 = 3 * v2; // 9, 18
//     v2 += v2 += v3; // 20, 40
//     v1 *= 42; // -84, -168
//     v1 = v1 - v1 +v1;
//     std::cout << "v1: " << v1 << std::endl;
//     std::cout << "v2: " << v2 << std::endl;
//     std::cout << "-v2: " << -v2 << std::endl;
//     std::cout << "v1[1]: " << v1[1] << std::endl;
//     v1[1] = 12;
//     std::cout << "v1[1]: " << v1[1] << std::endl;
//     std::cout << "v3[1]: " << v3[1] << std::endl;
//     std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
//     std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
//     std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
//     std::cout << "v1 != v1: " << (v1 != v1) << std::endl;
// }