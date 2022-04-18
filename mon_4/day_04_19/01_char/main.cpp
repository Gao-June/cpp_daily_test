/*
    栈区，可以更改
        char name1[5] = {'a', 'b', 'c', 'd'};
    常量区，不能更改
        char *name2 = "zxcv";
    堆区，可以更改
       char *name3= new char[5]; 
        strcpy(name3, "qwer"); 
*/


#include <iostream>
#include <cstring>

void Change_Char( char* c ){
    c[2] = 'C';
    std::cout << "Func()  " <<  c << std::endl;
}

int main( ){
    char name1[5] = {'a', 'b', 'c', 'd'};
    std::cout << "No1.  " <<  name1 << std::endl;


    char *name2 = "zxcv";   // ISO C++ forbids converting a string constant to 'char*'
    std::cout << "No2.  " <<  name2 << std::endl;
    // name2[2] = 'a';      // 数据在常量区 char* 不能被更改值
    //Change_Char(name2);   // 无结果 char* 不能被更改值

    char *name3= new char[5]; 
    strcpy(name3, "qwer");
    std::cout << "No4.  " <<  name3 << std::endl;
    Change_Char(name3);
    std::cout << "No5.  " <<  name3 << std::endl;

    return 0;
}