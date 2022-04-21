/**
 * 函数指针功能：让代码更干净。以下有4种方式实现函数指针功能
 * 
 * （方式1）最原始的方式，给出所有类型
 * （方式2）可以直接使用 auto = 函数名  的方式进行函数指针赋值
 * （方式3） typedef
 * （方式4） using
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

// 方式-1， 原始写法
    std::cout << "No.1" << std::endl;
    int (*p)( const int &, const int & );
    p = Add_nums;
    std::cout << p(num1, num2) << std::endl;

    p = Sub_num;
    std::cout << p(num1, num2) << std::endl;


// 方式-2， auto
    std::cout << "No.2" << std::endl;
    auto q = Add_nums;
    std::cout << q(num1, num2) << std::endl;

    q = Sub_num;
    std::cout << q(num1, num2) << std::endl;


// 方式-3， typedef
    std::cout << "No.3" << std::endl;
    
    // 这里的 *ptr_func 是类型名， 下面要定义变量实例化
    typedef int(*Ptr_Func)( const int&, const int& );
    Ptr_Func Ptr1 = Add_nums;
    std::cout << Ptr1(num1, num2) << std::endl;

    Ptr1 = Sub_num;
    std::cout << Ptr1(num1, num2) << std::endl;


    return 0;
}