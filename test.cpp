#include <iostream>
using namespace std;


class B{
public:
    char ch = 'a';
    virtual void func0(){}
};

class C{
public:
    char ch1 = 'b';
    char ch2 = 'c';
    virtual void func0(){}
};

// 加上F作为测试
class F{
public:
    virtual void func3( ){}
};

class E : public B, public C{
public:
    int e = 1;
    virtual void func0( ){}
    virtual void func1( ){}
    //virtual void func3( ){}
};

int main( ){
    B b;
    C c;
    E e;
    F f;

    cout << "b: " << sizeof(b) << endl;     // 16
    cout << "c: " << sizeof(C) << endl;     // 16
    cout << "f: " << sizeof(F) << endl;     // 8
    cout << "e: " << sizeof(E) << endl;     // 32
    cout << "查看地址：" << endl << "ch:" << &(e.ch) << "\tch1:" << &(e.ch1) << "\tch2:" <<
        &(e.ch2) << "\te:" << &e.e << endl;
}