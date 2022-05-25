/*
引入：
    C++在标准库中提供了字符串标准类std::string.
    它提供一些成员函数可以查找子串 find()，替换字符 replace()等基本功能.
    但是C++处理字符串的能力与其他语言如C#、Python、Java比起来；会显得很弱。

string_algo库简介：
    boost的 string_algo库是一个非常全面的字符串算法库，提供了大量字符串操作函数与算法（algorithm）
    如大小写无关比较，修剪，特定模式的子串查找等，
    可以再不使用正则表达式的情况下处理大多数字符串相关问题。
    需包含头文件: boost/agorithm/string.hpp

五大功能：
    - 大小写转换
    - 判断式与分类
    - 修剪
    - 查找与替换
    - 分割与合井

算法命名规律：
    前缀i：    有这个前缀表明算法大小写不敏感的；否则大小写敏感
    后缀copy：  有这个后缀表明算法不变动输入，返回处理结果的拷贝，否则算法原地处理，输入即输出
    后缀if：    有这个后缀表明算法需要一个作为判断式的谓词函数对象，否则使用默认的判断准则

简单示例：
- 大小写转换：
    void to_upper( T &Input );      // 大写，改变原字符串
    void to_lower( T &Input );      // 小写，改变原字符串
    T to_upper_copy( T &Input );    // 大写，不改变原字符串
    T to_lower_copy( T &Input );    // 小写，不改变原字符串  
- 判断式：可以检测两个字符串之间的关系：
    算法
    lexicographical_compare( T &str1, T &str2 ); 根据字典序检测一个字符串是否小于另一个字符串
    starts_with( T &str1, T &str2 );             检测字符串是否以另一个字符串为 前缀
    ends_with( T &str1, T &str2 );               检测字符串是否以另一个字符串为 后缀
    contains( T &str1, T &str2 );                检测字符串是否包含另一个字符串
    eauqls( T &str1, T &str2 );                  检测两个字符串 是否相等
    all( T &str1, T &str2 );                     检测字符串是否满足指定的判断式
    【注】以上算法都有另一个 “ i ” 前缀的版本。由于不改变字符串，因此不包含“ copy ”版本
    【返回】 bool 类型
    
    函数对象
    is_eauql()( T &str1, T &str2 );      与 eauals 算法类似，比较两个对象是否相等
    is_less()( T &str1, T &str2 );       比较两个对象是否有 小于关系
    is_not_greater( T &str1, T &str2 );  比较两个对象是否有 不大于关系
    【注】函数对象名称后的两个括号，第一个括号调用了函数对象的构造函数，产生了一个临时对象；
                                 第二个括号才是真正的函数调用 operator( )
    【返回】 bool 类型

- 分类：用于检测一个字符是否符号某种特性，主要用于搭配其它算法
    “懒得写了”

*/

#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace boost;

int main( ){
std::cout << "No.1\t大小写转换： " << std::endl;

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

std::cout << "No.2\t判断式：算法 " << std::endl;
    std::cout << "\t测试  A < a ? " << ('A' < 'a') << std::endl;
    std::string str2_1_1("HellO,World");
    std::string str2_1_2("Hello,world");
    std::cout << "\ttest_2.1.1\t" << lexicographical_compare(str2_1_1, str2_1_2) << std::endl;
    std::cout << "\ttest_2.1.2\t" << ilexicographical_compare(str2_1_1, str2_1_2) << std::endl;

    std::cout << "\t后面的类似，就不演示了" << std::endl;

std::cout << "No.3\t判断式：函数 " << std::endl;
    std::string str3_1_1("HellO,World");
    std::string str3_1_2("Hello,world");
    std::cout << "\t测试  A < a ? " << ('A' < 'a') << std::endl;
    std::cout << "\t" << is_equal()(str3_1_1, str3_1_2) << std::endl;
    is_equal ie;
    std::cout << "\t等价于上面的写法\t" << ie(str3_1_1, str3_1_2) << std::endl;

    std::string str3_2_1("HellO,World");
    std::string str3_2_2("Hello,world");
    std::cout << "\t" << is_less()(str3_2_1, str3_2_2) << std::endl;

    // 很奇怪，这个为啥运行不出来？
    // std::cout << is_iless()(str3_2_1, str3_2_2) << std::endl;


    return 0;
}
