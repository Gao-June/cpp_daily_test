// ���������
// ע��������������α�����

#include <iostream>
#include <random>

using namespace std;

int main( ){
    mt19937 rand_num;

    for( int i = 1; i <= 20; i ++ ){
        cout <<  rand_num()%100 << '\t';

        if ( i % 5 == 0 ){
            cout << endl;
        }
    }


    return 0;
}