/*
    ��ͨ���������ܼ� const ��
    ���ܣ� ֻ�� ��Ա���� �ſ���
    ��ע����Ա������� const ��Ŀ����Ϊ�� ��ֹ��class���Ա�����ĸ��ġ�
*/

#include <iostream>

using namespace std;

// ��ͨ������ �������� const
int sum( int a, int b ) const {
    return a + b;
}

int main( ){
    int a = 10, b = 20;

    // ���� on-member function 'int sum(int, int)' cannot have cv-qualifier
    cout << sum( a, b ) << endl;

    return 0;
}