/**
 * func()��� const
 * Ч����
 *  class ���Ե��� func()��func() const.
 *  const class ֻ�ܵ��� func() const.
 * 
 * C++�ں������const������:
 *  �Ѷ����const�ĳ�Ա������һ����ͼ�޸����ݳ�Ա��ֵ�����������������
 * 1���Ǿ�̬��Ա���������const (�ӵ��ǳ�Ա������̬��Ա���������������)
 * 2����ʾ��Ա�������������thisָ��Ϊconstָ�룬�������ڸó�Ա�����У�
 *      �D�����޸������ڵ���ĳ�Ա�Ĳ������ǲ������(��Ϊ�����˶�thisָ���const����);
 * 3��Ψһ�������Ƕ���mutable���εĳ�Ա��
 *      ����const�ĳ�Ա�������Ա���const�����const������õ�����const�ĳ�Ա����ֻ�ܱ���const�������
 */

#include <iostream>

class Entity{
public:
    void func1( ){
        std::cout << "func1()" << std::endl;
    }

    void func2( ) const{
        std::cout << "func2()" << std::endl;
    }

};

int main( ){
// class ���Ե��� func()��func() cosnt.
    Entity e1;
    e1.func1();
    e1.func2();

// const class ֻ�ܵ��� func() const.
    const Entity e2;
    //e2.func1(); // error
    e2.func2();

    return 0;
}