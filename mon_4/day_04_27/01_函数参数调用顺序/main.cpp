/**
 * ̽�� �����ڴ��ε�ʱ��ĵ���˳��
 * 
 * ���ۣ��ȵ��ú���Ĳ������ٵ���ǰ���
*/

#include <iostream>

int Get_a(  ){
    int a = 10;
    std::cout << "Get_a()" << std::endl;

    return a;
}

int Get_b(  ){
    int b = 20;
    std::cout << "Get_b()" << std::endl;

    return b;
}

int Get_c(  ){
    int c = 30;
    std::cout << "Get_c()" << std::endl;

    return c;
}

// �ȵ��� C -> B -> A
void Fun_sum( int a, int b, int c ){
    std::cout << a + b + c << std::endl;
}

int main( ){
    Fun_sum( Get_a(  ), Get_b(  ), Get_c(  ) );

    return 0;
}

