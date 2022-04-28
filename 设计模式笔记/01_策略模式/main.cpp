/**
 * @file main.cpp
 * @author GaoJune (gaojune_better@q.com)
 * @version 0.1
 * @date 2022-04-28
 * @copyright Copyright (c) 2022
 * 
 * @brief 
 *  学习《Head First设计模式》中第一节 - “策略模式”
 *  （由于原书全是 java，自己还不是很适应）
 * 策略模式的定义：
 *      策略模式顶一个一个算法族，分别封装起来，使得它们之间可以互相交换。
 *      策略让算法的变化独立于使用它的客户。
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
 * 文件介绍：
 *  Duck.h 为最基本的class，里面封装了2个接口，以及所有 duck 的公共函数
 *  该 “ has-A ” 中，每只鸭子有一个FlayBehavior和QuackBehavior，以委托飞行和叫。
 *  FlayBehavior.h 和 QuackBehavior.h 分别对 fly()、quack() 进行封装
 */

#include <iostream>
#include "Duck.h"

// 前置声明
class Duck;
class FlyBehavior;
class QuackBehavior;


// 设计鸭子类 MiniDuckSimulator，并为其添加属性
class MiniDuckSimulator : public Duck{
public:
    MiniDuckSimulator() {
        std::cout << "ctor MiniDuckSimulator" << std::endl;

        // 给该类添加一些新特性
        _fly_behavior = new FlyWithWings();
        _quack_behavior = new Squeak();
    }
    ~MiniDuckSimulator() {
        std::cout << "dtor MiniDuckSimulator" << std::endl;
    }
};

int main( ){
    // 开始测试 
    Duck* mallard = new MiniDuckSimulator();
   
    mallard->Swim();
    mallard->Display();
    mallard->PerformFly();
    mallard->PerformQuack();

    // 改变鸭子的飞行、叫声
    std::cout << "改变鸭子飞行、叫声 技能" << std::endl;
    mallard->SetFlyBehavior( new FlyNoWay() );
    mallard->SetQuackBehavior( new MuteQuack() );
    mallard->PerformFly();
    mallard->PerformQuack();

    return 0;
}