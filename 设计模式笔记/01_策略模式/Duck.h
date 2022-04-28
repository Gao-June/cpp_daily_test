/**
 * @brief:
 * Duck���а�������������: FlyBehavior�� QuackBehavior
 *      FlyBehavior   �ӿڣ��� fly ���˷�װ
 *      QuackBehavior �ӿڣ��� Quack(�¸�)���˷�װ
 */

#pragma once
#include <iostream>
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class Duck{
public:
    Duck(){
        std::cout << "ctor Duck" << std::endl;
    }
    ~Duck(){
        std::cout << "dtor Duck" << std::endl;
        delete _fly_behavior;
        delete _quack_behavior;
    }

public:
    // ����Ѽ�ӵĹ�����Ϊ
    void Swim( ){
        std::cout << "Ducks can swim!" << std::endl;
    }
    
    void Display( ){
        std::cout << "Duck's Display" << std::endl;
    }

    // ί�и��ӿ�ִ��
    void PerformFly( ){
        _fly_behavior->Fly();
    }
    void PerformQuack( ){
        _quack_behavior->quack();
    }

    // �ı� duck �ļ���
    // eg. ���� new FlyNoWay()
    void SetFlyBehavior( FlyBehavior *fb ){
        _fly_behavior = fb;
    }
    void SetQuackBehavior( QuackBehavior *qb ){
        _quack_behavior = qb;
    }


// ���ﲻ������ private����Ȼ�޷��޸�ָ��ָ��
protected:
    FlyBehavior*     _fly_behavior;
    QuackBehavior*   _quack_behavior; 
};