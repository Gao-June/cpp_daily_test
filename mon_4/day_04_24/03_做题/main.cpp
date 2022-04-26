#include <iostream>
#include <string>

using namespace std;

// �� pos ��ʼ�и�
int fun_find_num( string man, int pos ){
    int left_num = 0, right_num = 0;


    for ( int i = 0; i < man.size(); i ++ ){
        // ��߽���
        if ( i < pos && man[i] == '0' ){
            left_num += ( i + 1 );    // ����� = �±� + 1��
        }
        // �ұ߷���
        if ( i >= pos && man[i] == '1' ){
            right_num += ( i + 1 );
        }
    }

    // ȡ����ֵ
    return left_num > right_num ? left_num - right_num : right_num - left_num;

}

int main( ){
    int n;
    cin >> n;

    // 0 ������ 1����
    string man;
    cin >> man;

    int ans = 99999999;

    // ��ʼ����С ans
    // pos : ����Ӫ����[0,pos)�� ����Ӫ���� [pos, len)
    for( int pos = 0; pos < man.size(); pos ++ ){
        ans = min( ans, fun_find_num( man, pos ) );

        // cout << "ans = " << ans << endl;
    }

    cout << ans;

    return 0;
}