/**
 * ̽�� ���ؼ̳е��³�Ա�����������
 * �����ַ�����������⣺
 *  ���� -1 ����ָ��
 *  ���� -2 ����ת��
 *  ���� -3 ��д����ֱ����C�ж����Ҫʹ�õı�����
 */

#include <iostream>


class A {
public:
    int getVal() {
        return 11;
    }
    int aVal = 12;
};
 
class B {
public:
    int getVal() {
        return 22;
    }
    int aVal = 23;
};
 
class C : public A, public B {
// ���� - 3 ��д����ֱ����C�ж����Ҫʹ�õı�����
public:
    using A::getVal;
    using B::aVal;
};

int main( ){
    C c;

    //std::cout << c.getVal() << "  " << c.aVal << std::endl;   // err, ָ������ȷ

// ���� -1 ����ָ��
    std::cout << "No.1 :" << std::endl;
    std::cout << c.A::getVal() << "  " << c.B::getVal() << std::endl;


// ���� - 2 ����ת��
    std::cout << "No.2 :" << std::endl;
    std::cout << static_cast<A&>(c).getVal() << std::endl;


// ���� - 3 ǿ���Ƽ� ʹ�� using �ڲ�ָ����ӽ�����ʹ��
// �� class C

    return 0;
}