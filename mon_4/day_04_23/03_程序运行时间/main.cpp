/**
 * 检验程序运行时间 
*/

#include <iostream>
#include <thread>
#include <chrono>       // 时钟

int main( ){

    // std::chrono::time_point<std::chrono::steady_clock> Start;
    auto Start = std::chrono::high_resolution_clock::now();

    // 休眠 3S
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    // for 循环执行 10E 次
    // for( int i = 0; i < 1000000000; i ++ ){
    //     ;
    // }

    auto End = std::chrono::high_resolution_clock::now();

    // 求时间差， 这里也可以用 auto 的
    std::chrono::duration<double> Duration = End - Start;
    std::cout << Duration.count() << " s " << std::endl;

    return 0;
}
