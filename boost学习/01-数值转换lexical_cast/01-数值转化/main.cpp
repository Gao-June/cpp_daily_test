/*
#include <boost/lexical_cast.hpp>
    中定义了此函数lexical_cast使用统一接口形式实现任意类型之间的转换，增强了易用性。
如果转换发生了意外，
    lexical_cast会抛出一个bad_lexical_cast异常，因此程序中需要对其进行 try-catch。
*/

#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

int main( ){
    using boost::lexical_cast;
    using boost::bad_lexical_cast;

    try{
        // string to int
        int a = lexical_cast<int>("1234");
        // int a = lexical_cast<int>("asdefd", 4);  // wrong
        std::cout << "a = " << a << std::endl;

        // string to float/double
        float b = lexical_cast<float>("1234.576"); 
        //float b = lexical_cast<float>("1234.576abc");   // wrong
        std::cout << "b = " << b << std::endl;

        // float to string
        std::string c = lexical_cast<std::string>(b);
        std::cout << "c = " << c << std::endl;

        //  double to string
        std::string d = lexical_cast<std::string>(1.23456);
        std::cout << "d = " << d << std::endl;
    }

    // catch ( const std::exception &e )
    // 当 转换出错的时候 what() 会给出错误原因
    catch ( const bad_lexical_cast &e ){
        std::cout << e.what() << std::endl;
    }

    return 0;
}
