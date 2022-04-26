/**
 * 在 C++ 11 中，调用 new() 时会做多个拷贝，下面给出示例测试C++的拷贝次数
*/

#include <iostream>
#include <string>


static uint32_t Str_Alloc_Count = 0;

void* operator new( size_t size ){
    Str_Alloc_Count++;
    std::cout << "Allocationg " << size << " bytes\n";

    return malloc(size);
}



int main( ){
    std::string name = "Jeffy Gao";

    std::string First_Name = name.substr( 0, 5 );
    std::string_view Second_Name( name.c_str(), 5 );

    std::cout << name << "\n";
    std::cout << First_Name << "\n";
    std::cout << Second_Name << "\n";

    return 0;
}



