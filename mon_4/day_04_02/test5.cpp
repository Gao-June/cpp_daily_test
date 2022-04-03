// 函数重载 中 过载 问题
// 会自动匹配类型

#include <iostream>

using namespace std;

int add_num( int a, int b ){
    return a + b;
}

double add_num( double a , double b ){
    return a + b;
}

int main( ){
    int a = 1, b = 2;
    cout << add_num(a, b) << endl;

    double c = 1.1, d = 1.2 ;
    cout << add_num( c, d ) << endl;

    char e = 'a', f = 'b';
    cout << add_num( e, f ) << endl;
    return 0;
}