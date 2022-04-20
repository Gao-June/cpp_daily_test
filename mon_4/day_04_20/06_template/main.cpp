#include <iostream>
#include <string>

template <typename T>
bool Max_Num( T num_a, T num_b ){
    return num_a > num_b;
}

template < typename T, typename W >
void Print( T str, W num )
{
    std::cout << str << "   " << num << std::endl;
}

int main()
{
    int a = 18, b = 14;
    if ( Max_Num(a,b) )
        std::cout << "big" << std::endl;
    else    
        std::cout << "small" << std::endl;

    double c = 1.2345, d = 2.3424;
    if ( Max_Num(c, d) )
        std::cout << "big" << std::endl;
    else    
        std::cout << "small" << std::endl;

    std::string str("hello");
    int num = 10000;
    Print( str, num );

    return 0;
}