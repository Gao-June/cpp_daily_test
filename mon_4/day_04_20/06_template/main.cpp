#include <iostream>

template <typename T>
bool Max_Num( T num_a, T num_b ){
    return num_a > num_b;
}

int main()
{
    int a = 18, b = 14;
    if ( Max_Num(a,b) )
        std::cout << "big" << std::endl;
    else    
        std::cout << "small" << std::endl;

    return 0;
}