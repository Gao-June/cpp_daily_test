#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main( ){

// ��ʼ������
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

// ��ʼ���Ŷ�
    bool flag = false;      // ��¼�Ƿ�������0ֵ
    // ����
    for( int j = 0; j < str_length; j ++ ){
        // ����
        for ( int i = 0; i < n; i ++ ){
            if( nums[i][j] == '0' && !flag ){
                continue;
            }
            ans[j].push_back( nums[i][j] );
            flag = true;
        }
        flag = false;
    }

    // �ַ���ת����
    vector<int> ans_num(str_length);
    for( int i = 0; i < str_length; i ++ ){
        ans_num[i] = stoi( ans[i] );
    }

// ��С��������
    sort( ans_num.begin(), ans_num.end() );

// �����
    for( int i = 0; i < ans_num.size(); i ++ ){
        cout << ans_num[i] << " ";
    }

    return 0;
}