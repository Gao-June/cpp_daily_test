/*
    写一个多态，让基类指针指向派生类;

    1- 当基类指针向调用派生类的 函数时，可以直接调用；
    2-  ……想调用自己的 函数时，需要加作 用域运算符 ::
    3- 注意，基类所调用的函数只能是：自己在基类里的、派生类重写的虚函数、派生类的纯虚函数；派生类的普通函数无法调用。
*/

#include <iostream>
#include <string>

using namespace std;

class Base{
public:
    void _print1( ) const {
        cout << "基类的普通函数" << endl;
    }
    
    virtual void _print2( ) const {
        cout << "基类的虚函数" << endl;
    }

    // 基类的纯虚函数
    virtual void _print3( ) const = 0;

private:
    int _a;
    string _b;
};

class Derived : public Base{
public:
    void _print9( ) const {
        cout << "派生类的普通函数" << endl;
    }

    virtual void _print2( ) const {
        cout << "派生类 改写了 基类 的虚函数" << endl;
    }

    virtual void _print3( ) const{
        cout << "派生类 改写了 基类 的纯虚函数" << endl;
    }

private:
    int _q;
    string _w;
};

int main( ){
    // 现在写一个基类指针，让它指向派生类，看看效果
    Derived d;
    Base *b = &d;

    cout << "test 01" << endl;
    // b->_print10();  // wrong 基类没有这个成员函数
    b->_print1();   // 基类的普通函数
    b->_print2();   // 派生类 改写了 基类 的虚函数  
    b->_print3();   // 派生类 改写了 基类 的纯虚函数

    // 基类指针能调用自己的 func 吗？
    cout << "test 02" << endl;
    //b->Derived::_print9();  // wrong 基类没有这个成员函数
    b->Base::_print1(); // 基类的普通函数
    b->Base::_print2(); // 基类的虚函数
   // b->Base::_print3();   // wrong 纯虚函数并没有定义

    return 0;
}