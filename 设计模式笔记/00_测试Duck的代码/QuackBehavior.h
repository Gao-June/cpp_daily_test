/**
 * @brief
 * QuackBehavior �����ж�����Ϊ����
 *      class Quack��class MuteQuack��Squeak ��̳иýӿ�
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

class MuteQuack : public QuackBehavior{
public:
    void quack( ){
        std::cout << " <<Slience>> " << std::endl;
    }
};

class Squeak : public QuackBehavior{
public:
    void quack( ){
        std::cout << "Squeak" << std::endl;
    }
};
