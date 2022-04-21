/**
 * ����һ��������ָ��1����Ϊ���֣�����дһ��ʵ��
 * ���� ����ָ�� ��Ϊ�����Ĳ������е��õ������
 *  �� ���� Func_each() ��ʹ�� Print() �������
 * 
 * �ڷ���-2 �и����� lambda ���溯��ָ���ʵ��
*/

#include <iostream>
#include <vector>

// ��ӡԪ��
void Print( int Num )
{
    std::cout << "num value is : " << Num << std::endl;
}

// ���� vector �е�Ԫ�أ� ��2�������Ǻ���ָ��
void Fun_each( std::vector<int> Nums, void(*Ptr)(int) )
{
    for (auto &num : Nums )
    {
        Ptr( num );
    }
}

int main()
{
    std::vector<int> Nums{1,3,5,7,3};

    std::cout << "No.1" << std::endl;
    // ������� ����ָ��
    Fun_each(Nums, Print);

    std::cout << "No.2" << std::endl;
    // ʹ�� lambda ����
    Fun_each( Nums, [](int value) { std::cout << "num value is : " << value << std::endl; } );


    return 0;
}