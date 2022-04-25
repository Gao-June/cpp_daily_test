/**
 * ����� ��������Ӧ������Ϊ ������������
 * ��Ȼ�� Base* base = &derive�� ��ʱ�򣬲���ִ�� Derive ����������
*/

#include <iostream>

class Base{
public:
    Base( ){
        std::cout << "Base  construct" << std::endl;
    }

    virtual ~Base( ){
        std::cout << "Base destruct" << std::endl;
    }
};

class Derive : public  Base{
public:
    Derive( ){
        std::cout << "Derive construct" << std::endl;
        p = new int[5];
    }
    ~Derive( ){
        std::cout << "Derive destruct" << std::endl;
        delete[] p;
    }

private:
    int* p;

};

int main( ){
    std::cout << "No.1 ----------------" << std::endl;
    Base *base = new Base;
    delete base;

    std::cout << "No.2 ----------------" << std::endl;
    Derive *derive = new Derive;
    delete derive;

// ��� Base �������������� ������������No.3�����Ӳ������ Derive ����������
    std::cout << "No.3 ----------------" << std::endl;
    Base* base2 = new Derive();
    delete base2;

    return 0;
}
