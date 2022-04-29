/**
* @file DisplayElement.h
 * @author JeffyGao (gaojune_better@qq.com)
 * @version 0.1
 * @date 2022-04-29
 * @copyright Copyright (c) 2022
 * 
 * @brief ������ʾ(DisplayElement) �ӿ�
 * ��飺
 *  ���ļ�Ϊ ������ʾ(DisplayElement) �Ĵ�����
 *  DiaplayElement�ӿ�ֻ����һ������ Display()����Ԫ����Ҫ��ʾʱ�����ô˷�����
 * 
 * �ļ�������
 *      class DiaplayElement    չʾ����
 *          Display( ) չʾ����
 *      class CurrentConditionsDisplay : public Observer, public DisplayElement
 *          CurrentConditionsDisplay( ) ����������ʾע��Ϊ�۲���
 *          Update( )                   ��������
 *          Display( )                  ��д�� virtual DiaplayElement::Display() = 0
 */

#pragma once
#include <iostream>
#include "Subject.h"
#include "Observer.h"

// ǰ������
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
 * �����ʾʵ���� Observer�ӿڣ����������Դ� WeatherData�����л�ȡ�仯
 * ��Ҳʵ���� DisplayElement����Ϊ���ǵ� API ����Ҫ��������ʾԪ��ʵ������ӿ�
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

    // ������������ weatherData���� Subject ������������������ʾע��Ϊ�۲���
    CurrentConditionsDisplay( WeatherData weatherData ){
        std::cout << "CurrentConditionsDisplay( WeatherData weatherData ) ctor" << std::endl;

        this->_weatherData = weatherData;
        weatherData.RegisterObserver( *this );
    }

    // class Observer ���ж���
    void Update( float temperature, float humidity, float pressure ){
        this->_temperature = temperature;
        this->_humidity    = humidity;

        Display( );
    }

    // ��д�� virtual DiaplayElement::Display() = 0
    void Display( ){
        std::cout << "��ǰ�¶�: " << _temperature << "  ��ǰʪ�ȣ� " << _humidity << std::endl;
    }

};