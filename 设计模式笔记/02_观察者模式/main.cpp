/**
 * @file main.cpp
 * @author JeffyGao (gaojune_better@qq.com)
 * @version 0.1
 * @date 2022-04-29
 * @copyright Copyright (c) 2022
 * 
 * @brief  02_�۲���ģʽ
 * ���壺
 *      �۲���ģʽ�������֮��� һ�Զ� ����������һ������һ������ı�״̬ʱ��
 *      �������������߶����յ�֪ͨ���Զ����¡�
 * ���ԭ��
 *      �������������ö���֮����������ơ�
 *     �������ƣ��������ǽ����ܹ�Ӧ�Ա仯�ġ��е��Ե�OOϵͳ����Ϊ����֮��Ļ����������͵���͡�
 * ������
 *      ���ģʽ��������Ķ����ڷ���ĳЩ����ʱ������Ϣ��ͨ��
 *      �����ߣ�����, subject�� + �����ߣ��۲���, observer�� = �۲���ģʽ��һ�Զࣩ
 *      p.s. �ڡ�01_�����ģʽ���У��������ݱ仯ʱ�����󲻻ᱻ֪ͨ��
 * 
 * �ļ�������
 *      Subject.h   ����
 *      Observer.h   �۲���
 *      DisplayElement.h    ����չʾ
 */


#include <iostream>
#include "Subject.h"

/**
 * �����ʾʵ���� Observer�ӿڣ����������Դ� WeatherData�����л�ȡ�仯
 * ��Ҳʵ���� DisplayElement����Ϊ���ǵ� API ����Ҫ��������ʾԪ��ʵ������ӿ�
*/
class CurrentConditionsDisplay : public Observer, public DiaplayElement{
private:
    float _temperature;
    float _humidity;
    WeatherData _weatherData;

public:

    // ctor
    // ������������ weatherData���� Subject ������������������ʾע��Ϊ�۲���
    CurrentConditionsDisplay( WeatherData weatherData ){
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



int main( ){



    return 0;
}

