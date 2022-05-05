/**
 * 在 03 中用 lambda替换了 仿函数，接下来探究下是否能用 仿函数代替 lambda
 * 
 * 测试：
 *  写一个 sort() 函数测试
 * 结论：
 *  是可以的，不过这里仿函数要加一个() 实例化
 */

#include <iostream>
#include <algorithm>
#include <vector>

// 写仿函数
class Cmp{
public:
    bool operator()( const int& a, const int& b ) const{
        return a >= b;
    }
};

int main( ){
    std::vector<int> nums{1, 7, 20, 9, 23, 98, 23};

    // 正常排序，无参数
    sort( nums.begin(), nums.end() );
    for( auto& num : nums ){
        std::cout << num << "  ";
    }
    std::cout << std::endl;

    // 自定义排序
    sort( nums.begin(), nums.end(), Cmp() );
    for( auto& num : nums ){
        std::cout << num << "  ";
    }
    std::cout << std::endl;

    // 写 lambda
    sort( nums.begin(), nums.end(), [](const int& a, const int&b){return a <= b;}  
        );
    for( auto& num : nums ){
        std::cout << num << "  ";
    }
    std::cout << std::endl;

    return 0;
}
