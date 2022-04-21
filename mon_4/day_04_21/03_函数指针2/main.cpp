/**
 * 与上一个（函数指针1）作为区分，这里写一个实例
 * 测试 函数指针 作为函数的参数进行调用的情况。
 *  在 函数 Func_each() 中使用 Print() 这个函数
 * 
 * 在方法-2 中给出了 lambda 代替函数指针的实例
*/

#include <iostream>
#include <vector>

// 打印元素
void Print( int Num )
{
    std::cout << "num value is : " << Num << std::endl;
}

// 遍历 vector 中的元素， 第2个参数是函数指针
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
    // 常规调用 函数指针
    Fun_each(Nums, Print);

    std::cout << "No.2" << std::endl;
    // 使用 lambda 调用
    Fun_each( Nums, [](int value) { std::cout << "num value is : " << value << std::endl; } );


    return 0;
}