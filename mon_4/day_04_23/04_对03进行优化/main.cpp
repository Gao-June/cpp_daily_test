/**
 *  �� 03 �еĳ�������ʱ������Ż���
 * дһ�� class Timer
 *  ���캯����ʼ��ʱ�䣬�������������ʱ�䣨�����˳�����������������������ص㣩 
*/

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Timer{
public:
    std::chrono::time_point< std::chrono::system_clock > _Start, _End;
    std::chrono::duration<float> _Duration;

    Timer( ){
        _Start = std::chrono::high_resolution_clock::now();

        cout << "Timer begin" << endl; 
    }

    ~Timer( ){
        _End = std::chrono::high_resolution_clock::now();
        _Duration = _End - _Start;

        float ms = _Duration.count() * 1000.0f;
        cout << "Timer end took:  " << ms << "  s" << endl; 
    }

};


int main( ){

    Timer Time_loss;

    for( int i = 0; i < 5; i ++ ){
        std::cout << "No. " << i << std::endl;
    }

    return 0;
}