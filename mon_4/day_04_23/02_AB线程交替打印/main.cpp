/**
 * 每次延时 1S， 交替打印 A B 线程
 * 5S 后停止程序
*/

#include <iostream>
#include <thread>

// 终止标志符号
static bool Flag_Break = false;

void Do_Print_A( ){
    while( !Flag_Break ){
        std::cout << "A" << std::endl;

        // 延时 1s
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }  
}

void Do_Print_B( ){
    while( !Flag_Break ){
        std::cout << "B" << std::endl;

        // 延时 1s
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }  
}

int main( ){
    std::thread Thread_1(Do_Print_A);
    std::thread Thread_2(Do_Print_B);


    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    Flag_Break = true;

    Thread_1.join();
    Thread_2.join();

    return 0;
}