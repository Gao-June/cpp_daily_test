/**
 * operator = 为了能够连续使用 = 赋值，所以返回类型为 &，即 reference by this *
 *  eg. Base& operator= ( Base& b ){}
 *  
 * 【注】系统会有自带的 operaotr =， 所以我在自己写的里面 = 100以示区别
 */

#include <iostream>

class Base{
public:
    Base( ){
        std::cout << "ctor" << std::endl;
    }
    Base( int x, int y ) : _x(x), _y(y){
        std::cout << "ctor with value" << std::endl;
    }
    ~Base( ){
        std::cout << "dtor" << std::endl;
    }

    void Print( ){
        std::cout << "x: " << _x << "  y: " << _y << std::endl;
    }

    // 自己写一个 operator=
    Base& operator= ( Base& b ){
        this->_x = b._x + 100;
        this->_y = b._y + 100;
        return *this;
    }
    

public:
    int _x, _y;
};

int main( ){
    Base a(1,2);
    Base b(3,4);
    a.Print();
    b.Print();

    a = b;
    a.Print();

    return 0;
}