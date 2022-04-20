/**
 * 这里介绍 template 另一种神奇的使用方法
 * 一般情况，数组在定义的时候就要声明其大小，
 * 又 template只有在使用的时候 才进行实例化，
 * 因此可以 利用 template 的特点去定义数组大小 
*/

#include <iostream>

template <int N>
class Nums
{
private:
    int m_Nums[N];  // 如果不是 template 的话会有语法错误

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
