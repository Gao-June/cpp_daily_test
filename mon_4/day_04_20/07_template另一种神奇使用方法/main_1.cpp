/**
 * ������� template ��һ�������ʹ�÷���
 * һ������������ڶ����ʱ���Ҫ�������С��
 * �� templateֻ����ʹ�õ�ʱ�� �Ž���ʵ������
 * ��˿��� ���� template ���ص�ȥ���������С 
*/

#include <iostream>

template <int N>
class Nums
{
private:
    int m_Nums[N];  // ������� template �Ļ������﷨����

public:
    int GetSize( ) const
    {
        return N;
    }
};

int main()
{
    Nums<10> num;
    std::cout << num.GetSize() << std::endl;

    return 0;
}
