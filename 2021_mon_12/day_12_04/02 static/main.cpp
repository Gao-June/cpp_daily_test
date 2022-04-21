/*
    练习一下static的写法
    刚才上传的时候中文乱码了，改成 GB 2312再试试看
*/

#include <iostream>

using namespace std;

class base{
public:
    int a, b;
    static int c;

    base( int i = 0, int j = 0 ) : a(i), b(j){}

    void get_c( ){
        cout << c << endl;
    }
    void get_num( ){
        cout << "a: " << a << "  b: " << b << endl;
    }
};

    int base::c = 1;

int main( ){
    base num1(1,2);
    base num2(3,4);

    cout << "no1.  " << endl;
    num1.get_num();
    num2.get_num();
    num1.get_c();
    num2.get_c();

    cout << "no2. " << endl;
    num1.a = 10;
    num2.b = 15;
    num1.c = 18;
    num1.get_num();
    num2.get_num();
    num1.get_c();
    num2.get_c();

    cout << "no3. " << endl;
    num2.c = 20;
    num1.get_num();
    num2.get_num();
    num1.get_c();
    num2.get_c();

    return 0;
}