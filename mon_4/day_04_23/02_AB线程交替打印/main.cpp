/**
 * ÿ����ʱ 1S�� �����ӡ A B �߳�
 * 5S ��ֹͣ����
*/

#include <iostream>
#include <thread>

// ��ֹ��־����
static bool Flag_Break = false;

void Do_Print_A( ){
    while( !Flag_Break ){
        std::cout << "A" << std::endl;

        // ��ʱ 1s
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }  
}

void Do_Print_B( ){
    while( !Flag_Break ){
        std::cout << "B" << std::endl;

        // ��ʱ 1s
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