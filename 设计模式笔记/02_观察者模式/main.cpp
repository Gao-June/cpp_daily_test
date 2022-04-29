/**
 * @file main.cpp
 * @author JeffyGao (gaojune_better@qq.com)
 * @version 0.1
 * @date 2022-04-29
 * @copyright Copyright (c) 2022
 * 
 * @brief  02_观察者模式
 * 定义：
 *      观察者模式定义对象之间的 一对多 依赖，这样一来，当一个对象改变状态时，
 *      它得所有依赖者都会收到通知并自动更新。
 * 设计原则：
 *      尽量做到交互得对象之间得松耦合设计。
 *     松耦合设计：允许我们建造能够应对变化的、有弹性的OO系统，因为对象之间的互相依赖降低到最低。
 * 简述：
 *      这个模式可以让你的对象在发生某些事情时保持消息灵通。
 *      出版者（主题, subject） + 订阅者（观察者, observer） = 观察者模式（一对多）
 *      p.s. 在“01_设计者模式”中，主题数据变化时，对象不会被通知。
 * 
 * 文件包含：
 *      Subject.h   主题
 *      Observer.h   观察者
 *      DisplayElement.h    数据展示
 */


#include <iostream>
#include "Subject.h"

/**
 * 这个显示实现了 Observer接口，所以它可以从 WeatherData对象中获取变化
 * 它也实现了 DisplayElement，因为我们的 API 打算要求所有显示元素实现这个接口
*/
class CurrentConditionsDisplay : public Observer, public DiaplayElement{
private:
    float _temperature;
    float _humidity;
    WeatherData _weatherData;

public:

    // ctor
    // 构造器被传入 weatherData对象（ Subject ），我们用它来把显示注册为观察者
    CurrentConditionsDisplay( WeatherData weatherData ){
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



int main( ){



    return 0;
}

