#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main( ){

// 初始化数据
    int n;
    cin >> n;
    vector<string> nums;
    for( int i = 0; i < n; i ++ ){
        string temp;
        cin >> temp;
        nums.push_back( temp );
    }
    int str_length = nums[0].size();

    vector<string> ans(str_length);

// 开始竖着读
    bool flag = false;      // 记录是否遇到非0值
    // 读列
    for( int j = 0; j < str_length; j ++ ){
        // 读行
        for ( int i = 0; i < n; i ++ ){
            if( nums[i][j] == '0' && !flag ){
                continue;
            }
            ans[j].push_back( nums[i][j] );
            flag = true;
        }
        flag = false;
    }

    // 字符串转数字
    vector<int> ans_num(str_length);
    for( int i = 0; i < str_length; i ++ ){
        ans_num[i] = stoi( ans[i] );
    }

// 从小到大排序
    sort( ans_num.begin(), ans_num.end() );

// 输出答案
    for( int i = 0; i < ans_num.size(); i ++ ){
        cout << ans_num[i] << " ";
    }

    return 0;
}