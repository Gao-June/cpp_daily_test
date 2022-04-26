#include <iostream>
#include <string>

using namespace std;

// 从 pos 开始切割
int fun_find_num( string man, int pos ){
    int left_num = 0, right_num = 0;


    for ( int i = 0; i < man.size(); i ++ ){
        // 左边进攻
        if ( i < pos && man[i] == '0' ){
            left_num += ( i + 1 );    // 编号数 = 下标 + 1；
        }
        // 右边防守
        if ( i >= pos && man[i] == '1' ){
            right_num += ( i + 1 );
        }
    }

    // 取绝对值
    return left_num > right_num ? left_num - right_num : right_num - left_num;

}

int main( ){
    int n;
    cin >> n;

    // 0 进攻， 1防守
    string man;
    cin >> man;

    int ans = 99999999;

    // 开始找最小 ans
    // pos : 左阵营进攻[0,pos)， 右阵营防守 [pos, len)
    for( int pos = 0; pos < man.size(); pos ++ ){
        ans = min( ans, fun_find_num( man, pos ) );

        // cout << "ans = " << ans << endl;
    }

    cout << ans;

    return 0;
}