#include <iostream>

using namespace std;

#define flag_num 1

int main( ){
    int a = 10;



#ifdef flag_num == 1
    cout << "No.1 " << endl;
#endif

#ifdef flag_num == 2
    cout << "No.2 " << endl;
#endif

    cout << a << endl;

    return 0;
}