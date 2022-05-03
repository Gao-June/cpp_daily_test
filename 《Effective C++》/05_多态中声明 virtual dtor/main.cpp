/**
 * 问题描述：
 *  在多态中，base class中如果有 virtual func()，那基类的 dtor要声明为虚函数
 * 
 */

#include <iostream>

class Base{
public:
    Base( ){
        std::cout << "Base ctor" << std::endl;
    }

// virtual ~Base( ){
    ~Base( ){
        std::cout << "Base dtor" << std::endl;
    }

public:
    // 这里没有定义 pure virtual
    virtual void Print( ){
        std::cout << "Base Print() " << std::endl;
    }

};


class Derive : public Base{
public:
    Derive( ){
        std::cout << "Detive ctor" << std::endl;
    }
    ~Derive( ){
        std::cout << "Derive dtor" << std::endl;
    }

public:
    void Print( ){
        std::cout << "Derive Print()" << std::endl;
    }
};

int main( ){
    // 多态 基类指针指向派生类对象
    Base *b = new Derive();
    b->Print();
    b->Base::Print();

    delete b;   // 可以发现并没有调用 Derive dtor

    return 0;
}
