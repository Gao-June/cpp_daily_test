/*
���룺
    C++�ڱ�׼�����ṩ���ַ�����׼��std::string.
    ���ṩһЩ��Ա�������Բ����Ӵ� find()���滻�ַ� replace()�Ȼ�������.
    ����C++�����ַ���������������������C#��Python��Java�����������Եú�����

string_algo���飺
    boost�� string_algo����һ���ǳ�ȫ����ַ����㷨�⣬�ṩ�˴����ַ��������������㷨��algorithm��
    ���Сд�޹رȽϣ��޼����ض�ģʽ���Ӵ����ҵȣ�
    �����ٲ�ʹ��������ʽ������´��������ַ���������⡣
    �����ͷ�ļ�: boost/agorithm/string.hpp

����ܣ�
    - ��Сдת��
    - �ж�ʽ�����
    - �޼�
    - �������滻
    - �ָ���Ͼ�

�㷨�������ɣ�
    ǰ׺i��    �����ǰ׺�����㷨��Сд�����еģ������Сд����
    ��׺copy��  �������׺�����㷨���䶯���룬���ش������Ŀ����������㷨ԭ�ش������뼴���
    ��׺if��    �������׺�����㷨��Ҫһ����Ϊ�ж�ʽ��ν�ʺ������󣬷���ʹ��Ĭ�ϵ��ж�׼��

��ʾ����
- ��Сдת����
    void to_upper( T &Input );      // ��д���ı�ԭ�ַ���
    void to_lower( T &Input );      // Сд���ı�ԭ�ַ���
    T to_upper_copy( T &Input );    // ��д�����ı�ԭ�ַ���
    T to_lower_copy( T &Input );    // Сд�����ı�ԭ�ַ���  
- �ж�ʽ�����Լ�������ַ���֮��Ĺ�ϵ��
    �㷨
    lexicographical_compare( T &str1, T &str2 ); �����ֵ�����һ���ַ����Ƿ�С����һ���ַ���
    starts_with( T &str1, T &str2 );             ����ַ����Ƿ�����һ���ַ���Ϊ ǰ׺
    ends_with( T &str1, T &str2 );               ����ַ����Ƿ�����һ���ַ���Ϊ ��׺
    contains( T &str1, T &str2 );                ����ַ����Ƿ������һ���ַ���
    eauqls( T &str1, T &str2 );                  ��������ַ��� �Ƿ����
    all( T &str1, T &str2 );                     ����ַ����Ƿ�����ָ�����ж�ʽ
    ��ע�������㷨������һ�� �� i �� ǰ׺�İ汾�����ڲ��ı��ַ�������˲������� copy ���汾
    �����ء� bool ����
    
    ��������
    is_eauql()( T &str1, T &str2 );      �� eauals �㷨���ƣ��Ƚ����������Ƿ����
    is_less()( T &str1, T &str2 );       �Ƚ����������Ƿ��� С�ڹ�ϵ
    is_not_greater( T &str1, T &str2 );  �Ƚ����������Ƿ��� �����ڹ�ϵ
    ��ע�������������ƺ���������ţ���һ�����ŵ����˺�������Ĺ��캯����������һ����ʱ����
                                 �ڶ������Ų��������ĺ������� operator( )
    �����ء� bool ����

- ���ࣺ���ڼ��һ���ַ��Ƿ����ĳ�����ԣ���Ҫ���ڴ��������㷨
    ������д�ˡ�

*/

#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace boost;

int main( ){
std::cout << "No.1\t��Сдת���� " << std::endl;

    std::string str1_1( "Hello, World" );
    std::cout << "\ttest_1.1\t" << str1_1 << std::endl;
    to_upper(str1_1);
    std::cout << "\ttest_1.2\t" << str1_1 << std::endl;

    std::string str1_2( "Hello, World" );
    to_lower(str1_2);
    std::cout << "\ttest_1.3\t" << str1_2 << std::endl;

    std::string str1_3( "Hello, World" );
    std::string str1_3_1 = to_lower_copy(str1_3);
    std::cout << "\ttest_1.4\t" << str1_3 << "\t to \t" << str1_3_1 << std::endl;

    std::string str1_4( "Hello, World" );
    std::string str1_4_1 = to_upper_copy(str1_4);
    std::cout << "\ttest_1.5\t" <<  str1_4 << "\t to \t" << str1_4_1 << std::endl;

std::cout << "No.2\t�ж�ʽ���㷨 " << std::endl;
    std::cout << "\t����  A < a ? " << ('A' < 'a') << std::endl;
    std::string str2_1_1("HellO,World");
    std::string str2_1_2("Hello,world");
    std::cout << "\ttest_2.1.1\t" << lexicographical_compare(str2_1_1, str2_1_2) << std::endl;
    std::cout << "\ttest_2.1.2\t" << ilexicographical_compare(str2_1_1, str2_1_2) << std::endl;

    std::cout << "\t��������ƣ��Ͳ���ʾ��" << std::endl;

std::cout << "No.3\t�ж�ʽ������ " << std::endl;
    std::string str3_1_1("HellO,World");
    std::string str3_1_2("Hello,world");
    std::cout << "\t����  A < a ? " << ('A' < 'a') << std::endl;
    std::cout << "\t" << is_equal()(str3_1_1, str3_1_2) << std::endl;
    is_equal ie;
    std::cout << "\t�ȼ��������д��\t" << ie(str3_1_1, str3_1_2) << std::endl;

    std::string str3_2_1("HellO,World");
    std::string str3_2_2("Hello,world");
    std::cout << "\t" << is_less()(str3_2_1, str3_2_2) << std::endl;

    // ����֣����Ϊɶ���в�������
    // std::cout << is_iless()(str3_2_1, str3_2_2) << std::endl;


    return 0;
}
