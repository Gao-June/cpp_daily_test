/**
 * 探究左值引用 与 右值引用
 * 左值 支持存储，有地址；
 * 右值 是临时值；没有地址（纯右值），有地址（将亡值）。
 * 
 *  如果是右值，那么就不用担心它是否还活着，是否完整、是否拷贝；
 *  物品们就可以简单地偷它的资源，给到特定对象，或者其它地方使用它。
 *  因为我们知道它是暂时的，不会存在很长时间。
*/


#include <iostream>
#include <string>

void Print( const std::string &Name ) {
    std::cout << "[lvalue]  " << Name << std::endl;
}

// 右值引用
void Print( const std::string &&Name ){
    std::cout << "[rvalue]  " << Name << std::endl;
}

int main( ){
    std::string First = "Gao";
    std::string Second = "june";
    std::string Name = First + Second;


    Print( First );             // lvalue
    Print( First + Second );    // rvalue
    Print( Name );              // lvalue

    return 0;
}
