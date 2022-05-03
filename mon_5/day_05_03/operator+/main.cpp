/**
 * ̽����Ա operator += ��������Ա����Ϊ private���
 *  => ���Զ��� frinend ���
 * ??? ������д��ʱ��Ҳû������ʲô����ѽ
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