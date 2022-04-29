/**
* @file DisplayElement.h
 * @author JeffyGao (gaojune_better@qq.com)
 * @version 0.1
 * @date 2022-04-29
 * @copyright Copyright (c) 2022
 * 
 * @brief 数据显示(DisplayElement) 接口
 * 简介：
 *  本文件为 数据显示(DisplayElement) 的创建。
 *  DiaplayElement接口只包含一个方法 Display()，当元素需要显示时，调用此方法。
 * 
 * 文件包含：
 *      class DiaplayElement    展示数据
 *          Display( ) 展示数据
 *      class CurrentConditionsDisplay : public Observer, public DisplayElement
 *          CurrentConditionsDisplay( ) 用它来把显示注册为观察者
 *          Update( )                   更新数据
 *          Display( )                  重写了 virtual DiaplayElement::Display() = 0
 */

#pragma once
#include <iostream>
#include "Subject.h"
#include "Observer.h"

// 前置声明
class Observer;

class DisplayElement{
public:
    DisplayElement( ){
        std::cout << "ctor DisplayElement" << std::endl;
    }
    ~DisplayElement( ){
        std::cout << "dtor DisplayElement" << std::endl;
    }

public:
    virtual void Display( ) = 0;
};

/**
 * 这个显示实现了 Observer接口，所以它可以从 WeatherData对象中获取变化
 * 它也实现了 DisplayElement，因为我们的 API 打算要求所有显示元素实现这个接口
*/
class CurrentConditionsDisplay : public Observer, public DisplayElement{
private:
    float _temperature;
    float _humidity;
    WeatherData _weatherData;

public:

    // ctor
    CurrentConditionsDisplay( ){
        std::cout << "CurrentConditionsDisplay ctor" << std::endl;
    }

    // 构造器被传入 weatherData对象（ Subject ），我们用它来把显示注册为观察者
    CurrentConditionsDisplay( WeatherData weatherData ){
        std::cout << "CurrentConditionsDisplay( WeatherData weatherData ) ctor" << std::endl;

        this->_weatherData = weatherData;
        weatherData.RegisterObserver( *this );
    }

    // class Observer 里有定义
    void Update( float temperature, float humidity, float pressure ){
        this->_temperature = temperature;
        this->_humidity    = humidity;

        Display( );
    }

    // 重写了 virtual DiaplayElement::Display() = 0
    void Display( ){
        std::cout << "当前温度: " << _temperature << "  当前湿度： " << _humidity << std::endl;
    }

};