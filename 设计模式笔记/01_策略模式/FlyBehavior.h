/**
 * @brief��
 * FlyBehavior ��������Ϊ����
 *      class FlyWithWings��class FlyNoWay��̳иýӿ�
 */

#pragma once
#include <iostream>

class FlyBehavior{
public:
    FlyBehavior(){
        std::cout << "ctor FlyBehavior" << std::endl;
    }
    ~FlyBehavior(){
        std::cout << "dtor FlyBehavior" << std::endl;
    }

public:
    virtual void Fly( ) = 0;
};

/**
 * @brief: 
 * FlyWithWings ���� �ܷ� ��Ѽ�ӽ��з���ʵ��
 */
class FlyWithWings : public FlyBehavior{
public:
    FlyWithWings(){
        std::cout << "ctor FlyWithWings" << std::endl;
    }
    ~FlyWithWings(){
        std::cout << "dtor FlyWithWings" << std::endl;
    }

public:
    void Fly( ){
        std::cout << "I'm flying!" << std::endl;
    }
};

/**
 * @brief:
 * FlyNoWay ���Բ��ܷɵ�Ѽ�ӽ��з���ʵ��
 */
class FlyNoWay : public FlyBehavior{
    void Fly( ){
        std::cout << "I can't fly" << std::endl;
    }
};