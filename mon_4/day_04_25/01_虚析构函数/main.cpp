/**
 * 基类的 析构函数应该设置为 虚析构函数，
 * 不然当 Base* base = &derive； 的时候，不会执行 Derive 的析构函数
*/

#include <iostream>

class Base{
public:
    Base( ){
        std::cout << "Base  construct" << std::endl;
    }

    virtual ~Base( ){
        std::cout << "Base destruct" << std::endl;
    }
};

class Derive : public  Base{
public:
    Derive( ){
        std::cout << "Derive construct" << std::endl;
        p = new int[5];
    }
    ~Derive( ){
        std::cout << "Derive destruct" << std::endl;
        delete[] p;
    }

private:
    int* p;

};

int main( ){
    std::cout << "No.1 ----------------" << std::endl;
    Base *base = new Base;
    delete base;

    std::cout << "No.2 ----------------" << std::endl;
    Derive *derive = new Derive;
    delete derive;

// 如果 Base 的析构函数不是 虚析构函数，No.3的例子不会调用 Derive 的析构函数
    std::cout << "No.3 ----------------" << std::endl;
    Base* base2 = new Derive();
    delete base2;

    return 0;
}
