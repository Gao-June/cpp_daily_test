/*
�������룺
    ���ַ����������ٲ��˸�ʽ���ַ�����
    C++�д�ͳ�ĸ�ʽ��������C���Ե� printf��sprintf��
        ����һ���ܴ��������ǲ���ȫ��
    ��ˣ���STL�������� stringstream��ʵ�ְ�ȫ��ʽ����
        ���� stringstreamȴԶ���� sprintf����ֱ�ۡ�
Boost-format:
    boost::format�ṩ��һ����C�� printf���Ƶĸ�ʽ���ִ��﷨���壬
        ͬʱҲ������C++�� ostraem�ĸ������ƣ�
        ����Ҫ����ʽ�������C++���򿪷���Ա��˵��
        boost::format�Ǹ��൱���õĺ����⡣
ʹ��format�����ͷ�ļ�boost/format.hpp

ʹ�÷�����
    �� %����% ����ʾ�����˳��
*/

#include <iostream>
#include <string>
#include <boost/format.hpp>

using namespace boost;

int main( ){

    std::cout << "ʹ��1" << std::endl;
    format fmt1( "%1%  ,  %2%   !" );       // �ȶ������
    fmt1 % 123;
    fmt1 % "hello";
    std::cout << fmt1 << std::endl;

    std::cout << "ʹ��2\t���Բ���˳�򣬿����ظ�ָ��" << std::endl;
    format fmt2( " %2%  ----- %1% -----   %2%  !!!" );
    fmt2 % 123;
    fmt2 % "hello";
    std::cout << fmt2 << std::endl;

    std::cout << "ʹ��3\t�����ظ�ʹ��" << std::endl;
    format fmt3( " %2%  ----- %1% -----   %2%  !!!" );
    fmt3 % "hello";
    fmt3 % 123;
    std::cout << fmt3 << std::endl;

    fmt3 % 1.23456;
    fmt3 % 'C';
    std::cout << fmt3 << std::endl;

    std::cout << "ʹ��4\t��ʽʹ��" << std::endl;
    std::cout << format( "****%1%****%2%!!!" ) % "hello"   %1.2345f << std::endl;
    std::cout << (format( "****%1%****%2%!!!" ) % "hello") %6.78980f << std::endl;

    std::cout << "ʹ��5\tN$ָ�����ĸ�����" << std::endl;
    std::cout << format("---%2$s -----%1$s---")  %"Boost" % "Hello"<< std::endl;

    std::cout << "ʹ��5\t�Զ���ʹ������" << std::endl;
    std::string st1("hello,world");
    int num1 = 18;
    format fmt5( " %2%  ----- %1% -----   %2%  !!!" );
    fmt5 % num1;
    fmt5 % st1;
    std::cout  << fmt5 << std::endl;

    return 0;
}