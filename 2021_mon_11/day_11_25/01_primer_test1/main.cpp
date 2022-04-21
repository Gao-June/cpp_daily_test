#include <iostream>

using namespace std;

int main(){

    int a = 10;
    int b = 100;
    const int *p = &a;

    cout << "a : " << a << "  b: " << b  << "  p: " << p << "  *p:  " << *p << endl;
    a = 20;
    cout << "a : " << a <<  "  b: " << b  << "  p: " << p << "  *p:  " << *p << endl;

    //*p = 100;
    cout << "a : " << a <<  "  b: " << b  << "  p: " << p << "  *p:  " << *p << endl;

    cout << " changed " << endl;
    int *const q = &a;

    cout << "a : " << a << "  b: " << b  << "  q: " << q << "  *q:  " << *q << endl;
    a = 20;
    cout << "a : " << a <<  "  b: " << b  << "  q: " << q << "  *q:  " << *q << endl;

    //q = &b;
    cout << "a : " << a <<  "  b: " << b  << "  q: " << q << "  *q:  " << *q << endl;

    return 0;
}