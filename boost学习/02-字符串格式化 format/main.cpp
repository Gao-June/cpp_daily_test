/*
问题引入：
    在字符串处理中少不了格式化字符串；
    C++中传统的格式化函数是C语言的 printf、sprintf，
        但它一个很大的问题就是不安全。
    因此，在STL中引入了 stringstream来实现安全格式化，
        但是 stringstream却远不如 sprintf来得直观。
Boost-format:
    boost::format提供了一个和C的 printf类似的格式化字串语法定义，
        同时也保有了C++的 ostraem的各项优势，
        对于要做格式化输出的C++程序开发人员来说，
        boost::format是个相当好用的函数库。
使用format需包含头文件boost/format.hpp

使用方法：
    用 %数字% 来表示读入的顺序
*/

#include <iostream>
#include <string>
#include <boost/format.hpp>

using namespace boost;

int main( ){

    std::cout << "使用1" << std::endl;
    format fmt1( "%1%  ,  %2%   !" );       // 先定义对象
    fmt1 % 123;
    fmt1 % "hello";
    std::cout << fmt1 << std::endl;

    std::cout << "使用2\t可以不按顺序，可以重复指定" << std::endl;
    format fmt2( " %2%  ----- %1% -----   %2%  !!!" );
    fmt2 % 123;
    fmt2 % "hello";
    std::cout << fmt2 << std::endl;

    std::cout << "使用3\t可以重复使用" << std::endl;
    format fmt3( " %2%  ----- %1% -----   %2%  !!!" );
    fmt3 % "hello";
    fmt3 % 123;
    std::cout << fmt3 << std::endl;

    fmt3 % 1.23456;
    fmt3 % 'C';
    std::cout << fmt3 << std::endl;

    std::cout << "使用4\t链式使用" << std::endl;
    std::cout << format( "****%1%****%2%!!!" ) % "hello"   %1.2345f << std::endl;
    std::cout << (format( "****%1%****%2%!!!" ) % "hello") %6.78980f << std::endl;

    std::cout << "使用5\tN$指定用哪个参数" << std::endl;
    std::cout << format("---%2$s -----%1$s---")  %"Boost" % "Hello"<< std::endl;

    std::cout << "使用5\t自定义使用试试" << std::endl;
    std::string st1("hello,world");
    int num1 = 18;
    format fmt5( " %2%  ----- %1% -----   %2%  !!!" );
    fmt5 % num1;
    fmt5 % st1;
    std::cout  << fmt5 << std::endl;

    return 0;
}