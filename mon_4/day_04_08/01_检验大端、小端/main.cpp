// ���� pc �����Ǵ�˻���С��
#include <iostream>

int main( ){
    std::cout << "hello world!" << std::endl;

    int num = 0x12345678;
    char c = num;

    // ��֤�� pc �Ǵ��
    std::cout << (int)c << std::endl;   // 120
    printf( "%d\n", c );                // 120

    return 0;
}