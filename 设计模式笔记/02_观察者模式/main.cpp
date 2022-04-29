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
#include "Observer.h"
#include "DisplayElement.h"



// ���԰���
int main( ){
    WeatherData* weatherData = new WeatherData();

    CurrentConditionsDisplay* currentConditionsDisplay = new CurrentConditionsDisplay(*weatherData);

    weatherData->SetMeasurements( 80, 65, 30.4f );
    weatherData->SetMeasurements( 82, 70, 29.8f );
    weatherData->SetMeasurements( 78, 90, 39.4f );

    return 0;
}

