/**
 * @brief：
 * FlyBehavior ：飞行行为基类
 *      class FlyWithWings、class FlyNoWay会继承该接口
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
 * FlyWithWings ：对 能飞 的鸭子进行飞行实现
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
 * FlyNoWay ：对不能飞的鸭子进行飞行实现
 */
class FlyNoWay : public FlyBehavior{
    void Fly( ){
        std::cout << "I can't fly" << std::endl;
    }
};