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
#include "Observer.h"
#include "DisplayElement.h"



// 测试案例
int main( ){
    WeatherData* weatherData = new WeatherData();

    CurrentConditionsDisplay* currentConditionsDisplay = new CurrentConditionsDisplay(*weatherData);

    weatherData->SetMeasurements( 80, 65, 30.4f );
    weatherData->SetMeasurements( 82, 70, 29.8f );
    weatherData->SetMeasurements( 78, 90, 39.4f );

    return 0;
}

