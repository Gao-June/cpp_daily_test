/**
 * @brief:
 * Duck类中包含两个抽象类: FlyBehavior、 QuackBehavior
 *      FlyBehavior   接口：对 fly 做了封装
 *      QuackBehavior 接口：对 Quack(嘎嘎)做了封装
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
    // 所有鸭子的公共行为
    void Swim( ){
        std::cout << "Ducks can swim!" << std::endl;
    }
    
    void Display( ){
        std::cout << "Duck's Display" << std::endl;
    }

    // 委托给接口执行
    void PerformFly( ){
        _fly_behavior->Fly();
    }
    void PerformQuack( ){
        _quack_behavior->quack();
    }

    // 改变 duck 的技能
    // eg. 传入 new FlyNoWay()
    void SetFlyBehavior( FlyBehavior *fb ){
        _fly_behavior = fb;
    }
    void SetQuackBehavior( QuackBehavior *qb ){
        _quack_behavior = qb;
    }


// 这里不能设置 private，不然无法修改指针指向
protected:
    FlyBehavior*     _fly_behavior;
    QuackBehavior*   _quack_behavior; 
};