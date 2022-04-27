/**
 * 探究 函数在传参的时候的调用顺序
 * 
 * 结论，先调用后面的参数，再调用前面的
*/

#include <iostream>

int Get_a(  ){
    int a = 10;
    std::cout << "Get_a()" << std::endl;

    return a;
}

int Get_b(  ){
    int b = 20;
    std::cout << "Get_b()" << std::endl;

    return b;
}

int Get_c(  ){
    int c = 30;
    std::cout << "Get_c()" << std::endl;

    return c;
}

// 先调用 C -> B -> A
void Fun_sum( int a, int b, int c ){
    std::cout << a + b + c << std::endl;
}

int main( ){
    Fun_sum( Get_a(  ), Get_b(  ), Get_c(  ) );

    return 0;
}

