/*
    дһ����̬���û���ָ��ָ��������;

    1- ������ָ�������������� ����ʱ������ֱ�ӵ��ã�
    2-  ����������Լ��� ����ʱ����Ҫ���� ��������� ::
    3- ע�⣬���������õĺ���ֻ���ǣ��Լ��ڻ�����ġ���������д���麯����������Ĵ��麯�������������ͨ�����޷����á�
*/

#include <iostream>
#include <string>

using namespace std;

class Base{
public:
    void _print1( ) const {
        cout << "�������ͨ����" << endl;
    }
    
    virtual void _print2( ) const {
        cout << "������麯��" << endl;
    }

    // ����Ĵ��麯��
    virtual void _print3( ) const = 0;

private:
    int _a;
    string _b;
};

class Derived : public Base{
public:
    void _print9( ) const {
        cout << "���������ͨ����" << endl;
    }

    virtual void _print2( ) const {
        cout << "������ ��д�� ���� ���麯��" << endl;
    }

    virtual void _print3( ) const{
        cout << "������ ��д�� ���� �Ĵ��麯��" << endl;
    }

private:
    int _q;
    string _w;
};

int main( ){
    // ����дһ������ָ�룬����ָ�������࣬����Ч��
    Derived d;
    Base *b = &d;

    cout << "test 01" << endl;
    // b->_print10();  // wrong ����û�������Ա����
    b->_print1();   // �������ͨ����
    b->_print2();   // ������ ��д�� ���� ���麯��  
    b->_print3();   // ������ ��д�� ���� �Ĵ��麯��

    // ����ָ���ܵ����Լ��� func ��
    cout << "test 02" << endl;
    //b->Derived::_print9();  // wrong ����û�������Ա����
    b->Base::_print1(); // �������ͨ����
    b->Base::_print2(); // ������麯��
   // b->Base::_print3();   // wrong ���麯����û�ж���

    return 0;
}