/*
    普通函数后面能加 const 吗？
    不能！ 只有 成员函数 才可以
    【注】成员函数后加 const 的目的是为了 禁止对class里成员变量的更改。
*/

#include <iostream>

using namespace std;

// 普通函数后 不能增加 const
int sum( int a, int b ) const {
    return a + b;
}

int main( ){
    int a = 10, b = 20;

    // 报错： on-member function 'int sum(int, int)' cannot have cv-qualifier
    cout << sum( a, b ) << endl;

    return 0;
}