/**
 * ����ָ�빦�ܣ��ô�����ɾ���������4�ַ�ʽʵ�ֺ���ָ�빦��
 * 
 * ����ʽ1����ԭʼ�ķ�ʽ��������������
 * ����ʽ2������ֱ��ʹ�� auto = ������  �ķ�ʽ���к���ָ�븳ֵ
 * ����ʽ3�� typedef
 * ����ʽ4�� using
*/

#include <iostream>

int Add_nums( const int &a, const int &b )
{
    return a + b;
}


int Sub_num( const int &a, const int &b )
{
    return a - b;
}

int main()
{
    const int num1 = 10, num2 = 25;

// ��ʽ-1�� ԭʼд��
    std::cout << "No.1" << std::endl;
    int (*p)( const int &, const int & );
    p = Add_nums;
    std::cout << p(num1, num2) << std::endl;

    p = Sub_num;
    std::cout << p(num1, num2) << std::endl;


// ��ʽ-2�� auto
    std::cout << "No.2" << std::endl;
    auto q = Add_nums;
    std::cout << q(num1, num2) << std::endl;

    q = Sub_num;
    std::cout << q(num1, num2) << std::endl;


// ��ʽ-3�� typedef
    std::cout << "No.3" << std::endl;
    
    // ����� *ptr_func ���������� ����Ҫ�������ʵ����
    typedef int(*Ptr_Func)( const int&, const int& );
    Ptr_Func Ptr1 = Add_nums;
    std::cout << Ptr1(num1, num2) << std::endl;

    Ptr1 = Sub_num;
    std::cout << Ptr1(num1, num2) << std::endl;


    return 0;
}