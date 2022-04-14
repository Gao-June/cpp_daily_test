// 检验 pc 电脑是大端还是小端
#include <iostream>

int main( ){
    std::cout << "hello world!" << std::endl;

    int num = 0x12345678;
    char c = num;

    // 验证了 pc 是大端
    std::cout << (int)c << std::endl;   // 120
    printf( "%d\n", c );                // 120

    return 0;
}