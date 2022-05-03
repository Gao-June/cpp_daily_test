/**
 * ����������
 *  �ڶ�̬�У�base class������� virtual func()���ǻ���� dtorҪ����Ϊ�麯��
 * 
 */

#include <iostream>

class Base{
public:
    Base( ){
        std::cout << "Base ctor" << std::endl;
    }

// virtual ~Base( ){
    ~Base( ){
        std::cout << "Base dtor" << std::endl;
    }

public:
    // ����û�ж��� pure virtual
    virtual void Print( ){
        std::cout << "Base Print() " << std::endl;
    }

};


class Derive : public Base{
public:
    Derive( ){
        std::cout << "Detive ctor" << std::endl;
    }
    ~Derive( ){
        std::cout << "Derive dtor" << std::endl;
    }

public:
    void Print( ){
        std::cout << "Derive Print()" << std::endl;
    }
};

int main( ){
    // ��̬ ����ָ��ָ�����������
    Base *b = new Derive();
    b->Print();
    b->Base::Print();

    delete b;   // ���Է��ֲ�û�е��� Derive dtor

    return 0;
}
