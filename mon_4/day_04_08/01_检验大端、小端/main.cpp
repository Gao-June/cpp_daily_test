// 检验 pc 电脑是大端还是小端
#include <iostream>

int main( ){
    std::cout << "hello world!" << std::endl;

    int num = 0x5678;
    char c = num;

    // 验证了 pc 是大端
    std::cout << (int)c << std::endl;   // 十进制 120 - 十六进制 78
    printf( "%d\n", c );                // 120

    if ( c == 0x78 ){
        std::cout << "小端存储"  << std::endl;
    }
    else if ( c == 0x12 ){
        std::cout << "大端存储"  << std::endl;
    }

    return 0;
}