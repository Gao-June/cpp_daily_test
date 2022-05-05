/**
 * for_each 是 C++11 里的新特性
 * 定义在头文件 <algorithm> 里
 * 
 * 形式：
 *  template< class InputIt, class UnaryFunction >
 *  UnaryFunction for_each( InputIt first, InputIt last, UnaryFunction f );
 * 说明：
 *  1) 按顺序将给定的函数对象f应用于取消引用 range 中的每个迭代器的结果[first, last)。
 *  2) 将给定的函数对象f应用于取消引用范围内每个迭代器的结果[first, last)（不一定按顺序）。
 * 【注】  这个 for_each好像是要配合 lambda/仿函数 使用的哦。
 *        在使用累加的时候，要自定义 operator()
 * 测试：
 *  写两个代码测试看看
 */

#include <iostream>
#include <algorithm>
#include <vector>

struct Sum_nums
{
    void operator()(int& n) { num += n; }

    int num = 0;
};

int main( ){
    std::vector<int> nums{1, 4, 23, 98, 234, 87, 12};

    std::cout << "遍历:" << std::endl;
    auto Print = [ ]( const int& num ){ std::cout << num << "  "; };
    for_each( nums.begin(), nums.end(), Print );

    std::cout << "\n自加：" << std::endl;
    auto Sum_add = [ ]( int& num){ num ++; };
    for_each( nums.begin(), nums.end(), Sum_add );
    for_each( nums.begin(), nums.end(), Print );

    // 这里为 for_each 定义了 Sum_nums operator()
    std::cout << "\n累加：" << std::endl;
    Sum_nums s = for_each( nums.begin(), nums.end(), Sum_nums() );
    std::cout << s.num << std::endl;

    return 0;
}