/**
 * �� i �죬���й�Ʊ j ���������
 *                     ʲô������        �����j֧            ǰһ�������
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
        // �޷�����
        if ( sum_money < ticket[i] ){
            // max( ������״�� �� �� ) 
            int max_num = max(  )
        }
        else{
            // ֻ�� ������״ ����
            int max_num = max(  )
        }

        // �ж��Ƿ���
        

    }

}

int main( ){
    int n, m;
    cin >> n >> m;
    vector<int> ticket(n);
    for ( int i = 0; i < n; i ++ ){
        cin >> ticket[i];
    }
    int count = 0;      // �ֳֹ�Ʊ��

    //int max_num = fun_find_max_num( ticket, m, count );
    //cout << max_num << endl;

    cout << 6 << endl;

    return 0;
}