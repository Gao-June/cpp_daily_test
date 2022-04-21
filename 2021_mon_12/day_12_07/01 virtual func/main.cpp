/*
    ��ϰ ����д�麯�������麯����
    ��������û���ĺ������麯������д������麯�������麯��

*/


#include <iostream>
#include <string>

using namespace std;

class Base{
public:
    // non-virtual  ��ͨ����
    void _print1( ) const {
        cout << "this is a base class non-virtual func" << endl;
    }

    // impure-virtual func �麯��
    virtual void _print2( ) const {
        cout << "this is a base class impure-virtual func" << endl;
    }

    // pure-virtual func ���麯��
    virtual void _print3( ) const = 0;

private:
    int a;
    string s;
};

class Derived : public Base{
public:
    // ��д ����� ���麯��
    virtual void _print3( ) const{
        cout << "this is deriver_class pure-virtual func" << endl;
    }
    
    // ��д ����� �麯��
    virtual void _print2( ) const{
        cout << "this is deriver_class impure-virtual func" << endl;
    }

private:
    int b;
    string s;
};

int main( ){
    // deriver_class
    Derived my_class;

    // ֱ�ӵ��û��� �ĺ���
    my_class._print1();
    // ֱ�ӵ��û���� �麯��
    my_class.Base::_print2();
    // ��д�˻���� �麯��
    my_class._print2();
    // ��д�˻���� ���麯��
    my_class._print3();
    
    return 0;
}