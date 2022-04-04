// 静态成员函数
/* 为什么需要静态成员函数：
    1 - 静态成员变量的引入，避免了重复性，所有class可以共用一个变量
    2 - 当需要访问静态成员变量的时候，有一种方法就是 实例化 class，
        然后通过函数访问，但是这样可能带来内存损耗，于是就有了“静态成员函数”
        可以无需 实例化 class 访问静态成员变量。
*/
#include <iostream>

using namespace std;

class Something
{
private:
    static int s_value;

public:
    static int getValue(){ 
        return s_value; } // static member function
};

    int Something::s_value{ 1 }; // initializer


int main()
{
    cout << Something::getValue() << '\n';

    return 0;
}