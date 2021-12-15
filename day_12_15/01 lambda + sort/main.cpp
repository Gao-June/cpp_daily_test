/*
    用 Lambda 实现 sort 逆序
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main( ){
    vector<int> nums{ 1,4,6,3,7,2 };

    cout << "befor: " << endl;
    for ( int i = 0; i < nums.size(); i ++ ){
        cout << nums[i] << "  ";
    }

    cout << endl << "after: " << endl;
    sort( nums.begin(), nums.end(), [](int a, int b){ return a > b; } );
    for ( int j = 0; j < nums.size( ); j ++ ){
        cout << nums[j] << "  ";
    }
    cout << endl;

    return 0;
}
