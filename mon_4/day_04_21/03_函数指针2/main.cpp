/**
 * ����һ��������ָ��1����Ϊ���֣�����дһ��ʵ��
 * ���� ����ָ�� ��Ϊ�����Ĳ������е��õ������
 *  �� ���� Func_each() ��ʹ�� Print() �������
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
    Fun_each(Nums, Print);

    return 0;
}