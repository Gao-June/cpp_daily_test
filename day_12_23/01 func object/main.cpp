/*
    写一个仿函数operator 来实现之前得 Lambda功能（逆序排序）
    试试可不可行
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class func_d{
public:
    bool operator( )( int &a, int &b ){
        return a > b;
    }
} func_d;

int main( ){
    vector<int> nums1{1,4,7,9,7,5,3};
    cout << "no.1 " << endl;
    for( auto &n : nums1 ){
        cout << n << "  ";
    }
    cout << endl;

    // 法-1 用 lambda 写
    sort( nums1.begin(), nums1.end(), [](int a, int b){
        return a > b;
    });
    cout << "no.2 " << endl;
    for( auto &n : nums1 ){
        cout << n << "  ";
    }
    cout << endl;


    // 法-2 用仿函数写
    vector<int> nums2{1,4,7,9,7,5,3};
    cout << "no.3 " << endl;
    for( auto &n : nums2 ){
        cout << n << "  ";
    }
    cout << endl;

    sort( nums2.begin(), nums2.end(), func_d );
    cout << "no.4 " << endl;
    for( auto &n : nums2 ){
        cout << n << "  ";
    }
    cout << endl;

    return 0;
}
