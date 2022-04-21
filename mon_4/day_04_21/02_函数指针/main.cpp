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

    int (*p)( const int &, const int & );
    p = Add_nums;
    std::cout << p(num1, num2) << std::endl;

    p = Sub_num;
    std::cout << p(num1, num2) << std::endl;

    return 0;
}