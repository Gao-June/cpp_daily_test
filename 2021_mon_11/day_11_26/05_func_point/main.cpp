#include <iostream>

using namespace std;

int Sum( int a, int b ){
    return a + b;
}

int main(){

    int (*p)(int ,int);
    p = Sum;

    cout << p(1,2) << endl;

    return 0;
}