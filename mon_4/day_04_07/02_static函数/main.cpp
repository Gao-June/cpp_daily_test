/*
static函数：对函数的连接方式产生影响，使得函数只在本文件内部有效，对其他文件是不可见的。
这样的函数又叫作静态函数。
使用静态函数的好处是，不用担心与其他文件的同名函数产生干扰，另外也是对函数本身的一种保护机制（隐藏）。
如果想要其他文件可以引用本地函数，则要在函数定义时使用关键字extern，表示该函数是外部函数，可供其他文件调用。
另外在要引用别的文件中定义的外部函数的文件中，使用extern声明要用的外部函数即可。
*/

// 在 main.cpp 中调用 func.cpp 里的 Sum_Nums()

#include <iostream>
#include "func.cpp"

int main( ){
    int a_num = 1, b_num = 2;

    std::cout << Sum_Nums( a_num, b_num ) << std::endl;

    return 0;
}