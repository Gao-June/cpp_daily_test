/*
    浅拷贝
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
        // 要先判断自拷贝的情况
        if( this == &s ){
            return *this;
        }

        // 深拷贝
        delete[] data;      // 先清空资源
        data = new char [ strlen( s.data ) + 1 ];
        strcpy( data, s.data );

        // 浅拷贝
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

    cout << "拷贝前：" << endl;
    a1.prinT();
    a2.prinT();

    // 开始浅拷贝
    cout << "拷贝后：" << endl;
    a2= a1;
    a1.prinT();
    a2.prinT();

    // 验证 浅拷贝： 由于 data 是 private所以需要写一个函数改变个值
    cout << " 验证 浅拷贝/深拷贝 " << endl;
    //a1.data_change(2);
    a1.data[2] += 1;
    a1.prinT();
    a2.prinT();

    return 0;
}