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
 *      class WeatherData           ʵ�� Subject �ӿ�
 *          WeatherData( )          ���� _observer
 *          RegisterObserver( )     ע�� Observer
 *          RemoveObserver( )       �Ƴ� Observer
 *          NotifyObservers( )      ������״̬������ �۲���
 *          MeasurementsChanged( )  ������վ�õ����µĲ���ֵʱ��֪ͨ Observer
 *          SetMeasurements( )      ���ò���ֵ
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

        _observer = new std::vector<Observer>( );
    }
    ~WeatherData( ){
        std::cout << "dtor WeatherData" << std::endl;
        delete _observer;
    }

public:
    // ע��
    void RegisterObserver( Observer o ){
        _observer->add( o );    
    }

    // �Ƴ�
    void RemoveObserver( Observer o ){
        _observer->remove( o );
    }

    // ������״̬������ �۲���
    // ��Ϊ���Ƕ��� Observer������֪�����Ƕ�ʵ���� update()������֪�����֪ͨ����
    void NotifyObservers( ){
        for ( Observer ob : *_observer ){
            ob.Update( _temperature, _humidity, _pressure );
        }
    }

    // ������վ�õ����µĲ���ֵʱ��֪ͨ Observer
    void MeasurementsChanged( ){
        NotifyObservers( );
    }

    // ���ò���ֵ
    void SetMeasurements( float temperature, float humidity, float pressure ){
        this->_temperature = temperature;
        this->_humidity    = humidity;
        this->_pressure    = pressure;

        // ���ݸı���
        MeasurementsChanged( );
    }

    // ���� WeatherData �ķ������Լ���������д

private:
    std::vector<Observer>* _observer;
    float _temperature;                  // �¶�
    float _humidity;                    // ʪ��
    float _pressure;                    // ��ѹ
};
