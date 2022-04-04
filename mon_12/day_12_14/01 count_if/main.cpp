/*
    研究 count_if 的使用

    标准库里的count_if可以统计容器中满足特定条件的元素的个数。

    另，本代码尝试了使用 lambda 实现
*/

#include <iostream>
#include <algorithm>    // count_if
#include <vector>

using namespace std;

// 例如要统计一个整数vector——ivec中正数的个数，可以先写一个返回类型为bool，含有一个int参数的条件函数：
bool func_big_to_10( int num ){
    return num > 10;
}

int main( ){
    vector<int> nums{1,5,34,54,76,2,4,23};

    int n1 = count_if( nums.begin(), nums.end(), func_big_to_10);

    cout << n1 << endl;      // 4

    // test 2 使用 lambda 实现
    int n2 = count_if( nums.begin(), nums.end(), [ ]( const int num)->bool{
        return num > 10;
    } );
    cout << n2 << endl;     // 4
    return 0;
}