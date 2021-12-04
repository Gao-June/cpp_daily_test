/*
    ��Ҫ�о� static_cast ����������ת��
*/

#include <iostream>

using namespace std;

class base{
public:
    void prinT( ) const{
        cout << "this is base! " << endl;
    }

    int m = 1;

};

// ע�⣬������Ҫд�� public����Ȼ����
class son : public base{
public:
    void prinT( ) const{
        cout << "this is son !" << endl;
    }
};

int main(){
    base f1;
    son s1;

    // �����Զ����ش�ӡ�Լ��� ����
    cout << "no1. " << endl;
    f1.prinT();
    s1.prinT( );

    cout << "no2. " << endl;
    son s2;
    base &f2 = s2; // upcast via implicit conversion
    f2.prinT();

    son& s3 = static_cast< son& >( f2 );    // ���¼���
    //son &s3 = f2;   // ����д�����޷��� "base" ���͵�ֵ��ʼ�� "son &" ���͵�����
    s3.prinT();


    return 0;
}