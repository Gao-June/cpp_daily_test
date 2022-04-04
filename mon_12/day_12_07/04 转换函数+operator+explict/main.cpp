/*
    转换函数 conversion func + operator + explicit
    
    相对于上一个转换函数（02_转换函数） 这里再引入 operator+
    引入 explicit 是为了禁止编译器自动做隐式转换（在 ctor 处）
    同时将 x 定义为 double 类型
*/

#include <iostream>

using namespace std;

class Base{
public:
    // constructor，同时禁止隐式转换
   explicit Base( int a, int b = 1 ) : _a( a ), _b( b ){}

    //conversion func
    operator double( ) const{
        double ex_a = 0.0 + _a;
        double ex_b = 0.0 + _b;
        return ex_a / ex_b ;
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
    double x =num + 4;     // 禁止隐式转换后，后面的 +4 无法调用 operator+

    cout << x << endl;

    return 0;
}