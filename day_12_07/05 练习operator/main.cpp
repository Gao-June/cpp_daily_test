/*
    再练习一下 operator 的使用方法  github没显示中文注释
*/

#include <iostream>

using namespace std;

class Base{
public:
    // ctor
    Base( int a = 0, int b = 0 ) : _a( a ), _b( b ){}

    void _print( );
    Base& operator += ( const Base &temp );
    Base& operator -= ( const Base &temp );
    Base& operator *= ( const Base &temp );
    Base& operator /= ( const Base &temp );

private:
    int _a;
    int _b;
};

void Base::_print( ){
        cout << "a : " << _a << "  b: " << _b << endl;
    }

// operator +=
Base& Base::operator += ( const Base &temp ){
    this->_a += temp._a;
    this->_b += temp._b;

    return *this;
}

// operator -=
Base& Base::operator -= ( const Base &temp ){
    this->_a -= temp._a;
    this->_b -= temp._b;

    return *this;
}

// operator *=
Base& Base::operator *= ( const Base &temp ){
    this->_a *= temp._a;
    this->_b *= temp._b;

    return *this;
}

// operator /=
Base& Base::operator /= ( const Base &temp ){
    this->_a /= temp._a;
    this->_b /= temp._b;

    return *this;
}

int main( ){
    Base num1(1,2);
    Base num2(3,4);

    num1 *= num2;
    cout << " num1 - num2 : " << endl;
    num1._print();

    return 0;
}