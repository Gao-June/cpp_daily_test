/**
 * @file Subject.h
 * @author JeffyGao (gaojune_better@qq.com)
 * @version 0.1
 * @date 2022-04-29
 * @copyright Copyright (c) 2022
 * 
 * @brief 主题 Subject
 * 简介：
 *  本文件为 主题（Subject）的创建
 * 
 * 文件包含：
 *      class Subject   主题
 *          RegisterObserver( )     注册 Observer
 *          RemoveObserver( )       移除 Observer
 *          NotifyObservers( )      当 Subject 的状态改变时，这个方法会被调用，以通知所有的观察者
 *      
 *      class WeatherData           实现 Subject 接口
 *          WeatherData( )          构造 _observer
 *          RegisterObserver( )     注册 Observer
 *          RemoveObserver( )       移除 Observer
 *          NotifyObservers( )      把所有状态都告诉 观察者
 *          MeasurementsChanged( )  从气象站得到更新的测量值时，通知 Observer
 *          SetMeasurements( )      设置测量值
 */

#include <iostream>
#include <vector>
#include "Observer.h"
#include "DisplayElement.h"

class Subject{
public:
    Subject( ){
        std::cout << "ctor Subject" << std::endl;
    }
    ~Subject( ){
        std::cout << "dtor Subject" << std::endl;
    }

public:
    // 注册 Observer
    void RegisterObserver( Observer o );
    // 移除 Observer
    void RemoveObserver( Observer o );
    // 当 Subject 的状态改变时，这个方法会被调用，以通知所有的观察者
    void NotifyObservers( );

};

// 实现 Subject 接口
class WeatherData : public Subject{
public:
    WeatherData( ){
        std::cout << "ctor WeatherData" << std::endl;

        _observer = new std::vector<Observer>( );
    }
    ~WeatherData( ){
        std::cout << "dtor WeatherData" << std::endl;
        delete _observer;
    }

public:
    // 注册
    void RegisterObserver( Observer o ){
        _observer->add( o );    
    }

    // 移除
    void RemoveObserver( Observer o ){
        _observer->remove( o );
    }

    // 把所有状态都告诉 观察者
    // 因为它们都是 Observer，我们知道它们都实现了 update()，所以知道如何通知它们
    void NotifyObservers( ){
        for ( Observer ob : *_observer ){
            ob.Update( _temperature, _humidity, _pressure );
        }
    }

    // 从气象站得到更新的测量值时，通知 Observer
    void MeasurementsChanged( ){
        NotifyObservers( );
    }

    // 设置测量值
    void SetMeasurements( float temperature, float humidity, float pressure ){
        this->_temperature = temperature;
        this->_humidity    = humidity;
        this->_pressure    = pressure;

        // 数据改变了
        MeasurementsChanged( );
    }

    // 其它 WeatherData 的方法可以继续往后面写

private:
    std::vector<Observer>* _observer;
    float _temperature;                  // 温度
    float _humidity;                    // 湿度
    float _pressure;                    // 气压
};
