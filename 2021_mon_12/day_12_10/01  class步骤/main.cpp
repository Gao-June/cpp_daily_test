/*
    问题导入：
        1- 函数返回值是传值的时候发生几次对象析构，几次拷贝？
        2- 函数的形参是值传递的时候发生几次对象构造？
*/

#include <iostream>
#include <string>

using namespace std;

class A{
public:
    A( ){
        cout << "调用构造函数" << endl;
    }

    A(const A& ){
        cout << "调用拷贝构造函数" << endl;
    }

    A& operator= ( const A& ){
        cout << "调用赋值操作符" << endl;
    }

    ~A( ){
        cout << "调用析构函数" << endl;
    }
};

A func_get_A( ){
    return A( );
}

int main( ){
    A a = func_get_A( );
    /*
        输出：
            调用构造函数
            调用析构函数
        【分析】：
            如果使用编译器优化（默认）, 则会把临时对象拷贝的那次 和 用返回值构造最终对象的拷贝的给省略了；
            也即，只有一次构造和析构
    */
   cout << "测试析构是在这之前还是之后" << endl;

    return 0;
}