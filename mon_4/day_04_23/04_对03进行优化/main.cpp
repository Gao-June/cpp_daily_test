/**
 *  对 03 中的程序运行时间进行优化；
 * 写一个 class Timer
 *  构造函数初始化时间，析构函数求结束时间（利用了程序运行完调用析构函数的特点） 
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