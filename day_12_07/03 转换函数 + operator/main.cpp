/*
    ת������ conversion func
    
    �������һ��ת��������02_ת�������� ���������� operator+
    ͬʱ�� x ����Ϊ Base ����

    ���������� ambiguous����Ϊ��������֪������ת������������ operator+ ,��������� 04�½�
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
    int _a;     // ����
    int _b;     // ��ĸ
};

int main( ){
    Base num(1, 2);
    Base x =num + 4;     // ���� ambiguous

    x._print();

    // double q = double(1.0/2);
    // cout << q << endl;

    return 0;
}