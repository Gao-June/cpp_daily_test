// 函数写在 .cpp里，而不是之前的 .h

#include <iostream>
#include <string>
#include "print_s.cpp"

using namespace std;

void print_s( string s );

int main(){
    string s = "hello world";
    print_s( s );

    return 0;
}