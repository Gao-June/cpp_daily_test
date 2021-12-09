/*
    final:不希望某个类被继承（自己的类是最后的继承者）、或不希望某个虚函数被重写。
    override:它指定了子类的这个虚函数是重写父类的，名字（或参数）如果不小心打错了，编译器不会编译通过。（做了安全检查）。
*/

#include <iostream>

using namespace std;

class Base{ 
    virtual void f( ) final{
        cout << "Base final" << endl;
    }

};

class Derived : public Base{

    // 报错： 无法重写“final”函数 "Base::f" (已声明 所在行数:11)
    // void f( ){
    //     cout << "Derived func( )" << endl;
    // }
};

int main( ){


    return 0;
}