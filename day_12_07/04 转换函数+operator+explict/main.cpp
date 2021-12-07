/*
    ת������ conversion func + operator + explicit
    
    �������һ��ת��������02_ת�������� ���������� operator+
    ���� explicit ��Ϊ�˽�ֹ�������Զ�����ʽת������ ctor ����
    ͬʱ�� x ����Ϊ double ����
*/

#include <iostream>

using namespace std;

class Base{
public:
    // constructor��ͬʱ��ֹ��ʽת��
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
    int _a;     // ����
    int _b;     // ��ĸ
};

int main( ){
    Base num(1, 2);
    double x =num + 4;     // ��ֹ��ʽת���󣬺���� +4 �޷����� operator+

    cout << x << endl;

    return 0;
}