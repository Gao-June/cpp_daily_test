/**
 * 函数指针功能：让代码更干净
 * 可以直接使用 auto = 函数名  的方式进行函数指针赋值
*/

#include <iostream>

int Add_nums( const int &a, const int &b )
{
    return a + b;
}


int Sub_num( const int &a, const int &b )
{
    return a - b;
}

int main()
{
    const int num1 = 10, num2 = 25;

// 方式 - 1
    int (*p)( const int &, const int & );
    p = Add_nums;
    std::cout << p(num1, num2) << std::endl;

    p = Sub_num;
    std::cout << p(num1, num2) << std::endl;

// 方式 - 2
    auto q = Add_nums;
    std::cout << q(num1, num2) << std::endl;

    q = Sub_num;
    std::cout << q(num1, num2) << std::endl;

    return 0;
}