/*
    ǳ����
*/

#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdlib>
// #include <cstdio>
// #include <cstring>

using namespace std;

class str{
public:
    str( const char *cstr = 0 ){
        if (cstr) {
            data = new char[ strlen(cstr) + 1 ];
            strcpy( data, cstr );
        }
        else{
            data = new char[1];
            *data = '\n';
        }
    }

    str& operator= ( const str &s ){
        // Ҫ���ж��Կ��������
        if( this == &s ){
            return *this;
        }

        // ���
        delete[] data;      // �������Դ
        data = new char [ strlen( s.data ) + 1 ];
        strcpy( data, s.data );

        // ǳ����
        // data = s.data;
        return *this;
    }

    ~str( ){
        delete []data;
    }

    void prinT( ){
        for ( int i = 0; i < strlen( data ); i ++ ){
            cout << data[i];
        }
        cout << endl;
    }

    void data_change( int i ){
        data[i] += 1;
    }

public:
    char *data;
};

int main(){
    str  a1( "hello" );
    str  a2( "world" );

    cout << "����ǰ��" << endl;
    a1.prinT();
    a2.prinT();

    // ��ʼǳ����
    cout << "������" << endl;
    a2= a1;
    a1.prinT();
    a2.prinT();

    // ��֤ ǳ������ ���� data �� private������Ҫдһ�������ı��ֵ
    cout << " ��֤ ǳ����/��� " << endl;
    //a1.data_change(2);
    a1.data[2] += 1;
    a1.prinT();
    a2.prinT();

    return 0;
}