/**
 * @file Observer.h
 * @author JeffyGao (gaojune_better@qq.com)
 * @version 0.1
 * @date 2022-04-29
 * @copyright Copyright (c) 2022
 * 
 * @brief �۲���(Observer) �ӿ�
 * ��飺
 *  ���ļ�Ϊ �۲��ߣ�Observer�� �Ĵ�����
 * ���еĹ۲��߶�ʵ�� Ovserver�ӿڣ��������Ƕ����ò�ʵ�� update() ������
 * 
 * �ļ�������
 *      class Observer  �۲���
 *          Update( ) ��������
 */ 

#pragma once

#include <iostream>
#include "Subject.h"

class Observer{
public:
    Observer( ){
        std::cout << "ctor Observer" << std::endl;
    }
    ~Observer( ){
        std::cout << "dtor Observer" << std::endl;
    }

public:
    // �������ݡ�
    // ������������ݱ仯ʱ�۲��ߴ� Subject��õ�״ֵ̬��
    void Update( float tmep, float humidity, float pressure ){
        std::cout << "func_Update �¶ȣ� " << tmep << " ʪ�ȣ� " << humidity << " ��ѹ��" << pressure << std::endl;
    }
};
