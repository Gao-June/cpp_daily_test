/**
 *  �� main_1.cpp �Ļ����� ������ template���ӳ���
 * 
*/

#include <iostream>

// ʹ���� T�� �����class���ӳ���
template <typename T, int N>
class Nums
{
private:
    T m_Nums[N];  // ������� template �Ļ������﷨����

public:
    int GetSize( ) const
    {
        return N;
    }
};

int main()
{
    Nums<int, 20> num;
    std::cout << num.GetSize() << std::endl;

    return 0;
}
