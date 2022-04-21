// 练习使用 重载 重写 覆盖

#include <iostream>
#include <string>
using namespace std;


class Base {
public:
    virtual void mf1()    
    {
        cout << "Base::virtual void mf1()" << endl;
    }
    virtual void mf1(int)        //重载mf1() virtual函数
    {
        cout << "Base::virtual void mf1(int)" << endl;
    }
    int f() const
    {
        cout << "Base::f()\n";
        return 1;
    }
    int f(string) const        //重载f()函数
    {
        cout << "Base::f(string)" << endl;
        return 1;
    }
};


class Derived : public Base {
public:
    using Base::f;        //使用using关键字让f()函数可见
    virtual void mf1()    // 重写基类虚函数
    {
        cout << "Derived::virtual void mf1()" << endl;
    }
    int f(int)    //重定义f()函数, 可以改变其参数列表
    {
        cout << "Derived::f(int) const\n";
        return 1;
    }
};




class Derived2 : public Base {
public:
    void f()    //重定义f()函数, 可以改变其返回值
    {
        cout << "Derived2::f() const\n";
    }
};


int main()
{
    Derived d;
    Derived2 d2;
    int x = 10;
    string str = "hello";
    
    
    d.mf1();        ///调用派生类中的函数
//!    d.mf1(x);        ///派生类重写了基类中的mf1虚函数，则基类中其他版本的函数都被隐藏了
    d.f(x);            ///调用派生类中的函数
    d.f();
    
    d2.f();
//!    d2.f(str);        ///派生类重定义基类中的f函数，则基类中其他版本的函数都被隐藏了
}
