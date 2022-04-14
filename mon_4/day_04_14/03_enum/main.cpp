// 练习使用 enum 枚举

#include <iostream>

enum numbers : int
{
    A = 0, B, C = 5, D
};

int main( ){

    std::cout << "A: " << A << "  B: " << B << "  C: " << C  << " D: " << D << std::endl;

    return 0;
}