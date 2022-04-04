/*
    主要研究 static_cast 里面关于类的转换
*/

#include <iostream>

using namespace std;

class base{
public:
    void prinT( ) const{
        cout << "this is base! " << endl;
    }

    int m = 1;

};

// 注意，这里需要写上 public，不然报错
class son : public base{
public:
    void prinT( ) const{
        cout << "this is son !" << endl;
    }
};

int main(){
    base f1;
    son s1;

    // 都可以独立地打印自己的 函数
    cout << "no1. " << endl;
    f1.prinT();
    s1.prinT( );

    cout << "no2. " << endl;
    son s2;
    base &f2 = s2; // upcast via implicit conversion
    f2.prinT();

    son& s3 = static_cast< son& >( f2 );    // 向下兼容
    //son &s3 = f2;   // 这样写报错，无法用 "base" 类型的值初始化 "son &" 类型的引用
    s3.prinT();


    return 0;
}