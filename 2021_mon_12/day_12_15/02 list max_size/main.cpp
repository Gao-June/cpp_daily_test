/*
    使用 list max_size( ) 查看 list 的最大容量
*/

#include <iostream>
#include <list>

using namespace std;

int main( ){
    list<int> nums;
    cout << "list's max size: " << nums.max_size( ) << endl;        // 357913941

    return 0;
}
