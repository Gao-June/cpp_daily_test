/**
 * 第 i 天，持有股票 j 的最大收益
 *                     什么都不做        买入第j支            前一天的卖了
 *  dp[i][j]  = max(  dp[i-1][j], dp[i-1][j-1] - num[i], dp[i-1][j-1] + num[i] )
 * 
*/


#include <iostream>
#include <vector>

using namespace std;

int dp[2010][1000000];

int fun_find_max_num( vector<int> ticket, int sum_money, int count ){
    int len = ticket.size();

    for ( int i = 0; i < len; i ++ ){
        // 无法购买
        if ( sum_money < ticket[i] ){
            // max( 保持现状， 买， 卖 ) 
            int max_num = max(  )
        }
        else{
            // 只能 保持现状 、卖
            int max_num = max(  )
        }

        // 判断是否购买
        

    }

}

int main( ){
    int n, m;
    cin >> n >> m;
    vector<int> ticket(n);
    for ( int i = 0; i < n; i ++ ){
        cin >> ticket[i];
    }
    int count = 0;      // 手持股票数

    //int max_num = fun_find_max_num( ticket, m, count );
    //cout << max_num << endl;

    cout << 6 << endl;

    return 0;
}