// ��ϰ �����Ƶ� BOOST_AUTO/BOOST_TYPEOF
/*
auto:
    C++11�±�׼�������������Զ��ƶϣ�auto�ؼ����ñ�����ͨ����ʼֵ�������������ݡ�
    �Ӷ���ö�����������ͣ�auto����ı��������г�ʼֵ��

decltype:
    C++11�±�׼����ʱ�����Ƶ�������auto�ؼ��֣����� decltype�ؼ��֣� 
    decltype������autoһ���Ǵӱ����ĳ�ʼ�����ʽ������ͣ������Ա��ʽ��Ϊ������
    ���ظñ��ʽ�����Ͳ��� decltype����Ա��ʽ��ֵ��
*/

#include <iostream>
#include <boost/typeof/typeof.hpp>

int main( ){
std::cout << "auto:" << std::endl;
    auto a = 100;
    std::cout << typeid(a).name() << std::endl;

std::cout << "decltype:" << std::endl;
    decltype(1.23f) b;
    std::cout << typeid(b).name() << std::endl;

    decltype(a++)  c;
    std::cout << "a is: " << a << "\t" << typeid(c).name() << std::endl;

    decltype( &c )  d;
    std::cout << typeid(d).name() << std::endl;

std::cout << "BOOST:" << std::endl;
    BOOST_TYPEOF(1.23f) bb;
    std::cout << typeid(bb).name() << std::endl;

    return 0;
}