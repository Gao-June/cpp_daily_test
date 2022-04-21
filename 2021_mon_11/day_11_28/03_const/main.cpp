/*
    练习使用 int const *p  和 int * const p
*/

#include <iostream>

using namespace std;

int main(){
    int a = 10;
    int a_temp = 20;
    
    // *p 是常量，无法修改所指向地址里的值，但是可以修改指向的地址（其它变量）
    const int *p = &a;
    cout << "no.1  a: " << a << "  *p: " << *p << endl;       // 10, 10
    a = 15;
    cout << "no.2  a: " << a << "  *p: " << *p << endl;       // 15, 15
    //*p = 30;        // wrong  read-only location '* p'
    p = &a_temp;
    cout << "no.3  a: " << a << "  *p: " << *p << endl;       // 15, 20


    int b = 100;
    int b_temp = 200;
    // q 是常量，无法修改 指向的地址，但是可以修改指向地址里的值。
    int * const q = &b;
    cout << "no.4  b: " << b << "  *q: " << *q << endl;       // 100, 100
    //q = &b_temp;        // wrong  read-only location '* q'
    *q = 150;
    cout << "no.5  b: " << b << "  *q: " << *q << endl;       //150  150


    return 0;
}