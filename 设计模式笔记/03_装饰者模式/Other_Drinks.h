/**
 * @file Other_dring.h
 * @author effyGao (gaojune)better@qq.com)
 * @version 0.1
 * @date 2022-04-30
 * @copyright Copyright (c) 2022
 * 
 * @brief ���� ���� Beverage (Beverage.h)��������һЩ��������
 * 
 * �ļ�������
 *  class Espresso : public Beverage ��Ũ������
 *      Espresso()      ���� _description
 *      Cost()          ��д�� Cost()
 *  class TeaWithMilk : public Beverage�� �̲�
 *      TeaWithMilk()   ���� _description
 *      Cost()          ��д�� Cost()
 */

#ifndef OTHER_DRINKS_H
#define OTHER_DRINKS_H


#include "Beverage.h"
#include <iostream>

// Ũ������ �����������
class Espresso : public Beverage{
public:
    Espresso( ){
        //std::cout << "Espresso ctor" << std::endl;
        _description= "�������飺 Ũ������ ";   // ����������
    }
    ~Espresso( ){
        std::cout << "Espresso dtor" << std::endl;
    }

public:
    // ��д�� Cost()
    double Cost( ){
        std::cout << "�����ѣ�  ";
        return 1.99;
    }
};

// �̲�    �����������
class TeaWithMilk : public Beverage{
public:
    TeaWithMilk( ){
        //std::cout << "TeaWithMilk ctor" << std::endl;
        _description= "�������飺 �̲� ";   // ����������
    }
    ~TeaWithMilk( ){
        std::cout << "TeaWithMilk dtor" << std::endl;
    }

public:
    // ��д�� Cost()
    double Cost( ){
        std::cout << "�����ѣ�    ";
        return 0.89;
    }
};

#endif