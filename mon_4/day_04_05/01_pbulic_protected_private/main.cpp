// 练习使用 public/protected/private 三种继承

#include <iostream>

using namespace std;

class person{
public:
    int _p_a;

    person( int a = 0, int b = 0, int c = 0 ) : _p_a(a), _p_b(b), _p_c(c) {
        cout << "create class person" << endl;
    }

    void p_public_print( ){
        cout << "this is class person public func " << endl;
        cout << "_p_a : " << _p_a << "  _p_b : " << _p_b << " _p_c :  " << _p_c << endl;
    }

    void do_protected_func( ){
        p_protected_print( );
    }

protected:
    int _p_b;
    void p_protected_print( ){
        cout << "this is class person protected func" << endl;
        cout << "_p_a : " << _p_a << "  _p_b : " << _p_b << " _p_c :  " << _p_c << endl;
    }

private:
    int _p_c;
};

// public 继承
class a_person : public person{
public:
    int _a_a;

    a_person( int a = 0, int b = 0, int c = 0 ) : _a_a(a), _a_b(b), _a_c(c) {
        cout << "create class a_person" << endl;
    }

    void a_public_print( ){
        cout << "this is class a_person " << endl;
        cout << "_a_a : " << _a_a << "  _a_b : " << _a_b << " _a_c :  " << _a_c << endl;
    }

protected:
    int _a_b;

private:
    int _a_c;
};

// protected 继承
class b_person : protected person{
public:
    int _b_a;

    b_person( int a = 0, int b = 0, int c = 0 ) : _b_a(a), _b_b(b), _b_c(c) {
        cout << "create class b_person" << endl;
    }

    void b_public_print( ){
        cout << "this is class b_person " << endl;
        cout << "_b_a : " << _b_a << "  _b_b : " << _b_b << " _b_c :  " << _b_c << endl;
    }

protected:
    int _b_b;

private:
    int _b_c;
};

// private 继承
class c_person : private person{
public:
    int _c_a;

    c_person( int a = 0, int b = 0, int c = 0 ) : _c_a(a), _c_b(b), _c_c(c) {
        cout << "create class c_person" << endl;
    }

    void c_public_print( ){
        cout << "this is class c_person " << endl;
        cout << "_c_a : " << _c_a << "  _c_b : " << _c_b << " _c_c :  " << _c_c << endl;
    }

protected:
    int _c_b;

private:
    int _c_c;
};


int main( ){ 
    cout << "No.1  " << endl;
    person base;
    base.p_public_print();
    base.do_protected_func();   // protected func 可以被 public 里的函数调用
    
    base._p_a = 1;
    // base._p_b = 2;  // err protected 不可访问
    // base._p_c = 3;  // err private 不可访问

// public inheritance 
    cout << "No.2  " << endl;
    a_person son_a;
    son_a.a_public_print();
    son_a.p_public_print();

// 可以在 class 外更改自己的 public 数据 和 public inheritance 里的 public数据
    son_a._a_a = 11;
    // son_a._a_b = 12;  // err protected 不可访问
    // son_a._a_c = 13;  // err private 不可访问 
    son_a._p_a = 1;
    // son_a._p_b = 2;  // err protected 不可访问
    // son_a._p_c = 3;  // err private 不可访问 
    cout << "No.3  " << endl;
    son_a.a_public_print();
    son_a.p_public_print();

// protected inheritance
    cout << "No.4  " << endl;
    b_person son_b;
    son_b.b_public_print();
    // son_b.p_print();    // err 不可调用该函数

// 可以在 class 外更改自己的 public 数据
    son_b._b_a = 21;
    // son_b._b_b = 22;  // err protected 不可访问
    // son_b._b_c = 23;  // err private 不可访问
    // son_b._p_a = 1;  // err public 不可访问
    // son_b._p_b = 2;  // err protected 不可访问
    // son_b._p_c = 3;  // err private 不可访问
    cout << "No.5  " << endl;
    son_b.b_public_print();
    // son_b.p_print();    // err 不可调用该函数


// private inheritance
    cout << "No.6  " << endl;
    c_person son_c;
    son_c.c_public_print();
    // son_c.p_print();    // err 不可调用该函数

// 可以在 class 外更改自己的 public 数据
    son_c._c_a = 31;
    // son_c._c_b = 32;  // err protected 不可访问
    // son_c._c_c = 33;  // err private 不可访问
    // son_c._p_a = 1;  // err public 不可访问
    // son_c._p_b = 2;  // err protected 不可访问
    // son_c._p_c = 3;  // err private 不可访问 
    cout << "No.7  " << endl;
    son_c.c_public_print();
    // son_c.p_print();    // err 不可调用该函数


    return 0;
}
