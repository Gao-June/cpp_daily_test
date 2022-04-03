// 函数名也是地址

#include <iostream>

using namespace std;

int add_nums( int a, int b ){
    return a + b;
}

int main( ){
    int x = 1, y  = 2;
    cout << x + y << endl;
    cout << add_nums( x, y ) << endl;
    cout << add_nums << endl;

    cout << reinterpret_cast<void *>( add_nums ) << endl;

    return 0;
}