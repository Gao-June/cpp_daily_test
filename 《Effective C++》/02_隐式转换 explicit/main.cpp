/**
 * 《Effective C++》 导读
 * 
 * 探究隐式转换 explicit
 * explicit:
 *  通过将 ctor 声明为explicit，可以阻止它们被用来执行隐式转换（implicit type conveesions），
 *  但是它们仍可被用来进行显示类型转换
 */

#include <iostream>

class A{
public:
    A(){
        std::cout << "ctor A()" << std::endl;
    }
};

class B{
public:
    explicit B( int x = 0, bool b = true ){
        std::cout << "ctor B()" << std::endl;
    }

public:
    int x;
    bool b;
};

class C{
public:
    explicit C( int x ){
        std::cout << "ctor C()" << std::endl;
    }

public:
    int x;
};

void DoSomething( B obj ){
    std::cout << "func() DoSomething" << std::endl;
}

int main( ){
    B b_obj_1;                  // 可以
    DoSomething( b_obj_1 );     //可以
    B b_obj_2(28);              // 可以，（此时 b参数缺省为 true）

    // DoSomething( 28 );          // 禁止隐式转换了
    DoSomething( B(28) );       // 可以~

    return 0;
}