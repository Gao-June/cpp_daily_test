#include <iostream>

using namespace std;

int main( ){

    int i = 100;
    for ( int j = 1; j <= 10; j ++ ){
        auto f = []( int i, int j ){
            return i + j;
        };

        cout << f(i, j) << "  ";
    }

    return 0;
}