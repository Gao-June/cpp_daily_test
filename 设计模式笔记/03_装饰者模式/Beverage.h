/**
 * @file Beverage.h
 * @author JeffyGao (gaojune)better@qq.com) 
 * @version 0.1
 * @date 2022-04-30
 * @copyright Copyright (c) 2022
 * 
 * @brief ����һ�������� �Ļ���
 * 
 * �ļ�������
 *      GetDescription() ��Ʒ����
 *      virtual double Cost() = 0 ��Ʒ����
 *      
 * 
 */

#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <iostream>
#include <string.h>

class Beverage{
public:
    Beverage( ){
        std::cout << "Beverage ctor" << std::endl;
    }

    // Ҫ���� �麯��
    virtual ~Beverage( ){
        std::cout << "Beverage dtor" << std::endl;
    }

public:
    // �����ӿ�
    // ��Ʒ����
    virtual std::string GetDescription( ){
        return _description;
    }

    // ��Ʒ����
    // ���ﲻ�ܶ���Ϊ ���麯������Ȼ class CondimentDecorator �޷�ʵ����_beverage
    virtual double Cost( ) = 0;
    //virtual double Cost( ) {}     // ���Ҫ����Ϊ�麯���Ļ�Ҫ���� {}
    // double Cost( ){
    //     std::cout << " Beverage Cost()" << std::endl;
    //     return (double)12345.1234;
    // }

    // ��������Ϊ private����Ȼ�������޷����ĸı���
    std::string _description = "Unknown Beverage  ";

};


// Ϊ����ʵ�ֳ�����
class CondimentDecorator : public Beverage{
public:
    CondimentDecorator( ){
        std::cout << "CondimentDecorator ctor" << std::endl;
    }
    ~CondimentDecorator( ){
        std::cout << "CondimentDecorator dtor" << std::endl;
    }

public:
    // ������һ��û���� =>  �� Other_Seasonings.h ��Ҫʵ����
    // ���� Beverage �н� Cost( ) �����˴��麯������˲���ֱ��ʵ������ֻ��ʵ������ָ��
    // Ҫ����ʵ���������Ļ�����һ�ַ����Ƕ�������鹹����{}
    Beverage* _beverage;

    // ��д GetDescription()
    virtual std::string GetDescription( ) {
        return _description;
    }

};


#endif