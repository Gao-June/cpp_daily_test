/**
 * @file main.cpp
 * @author JeffyGao  gaojune_better@qq.com
 * @version 0.1
 * @date 2022-05-02
 * @copyright Copyright (c) 2022
 * 
 * @brief ̽�� size_t��ʹ��
 *  1��strlen() ���ص��� size_t���ͣ�
 *  2�����Ƚ� int�� size_tʱ�����ȻὫ Num_a ת��Ϊ size_t���ͣ����������Ǹ���������ת����Ĵ���strlen(Str_1)
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
