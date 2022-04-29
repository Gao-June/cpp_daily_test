/**
 * @file Subject.h
 * @author JeffyGao (gaojune_better@qq.com)
 * @version 0.1
 * @date 2022-04-29
 * @copyright Copyright (c) 2022
 * 
 * @brief ���� Subject
 * ��飺
 *  ���ļ�Ϊ ���⣨Subject���Ĵ���
 * 
 * �ļ�������
 *      class Subject   ����
 *          RegisterObserver( )     ע�� Observer
 *          RemoveObserver( )       �Ƴ� Observer
 *          NotifyObservers( )      �� Subject ��״̬�ı�ʱ����������ᱻ���ã���֪ͨ���еĹ۲���
 *      
 *      class WeatherData : public Subject           ʵ�� Subject �ӿ�
 *          WeatherData( )          ���� _observer
 *          RegisterObserver( )     ע�� Observer
 *          RemoveObserver( )       �Ƴ� Observer
 *          NotifyObservers( )      ������״̬������ �۲���
 *          MeasurementsChanged( )  ������վ�õ����µĲ���ֵʱ��֪ͨ Observer
 *          SetMeasurements( )      ���ò���ֵ
 */
#pragma once

#include <iostream>
#include <vector>
#include "Observer.h"

class Subject{
public:
    Subject( ){
        std::cout << "ctor Subject" << std::endl;
    }
    ~Subject( ){
        std::cout << "dtor Subject" << std::endl;
    }

public:
    // ע�� Observer
    void RegisterObserver( Observer o );
    // �Ƴ� Observer
    void RemoveObserver( Observer o );
    // �� Subject ��״̬�ı�ʱ����������ᱻ���ã���֪ͨ���еĹ۲���
    void NotifyObservers( );

};

// ʵ�� Subject �ӿ�
class WeatherData : public Subject{
public:
    WeatherData( ){
        std::cout << "ctor WeatherData" << std::endl;

        _observer = std::vector<Observer>( );
    }
    ~WeatherData( ){
        std::cout << "dtor WeatherData" << std::endl;
    }

public:
    // ע��
    void RegisterObserver( Observer o ){
        std::cout << "RegisterObserver" << std::endl;
        //_observer->add( o );    
    }

    // �Ƴ�
    void RemoveObserver( Observer o ){
        std::cout << "RemoveObserver" << std::endl;
       // _observer->remove( o );
    }

    // ������״̬������ �۲���
    // ��Ϊ���Ƕ��� Observer������֪�����Ƕ�ʵ���� update()������֪�����֪ͨ����
    void NotifyObservers( ){
        std::cout << "func NotifyObservers()" << std::endl;
        
        int count_num = 1;
        std::cout << "begin NotifyObservers" << std::endl;

        // ����������д����vector<Observer> ��������ݴ���ʲô��
        // for ( Observer &ob : _observer ){
        //     std::cout << " No. " << count_num++ << std::endl;
        //     ob.Update( _temperature, _humidity, _pressure );
        // }
        _observer[0].Update( _temperature, _humidity, _pressure );

    }

    // ������վ�õ����µĲ���ֵʱ��֪ͨ Observer
    void MeasurementsChanged( ){
        std::cout << "func MeasurementsChanged()" << std::endl;

        std::cout << "goto func NotifyObservers()" << std::endl;
        NotifyObservers( );
    }

    // ���ò���ֵ
    void SetMeasurements( float temperature, float humidity, float pressure ){
        std::cout << "func SetMeasurements()" << std::endl;
        this->_temperature = temperature;
        this->_humidity    = humidity;
        this->_pressure    = pressure;

        // ���ݸı���
        std::cout << "goto func MeasurementsChanged()" << std::endl;
        MeasurementsChanged( );
    }

    // ���� WeatherData �ķ������Լ���������д

private:
    std::vector<Observer> _observer;
    float _temperature;                  // �¶�
    float _humidity;                    // ʪ��
    float _pressure;                    // ��ѹ
};
