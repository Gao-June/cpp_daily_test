/**
 *  在 main_1.cpp 的基础上 继续让 template更加抽象
 * 
*/

#include <iostream>

// 使用了 T， 让这个class更加抽象化
template <typename T, int N>
class Nums
{
private:
    T m_Nums[N];  // 如果不是 template 的话会有语法错误

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
