/**
 * �̵߳Ĺ�����ʽ�����պ���ָ��
*/

#include <iostream>
#include <thread>

// ����
static int Number_Count = 1;

// ��ֹ��־����
static bool Flag_Break = false;

void Do_Work( ){
    while( !Flag_Break ){
        std::cout << "No. " << Number_Count++ << std::endl;

        // ��ʱ 1s
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }  
}

int main( ){
    std::thread Thread_1(Do_Work);

    // �ȴ��������룬��ֹ Do_Work() 
    std::cin.get();
    Flag_Break = true;

    // �ȴ��¼����
    Thread_1.join();

    return 0;
}