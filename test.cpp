#include <iostream>
using namespace std;


class A{

};

class B{
public:
    char ch = 'a';
    virtual void func0(){}
};

class C{
public:
    char ch1 = 'b';
    char ch2 = 'c';
    virtual void func(){}
    virtual void func1(){}
};

class D : public A, public C{
public:
    int d = 9;
    //virtual void func(){}
    virtual void func2(){}
};

class E : public B, public C{
public:
    int e = 1;
    virtual void func( ){}
    virtual void func1( ){}
    // virtual void func3( ){}
    // virtual void func4( ){}
};


// 加上F作为测试
class F{
public:
    char ch4 = 'f';
    int ff = 4;
    virtual void func3( ){}
};

class G{
public:
    virtual void func4( ){}
};

class H{
public:
    virtual void func5( ){} 
};

class I : public G, public H{
public:
    virtual void func4( ){}
    virtual void func5( ){} 
};

int main( ){
    A a;
    B b;
    C c;
    D d;
    E e;
    F f;
    G g;
    H h;
    I i;

    cout << "a: " << sizeof(a) << endl;     // 1
    cout << "b: " << sizeof(b) << endl;     // 16
    cout << "c: " << sizeof(c) << endl;     // 16
    cout << "d: " << sizeof(d) << endl;     // 16
    cout << "e: " << sizeof(e) << endl;     // 32
    cout << "f: " << sizeof(f) << endl;     // 16
    cout << "g: " << sizeof(g) << endl;     // 8
    cout << "h: " << sizeof(h) << endl;     // 8
    cout << "i: " << sizeof(i) << endl;     // 16
    
    return 0;
}