/**
 * 线程的工作方式：接收函数指针
*/

#include <iostream>
#include <thread>

// 计数
static int Number_Count = 1;

// 终止标志符号
static bool Flag_Break = false;

void Do_Work( ){
    while( !Flag_Break ){
        std::cout << "No. " << Number_Count++ << std::endl;

        // 延时 1s
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }  
}

int main( ){
    std::thread Thread_1(Do_Work);

    // 等待键盘输入，终止 Do_Work() 
    std::cin.get();
    Flag_Break = true;

    // 等待事件完成
    Thread_1.join();

    return 0;
}