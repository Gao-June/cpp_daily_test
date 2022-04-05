// 练习一下多态
/*
    写一个多态，让基类指针指向派生类;

    1- 当基类指针向调用派生类的 函数时，可以直接调用；
    2-  ……想调用自己的 函数时，需要加作 用域运算符 ::
    3- 注意，基类所调用的函数只能是：自己在基类里的、派生类重写的虚函数、派生类的纯虚函数；派生类的普通函数无法调用。
*/

#include <iostream>
#include <string>

using namespace std;

class Animal{
private:
    string _name;

public:
    Animal( string name = "" ) : _name(name) {}

    void speak( ){
        cout << "???" << endl;
    }
    void get_name( ){
        cout << "..." << endl;
    }

    virtual void speak_virtual( ){
        cout << "基类的虚函数" << endl;
    }
};

class Dog : public Animal{
private:
    string _d_name;

public:
    Dog( string name = "" ) : _d_name( name ) {}

    void speak( ){
        cout << "wang wang wang" << endl;
    }

    void get_name( ){
        cout << _d_name << endl;
    }

    virtual void speak_virtual( ){
        cout << "dog 派生类的虚函数" << endl;
    }
};

class Cat : public Animal{
private:
    string _c_name;

public:
    Cat( string name = "" ) : _c_name( name ) {}

    void speak( ){
        cout << "miao miao miao" << endl;
    }

    void get_name( ){
        cout << _c_name << endl;
    }

    virtual void speak_virtual( ){
        cout << "cat 派生类的虚函数" << endl;
    }
};

int main( ){
    cout << "No.1" << endl;
    Dog d("dddd");
    d.speak();              // 覆盖了 基类的函数 speak()
    d.get_name();           // 覆盖了 基类的函数 get_name()
    d.Animal::speak();      // 调用 基类的函数 speak()
    d.Animal::get_name();   // 调用 基类的函数 get_name()

    cout << "No.2" << endl;
    Cat c("cccc");
    c.speak();          // 覆盖了 基类的函数 speak()
    c.get_name();           // 覆盖了 基类的函数 get_name()
    c.Animal::speak();  // 调用 基类的函数 speak()
    c.Animal::get_name();  // 调用 基类的函数 get_name()


// 开始测试 多态
// 基类指针指向派生类
// 可以看到 当基类指针 指向 派生类对象的时候， 想要运行派生类的函数只有通过 虚函数才行； 
//    不然默认运行的是 基类 的函数。例如： speak()、get_name()
    cout << "No.3" << endl;
    Animal *a = &d;         // 指向了 class Dog
    a->speak();             // 运行的是 基类 class 的函数 speak()
    a->get_name();          // 运行的是 基类 class 的函数 get_name()
    a->Animal::speak();     // 运行的是 基类 class 的函数 speak()   （同上面的 speak()的情况）
    a->speak_virtual();     // 运行的是 派生类 的函数 speak_virtual()
    a->Animal::speak_virtual();     // 运行的是 基类 的函数 speak_virtual()

    return 0;
}
