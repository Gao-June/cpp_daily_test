// ���� pc �����Ǵ�˻���С��
#include <iostream>

int main( ){
    std::cout << "hello world!" << std::endl;

    int num = 0x5678;
    char c = num;

    // ��֤�� pc �Ǵ��
    std::cout << (int)c << std::endl;   // ʮ���� 120 - ʮ������ 78
    printf( "%d\n", c );                // 120

    if ( c == 0x78 ){
        std::cout << "С�˴洢"  << std::endl;
    }
    else if ( c == 0x12 ){
        std::cout << "��˴洢"  << std::endl;
    }

    return 0;
}