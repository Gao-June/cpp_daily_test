/*
    转换函数 conversion func
    
    相对于上一个转换函数（02_转换函数） 这里再引入 operator+
    同时将 x 定义为 Base 类型

    编译器报错 ambiguous，因为编译器不知道生成转化函数，还是 operator+ ,解决方法在 04章节
*/

#include <iostream>

using namespace std;


class Base{
public:
    // constructor
   Base( int a, int b = 1 ) : _a( a ), _b( b ){}

    //conversion func
    operator double( ) const{
        return (double) ( _a / _b );

        // double ex_a = 0.0 + _a;
        // double ex_b = 0.0 + _b;
        // return ex_a / ex_b ;
    }

    Base operator+( const Base &temp ){
        this->_b = _b * temp._b;
        this->_a = _a * temp._b + _b * temp._a;

        return *this;
    }

    void _print( ){
        cout << "_a : " << _a << "  _b :  " << _b << endl;
    }

private:
    int _a;     // 分子
    int _b;     // 分母
};

int main( ){
    Base num(1, 2);
    Base x =num + 4;     // 报错 ambiguous

    x._print();

    // double q = double(1.0/2);
    // cout << q << endl;

    return 0;
}