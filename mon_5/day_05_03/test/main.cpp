// Ëæ±ãÊÔÊÔ
#include <iostream>
#include <string>

std::string func( std::string str1, std::string str2 ){
    return str1.size() <= str2.size() ? str1 : str2;
}

int main(){
    const std::string s1("abcde");
    const std::string s2("abcdefg");

    std::cout << func(s1, s2) << std::endl;

    return 0;
}