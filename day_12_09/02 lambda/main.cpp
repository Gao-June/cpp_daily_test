/*
    lambda 示例
    1- 简单小示例
    2- sort() 第三个参数，让 vertor 逆序排序
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main( ){
    // 示例 1， use lambda simply
    int id = 0;
    // id 如果不是以 引用（&）形式捕获，会报错
    auto f = [ &id ] ( ) {
        cout << "now id = " << id << endl;
        id++;
    };
    f();    // now id = 0
    f();    // now id = 1
    f();    // now id = 2

    // 示例 2，更改 sort排序方式
    vector<int> nums1 = {1,4,6,3,7,8};
    // 打印初始变化：
    cout << "no1 " << endl;
    for ( auto &n1 : nums1 ){
        cout << n1 << "  ";
    }
    cout << endl;
    // 正常 sort 后
    sort( nums1.begin(), nums1.end() );
    cout << "no2  " << endl;
    for ( auto &n1 : nums1 ){
        cout << n1 << "  ";
    }
    cout << endl;

    // 使用 lambda 逆序打印
        vector<int> nums2 = {1,4,6,3,7,8};
    // 打印初始变化：
    cout << "no3 " << endl;
    for ( auto &n2 : nums2 ){
        cout << n2 << "  ";
    }
    cout << endl;
    // 正常 sort 后
    sort( nums2.begin(), nums2.end(), []( int nu1, int nu2 ){
        return nu1 > nu2;    } 
    );
    cout << "no4  " << endl;
    for ( auto &n2 : nums2 ){
        cout << n2 << "  ";
    }
    cout << endl;

    return 0;
}