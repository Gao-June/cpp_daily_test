/**
 * @file main.cpp
 * @author GaoJune (gaojune_better@q.com)
 * @version 0.1
 * @date 2022-04-28
 * @copyright Copyright (c) 2022
 * 
 * @brief 
 *  学习《Head First设计模式》中第一节 - “测试鸭子的行为”
 *  由于原书全是 java，自己还不是很适应
 * 
 * 设计原则：
 *  针对接口编程，而不是针对实现编程。
 * 
 * 问题引入：
 *  当设计完 Duck类后，有的派生类duck 需要 fly() 方法。
 *      => 一种做法是：直接在 class Duck() 中添加 fly()方法。
 *      => 但是不是所有的 duck 都能够飞，所以这种做法是错误的（所有的派生类都可以调用了）
 *      “总结”: 不能通过 继承 来达到 复用 的目的，当涉及到 维护 时会很麻烦。
 * 解决办法：
 *  实行功能分离：
 *      => 把变化的部分取出并封装，这样，以后就可以修改或扩展这个部分，而不会影响其它不需要变化的部分。
 *      => 这样系统会更有弹性。
 */

#include <iostream>

/**
 * @brief：
 * FlyBehavior ：飞行行为基类
 *      class FlyWithWings、class FlyNoWay会继承该接口
 */
class FlyBehavior{
public:
    FlyBehavior() = default;
    ~FlyBehavior() = default;

public:
    virtual void Fly( ) = 0;
};

/**
 * @brief: 
 * FlyWithWings ：对能飞的鸭子进行飞行实现
 */
class FlyWithWings : public FlyBehavior{
public:
    FlyWithWings() = default;
    ~FlyWithWings() = default;

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

/**
 * @brief
 * QuackBehavior ：所有动作行为基类
 *      class Quack、class MuteQuack、Squeak 会继承该接口
 */
class QuackBehavior{
public:
    QuackBehavior() = default;
    ~QuackBehavior() = default;

public:
    virtual void quack( ) = 0;
};

class Quack : public QuackBehavior{
public:
    Quack();
    ~Quack();

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


/**
 * @brief:
 * Duck类中包含两个抽象类: FlyBehavior、 QuackBehavior
 *      FlyBehavior   接口：对 fly 做了封装
 *      QuackBehavior 接口：对 Quack(嘎嘎)做了封装
 */
class Duck{
public:
    Duck() = default;
    ~Duck(){
        delete _fly_behavior;
        delete _quack_behavior;
    }

public:
    // 所有鸭子的公共行为
    void Swim( ){
        std::cout << "All ducks float, even decoys!" << std::endl;
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

// 这里不能设置 private，不然无法修改指针指向
protected:
    FlyBehavior*     _fly_behavior;
    QuackBehavior*   _quack_behavior; 
};



// 具体 鸭子类 MiniDuckSimulator
class MiniDuckSimulator : public Duck{
public:
    MiniDuckSimulator() {
        _fly_behavior = new FlyWithWings();
        _quack_behavior = new Squeak();
    }
    ~MiniDuckSimulator();
};

int main( ){
    // 开始测试 
    Duck* mallard = new MiniDuckSimulator();
   
    mallard->Swim();
    mallard->Display();
    mallard->PerformFly();
    mallard->PerformQuack();

    return 0;
}