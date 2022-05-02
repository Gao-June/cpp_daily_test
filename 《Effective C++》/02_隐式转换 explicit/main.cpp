/**
 * ��Effective C++�� ����
 * 
 * ̽����ʽת�� explicit
 * explicit:
 *  ͨ���� ctor ����Ϊexplicit��������ֹ���Ǳ�����ִ����ʽת����implicit type conveesions����
 *  ���������Կɱ�����������ʾ����ת��
 */

#include <iostream>

class A{
public:
    A(){
        std::cout << "ctor A()" << std::endl;
    }
};

class B{
public:
    explicit B( int x = 0, bool b = true ){
        std::cout << "ctor B()" << std::endl;
    }

public:
    int x;
    bool b;
};

class C{
public:
    explicit C( int x ){
        std::cout << "ctor C()" << std::endl;
    }

public:
    int x;
};

void DoSomething( B obj ){
    std::cout << "func() DoSomething" << std::endl;
}

int main( ){
    B b_obj_1;                  // ����
    DoSomething( b_obj_1 );     //����
    B b_obj_2(28);              // ���ԣ�����ʱ b����ȱʡΪ true��

    // DoSomething( 28 );          // ��ֹ��ʽת����
    DoSomething( B(28) );       // ����~

    return 0;
}