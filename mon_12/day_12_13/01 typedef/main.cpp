/*
    在 golang 中，自定义类型不会继承基础类型的其它信息;
    测试一下 cpp 可不可以   => 可以
*/

#include <iostream>

using namespace std;

typedef int iii;

int main( ){
    int a = 10;

    iii b = 15;

    int c = b;

    cout << "a: " << a << "  b:  " << b << "  c : " << c << endl;

    return 0;
}