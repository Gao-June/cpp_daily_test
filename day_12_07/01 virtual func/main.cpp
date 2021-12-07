/*
    练习 基类写虚函数、纯虚函数；
    派生类调用基类的函数、虚函数，改写基类的虚函数、纯虚函数

*/


#include <iostream>
#include <string>

using namespace std;

class Base{
public:
    // non-virtual  普通函数
    void _print1( ) const {
        cout << "this is a base class non-virtual func" << endl;
    }

    // impure-virtual func 虚函数
    virtual void _print2( ) const {
        cout << "this is a base class impure-virtual func" << endl;
    }

    // pure-virtual func 纯虚函数
    virtual void _print3( ) const = 0;

private:
    int a;
    string s;
};

class Derived : public Base{
public:
    // 复写 基类的 纯虚函数
    virtual void _print3( ) const{
        cout << "this is deriver_class pure-virtual func" << endl;
    }
    
    // 复写 基类的 虚函数
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

    // 直接调用基类 的函数
    my_class._print1();
    // 直接调用基类的 虚函数
    my_class.Base::_print2();
    // 改写了基类的 虚函数
    my_class._print2();
    // 改写了基类的 纯虚函数
    my_class._print3();
    
    return 0;
}