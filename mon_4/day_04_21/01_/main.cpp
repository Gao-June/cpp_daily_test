#include <iostream>
#include <string>

// 使用 using，这里记得加 ;
using string = std::string;

int main()
{
    string str("hello world!");
    std::cout << str << std::endl;

    return 0;
}