/**
 * �����������ʱ�� 
*/

#include <iostream>
#include <thread>
#include <chrono>       // ʱ��

int main( ){

    // std::chrono::time_point<std::chrono::steady_clock> Start;
    auto Start = std::chrono::high_resolution_clock::now();

    // ���� 3S
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    // for ѭ��ִ�� 10E ��
    // for( int i = 0; i < 1000000000; i ++ ){
    //     ;
    // }

    auto End = std::chrono::high_resolution_clock::now();

    // ��ʱ�� ����Ҳ������ auto ��
    std::chrono::duration<double> Duration = End - Start;
    std::cout << Duration.count() << " s " << std::endl;

    return 0;
}
