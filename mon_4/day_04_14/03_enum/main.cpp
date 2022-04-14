// 练习使用 enum 枚举

#include <iostream>

// 这里的 numbers 就相当于一个类型了
enum numbers : int
{
    A = 0, B, C = 5, D
};

void print_fun( numbers a ){
    std::cout << "this number is : " << a << std::endl;;
}

int main( ){

    std::cout << "A: " << A << "  B: " << B << "  C: " << C  << " D: " << D << std::endl;

    numbers num = D;
    print_fun(D);

    return 0;
}