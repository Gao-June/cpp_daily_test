/*
    练习 tuple 元组
*/

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

tuple<string, int > func( void ){
    tuple<string, int> temp( "hello", 123 );

    return temp;
}

int main( ){
    // test -1 函数返回 tuple元组容器
    cout << "test 1" << endl;
    auto a = func( );
    cout << get<0>(a) << "  -  " << get<1>(a) << endl;

    // test -2 得到元组的个数
    cout << "test 2" << endl;
    tuple<int, double, string> t1( 64, 1.234, "world!" );
    tuple<string, string, int> t2 = make_tuple( "hello", "world", 55 );

    // 获得 t1 元组元素的个数
    size_t num_t1 = tuple_size< decltype(t1) > :: value;
    cout << num_t1 << endl;     // 3

    // 获得 t1 元组第二个元素的值
    cout << "test 3" << endl;
    tuple_element<1, decltype(t1)> :: type val = get<1>(t1);
    cout << "val = " << val << endl;

    // 比较
    cout << "test 4" << endl;
    tuple<int, int> n1( 24, 48 );
    tuple<double, double> n2( 28.01, 56 );
    bool b = (n1 < n2);
    cout << " b = " << b << endl;

    return 0;
}