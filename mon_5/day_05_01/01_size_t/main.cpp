/**
 * @file main.cpp
 * @author JeffyGao  gaojune_better@qq.com
 * @version 0.1
 * @date 2022-05-02
 * @copyright Copyright (c) 2022
 * 
 * @brief 探究 size_t的使用
 *  1：strlen() 返回的是 size_t类型；
 *  2：当比较 int和 size_t时，首先会将 Num_a 转化为 size_t类型，又由于它是负数，所以转化后的大于strlen(Str_1)
 */

#include <iostream>
#include <cstring>

int main( ){
    int Num_a = -1;
    char* Str_1 = "hello";
    std::cout << "strlen(Str_1) : " << strlen(Str_1) << std::endl;

    if ( Num_a > strlen(Str_1) ){
        std::cout << " Num_a > strlen(Str_1) " << std::endl;
    }
    else{
        std::cout << " Num_a < strlen(Str_1) " << std::endl;
    }

    return 0;
}
