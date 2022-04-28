/**
 * @brief
 * QuackBehavior ：所有动作行为基类
 *      class Quack、class MuteQuack、Squeak 会继承该接口
 */

#pragma once
#include <iostream>

class QuackBehavior{
public:
    QuackBehavior() = default;
    ~QuackBehavior() = default;

public:
    virtual void quack( ) = 0;
};


// 嘎嘎叫
class Quack : public QuackBehavior{
public:
    Quack(){
        std::cout << "ctor Quack" << std::endl;
    }
    ~Quack(){
        std::cout << "dtor Quack" << std::endl;
    }

public:
    void quack( ){
        std::cout << "Quack" << std::endl;
    }
};

// 不会叫
class MuteQuack : public QuackBehavior{
public:
    MuteQuack(){
        std::cout << "ctor MuteQuack" << std::endl;
    }
    ~MuteQuack(){
        std::cout << "dtor MuteQuack" << std::endl;
    }

public:
    void quack( ){
        std::cout << " <<Slience>> " << std::endl;
    }
};

// 吱吱叫
class Squeak : public QuackBehavior{
public:
    Squeak(){
        std::cout << "ctor Squeak" << std::endl;
    }
    ~Squeak(){
        std::cout << "dtor Squeak" << std::endl;
    }

public:
    void quack( ){
        std::cout << "Squeak" << std::endl;
    }
};
