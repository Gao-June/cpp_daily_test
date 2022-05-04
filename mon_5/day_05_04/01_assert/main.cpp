/**
 * 学习 assert 的用法
 * 
 * 如果 assert 中返回 false的话，程序直接终止。
 */

#include <iostream>
#include <cassert>

int main(){
    int a = 3., b = 4;
    assert( a > b );

    std::cout << "there" << std::endl;

    return 0;
}