/**
 * 探究成员 operator += 中遇到成员变量为 private情况
 *  => 可以定义 frinend 解决
 * ??? 但是我写的时候，也没发现有什么问题呀
 */

#include <iostream>

class Base{
public:
    Base( int a, int b ) : _a(a), _b(b){
        std::cout << "ctor" << std::endl;
    }
    ~Base( ){
        std::cout << "dtor" << std::endl;
    }

    // operator +
    Base& operator+= ( Base& b );

    void Print( ){
        std::cout << "a: " << _a << "  b:" << _b << std::endl;
    }

private:
    int _a, _b;
// public:
//     int _a, _b;

};

Base& Base::operator+= ( Base& b )
{
        this->_a += b._a + 1000;
        this->_b += b._b + 1000;
        return *this;
    }

int main( ){
    Base b1(1, 2);
    Base b2(3, 4);
    b1  += b2;
    b1.Print();

    return 0;
}