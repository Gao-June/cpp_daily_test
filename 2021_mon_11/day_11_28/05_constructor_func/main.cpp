/*
    默认构造函数
*/


#include <iostream>

using namespace std;

class A{
private:
    int a;
public:
    A( int temp = 1 ) : a(temp) { }

    void Print_val( ){
        cout << a << endl;
    }
};

int main(){
    A x;
    x.Print_val( );

    A y(2);
    y.Print_val( );

    return 0;
}