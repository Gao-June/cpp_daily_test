#include <iostream>

using namespace std;

int getvalue( ){
cout << "getvalue() called" << endl;
    return 4;
}

int main(){
// cerr << "main() called" << endl;
cout << "main() called" << endl;
    cout << getvalue << endl;

    return 0;
}