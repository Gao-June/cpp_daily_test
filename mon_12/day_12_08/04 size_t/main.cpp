/*
    size_t 是无符号 int 如果给 size_t赋值一个负数会怎样？
*/

#include <iostream>

using namespace std;

int main( ){
    size_t a = 100;
    cout << "a = " << a << endl;

    a = -100;       // a = 18446744073709551516 又变成正无穷大了
    cout << "a = " << a << endl;

    a = 0;          // a - 1 = 18446744073709551615
    cout << "a - 1 = " << a - 1 << endl;

}