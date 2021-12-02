/*
    成员函数后面加 const，表示常量函数
    const用在成员函数后 主要是针对类的const 对象

    const对象只能调用const成员函数。
    const对象的值不能被修改，在const成员函数中修改const对象数据成员的值是语法错误
    在const函数中调用非const成员函数是语法错误

*/

#include <iostream>

using namespace std;

class Text {
public:
    Text( int a) : k(a){}

    void printconst( ) const {
        cout  <<  "hello1"  <<  endl;
    }

    void print( ) {
        cout  <<  "hello2"  <<  endl;
    }
private:
    int k;
} ;


int main(void)
{
    //定义了类Text的一常量对象
    const Text a(1);
    
    a.printconst( );     //ok
    //a.print( );      //error  a.print()调用是非法的
    
    return 0;
}



