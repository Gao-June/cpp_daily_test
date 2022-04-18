/*
    ջ�������Ը���
        char name1[5] = {'a', 'b', 'c', 'd'};
    �����������ܸ���
        char *name2 = "zxcv";
    ���������Ը���
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
    // name2[2] = 'a';      // �����ڳ����� char* ���ܱ�����ֵ
    //Change_Char(name2);   // �޽��? char* ���ܱ�����ֵ

    char *name3= new char[5]; 
    strcpy(name3, "qwer");
    std::cout << "No4.  " <<  name3 << std::endl;
    Change_Char(name3);
    std::cout << "No5.  " <<  name3 << std::endl;

    return 0;
}