/**
 * @file Other_Seasonings.h
 * @author effyGao (gaojune)better@qq.com)
 * @version 0.1
 * @date 2022-04-30
 * @copyright Copyright (c) 2022
 * 
 * @brief ���� ���� CondimentDecorator (Beverage.h)��������һЩ��������
 * 
 * �ļ�������
 *  class Mocha : public CondimentDecorator ���� - Ħ�� ������װ���ߣ�
 *  class Cream : public CondimentDecorator ���� - ���� ������װ���ߣ�
 *  class Soy   : public CondimentDecorator ���� - ���� ������װ���ߣ�
 */

#ifndef OTHER_SEASONINGS_H
#define OTHER_SEASONINGS_H

#include <iostream>
#include "Beverage.h"
#include <string>

// ���� - Ħ�� ����װ����
class Mocha : public CondimentDecorator{
public:
    Mocha( ){
        std::cout << "Mocha ctor" << std::endl;
    }
    Mocha( Beverage* beverage ){
        std::cout << "Mocha( Beverage beverage )" << std::endl;

        // ������ʵ������Ϊ���ڰ����Ķ���
        // ������ǿ��Դ������ڰ�װ�����ϸ�װ���ߵĹ�������
        this->_beverage = beverage;
    }

    ~Mocha( ){
        std::cout << "Mocha dtor" << std::endl;
    }

public:
    // ��д����
    // ���� Description + Mocha ����
    std::string GetDescription( ){
        return _beverage->GetDescription() + " , Mocha";
    }

    // ���� Cost +  Mocha �۸�
    double Cost( ){
        return _beverage->Cost() + 0.20;
    }
};

// ���� - ���� ����װ����
class Cream : public CondimentDecorator{
public:
    Cream( ){
        std::cout << "Cream ctor" << std::endl;
    }
    Cream( Beverage* beverage ){
        std::cout << "Cream( Beverage beverage )" << std::endl;

        // ������ʵ������Ϊ���ڰ����Ķ���
        // ������ǿ��Դ������ڰ�װ�����ϸ�װ���ߵĹ�������
        this->_beverage = beverage;
    }

    ~Cream( ){
        std::cout << "Cream dtor" << std::endl;
    }

public:
    // ��д����
    // ���� Description + Cream ����
    std::string GetDescription( ){
        return _beverage->GetDescription() + " , Cream";
    }

    // ���� Cost +  Cream �۸�
    double Cost( ){
        return _beverage->Cost() + 0.31;
    }
};

// ���� - ���� ����װ����
class Soy : public CondimentDecorator{
public:
    Soy( ){
        std::cout << "Soy ctor" << std::endl;
    }
    Soy( Beverage* beverage ){
        std::cout << "Soy( Beverage beverage )" << std::endl;

        // ������ʵ������Ϊ���ڰ����Ķ���
        // ������ǿ��Դ������ڰ�װ�����ϸ�װ���ߵĹ�������
        this->_beverage = beverage;
    }

    ~Soy( ){
        std::cout << "Soy dtor" << std::endl;
    }

public:
    // ��д����
    // ���� Description + Soy ����
    std::string GetDescription( ){
        return _beverage->GetDescription() + " , Soy";
    }

    // ���� Cost +  Soy �۸�
    double Cost( ){
        return _beverage->Cost() + 0.39;
    }
};

#endif  

