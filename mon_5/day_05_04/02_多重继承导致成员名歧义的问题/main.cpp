/**
 * 探究 多重继承导致成员名歧义的问题
 * 有三种方法解决该问题：
 *  方法 -1 域名指定
 *  方法 -2 类型转换
 *  方法 -3 的写法，直接在C中定义好要使用的变量。
 */

#include <iostream>


class A {
public:
    int getVal() {
        return 11;
    }
    int aVal = 12;
};
 
class B {
public:
    int getVal() {
        return 22;
    }
    int aVal = 23;
};
 
class C : public A, public B {
// 方法 - 3 的写法，直接在C中定义好要使用的变量。
public:
    using A::getVal;
    using B::aVal;
};

int main( ){
    C c;

    //std::cout << c.getVal() << "  " << c.aVal << std::endl;   // err, 指代不明确

// 方法 -1 域名指定
    std::cout << "No.1 :" << std::endl;
    std::cout << c.A::getVal() << "  " << c.B::getVal() << std::endl;


// 方法 - 2 类型转换
    std::cout << "No.2 :" << std::endl;
    std::cout << static_cast<A&>(c).getVal() << std::endl;


// 方法 - 3 强烈推荐 使用 using 内部指定最接近正常使用
// 见 class C

    return 0;
}