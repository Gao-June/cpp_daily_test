/*
    转换函数 conversion func
    
    写一个分数形式的转换函数
    x = a/b
*/

#include <iostream>

using namespace std;


class Base{
public:
    // constructor
    Base( int a, int b = 1 ) : _a( a ), _b( b ){}

    // conversion func
    operator double( ) const{
        double ex_a = 0.0 + _a;
        double ex_b = 0.0 + _b;
        return ex_a / ex_b ;
    }

private:
    int _a;
    int _b;
};

int main( ){
    Base num(3, 5);
    double x = 4 + num;     // 调用 operator double( ) 将 Base转换为 1/2 也就是 0.5

    cout << x << endl;

    // double q = double(1.0/2);
    // cout << q << endl;

    return 0;
}