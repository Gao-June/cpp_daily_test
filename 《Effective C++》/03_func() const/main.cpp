/**
 * func()后接 const
 * 效果：
 *  class 可以调用 func()、func() const.
 *  const class 只能调用 func() const.
 * 
 * C++在函数后加const的意义:
 *  已定义成const的成员函数，一旦企图修改数据成员的值，则编译器按错误处理。
 * 1、非静态成员函数后面加const (加到非成员函数或静态成员后面会产生编译错误)
 * 2、表示成员函数隐含传入的this指针为const指针，决定了在该成员函数中，
 *      ―任意修改它所在的类的成员的操作都是不允许的(因为隐含了对this指针的const引用);
 * 3、唯一的例外是对于mutable修饰的成员。
 *      加了const的成员函数可以被非const对象和const对象调用但不加const的成员函数只能被非const对象调用
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
// class 可以调用 func()、func() cosnt.
    Entity e1;
    e1.func1();
    e1.func2();

// const class 只能调用 func() const.
    const Entity e2;
    //e2.func1(); // error
    e2.func2();

    return 0;
}