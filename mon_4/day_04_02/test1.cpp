#include <iostream>

using namespace std;

int main( ){
    int x = 0;

Try_Again:
    cout << "ÊäÈë x µÄÖµ£º ";
    cin >> x;

    if ( 0 == x ){
        goto Try_Again;
    } 
    cout << x << endl;


    return 0;
}