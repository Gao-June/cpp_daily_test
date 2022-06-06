// 练习 类型推导 BOOST_AUTO/BOOST_TYPEOF
/*
auto:
    C++11新标准就引入了类型自动推断：auto关键字让编译器通过初始值来进行类型推演。
    从而获得定义变量的类型，auto定义的变量必须有初始值。

decltype:
    C++11新标准编译时类型推导，除了auto关键字，还有 decltype关键字， 
    decltype不是像auto一样是从变量的初始化表达式获得类型，而是以表达式作为参数，
    返回该表达式的类型并且 decltype不会对表达式求值。
*/

#include <iostream>
#include <boost/typeof/typeof.hpp>

int main( ){
std::cout << "auto:" << std::endl;
    auto a = 100;
    std::cout << typeid(a).name() << std::endl;

std::cout << "decltype:" << std::endl;
    decltype(1.23f) b;
    std::cout << typeid(b).name() << std::endl;

    decltype(a++)  c;
    std::cout << "a is: " << a << "\t" << typeid(c).name() << std::endl;

    decltype( &c )  d;
    std::cout << typeid(d).name() << std::endl;

std::cout << "BOOST:" << std::endl;
    BOOST_TYPEOF(1.23f) bb;
    std::cout << typeid(bb).name() << std::endl;

    return 0;
}