/*
    size_t ���޷��� int ����� size_t��ֵһ��������������
*/

#include <iostream>

using namespace std;

int main( ){
    size_t a = 100;
    cout << "a = " << a << endl;

    a = -100;       // a = 18446744073709551516 �ֱ�����������
    cout << "a = " << a << endl;

    a = 0;          // a - 1 = 18446744073709551615
    cout << "a - 1 = " << a - 1 << endl;

}