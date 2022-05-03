/**
 * operator = Ϊ���ܹ�����ʹ�� = ��ֵ�����Է�������Ϊ &���� reference by this *
 *  eg. Base& operator= ( Base& b ){}
 *  
 * ��ע��ϵͳ�����Դ��� operaotr =�� ���������Լ�д������ = 100��ʾ����
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

    // �Լ�дһ�� operator=
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