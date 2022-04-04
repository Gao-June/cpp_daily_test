#include <iostream>

using namespace std;

int main(){
    int a = 10;
    const int *p = &a;
    cout << "a: " << a << "  p: " << *p << endl;


    int *q = const_cast<int*>(p);
    *q = 20;
    cout << "a: " << a << "  p: " << *p << endl;


    return 0;
}