/**
 * @file main.cpp
 * @author JeffyGao (gaojune)better@qq.com)
 * 
 * @version 0.1
 * @date 2022-04-30
 * @copyright Copyright (c) 2022
 * 
 * @brief  本节开始介绍 设计模式03 - 装饰者模式
 * 引入：
 *  曾今以为继承能解决一切问题。在程序运行时发现，扩展的威力远大于编译时扩展的威力。
 * 装饰者模式：
 *  好处：
 *      一旦知道装饰的技巧，你将能给你的（或别人的）对象一个新的责任，而不需要对底层class的代码做任何改变
 *      p.s. 写代码的时候，尽量少对底层代码做修改。
 *  描述：
 *      装饰者模式动态地将额外责任附加到对象上。
 *      对于扩展功能，装饰者提供子类化之外地弹性替代方案。
 * 
 * 设计原则：
 *  类应该对扩展开放，但对修改关闭。
 *      我们的目标是允许类容易扩展以容纳新的行为，而不用修改已有代码。
 *      达成这个目标，有什么好处？
 *      这样的设计可以弹性地应对改变，有足够弹性接纳新的功能来应对改变的需求。
 * 文件描述：
 *  Beverage.h:
 *      class Beverage      基类                                           （抽象组件）
 *      class CondimentDecorator : public Beverage 为调料实现抽象类         （抽象装饰者）
 *  other_Drinks.h:         基于 Beverage (Beverage.h)，派生的一些其它饮料
 *      class Espresso   : public Beverage    浓缩咖啡                      （具体组件）
 *      class TeaWithMilk : public Beverage   奶茶                          （具体组件）
 *      
 *  other_Seasonings.h 基于 CondimentDecorator (Beverage.h)，派生的一些其它调料
 *      class Mocha : public CondimentDecorator 调料 - 摩卡                 （具体装饰者）
 *      class Cream : public CondimentDecorator 调料 - 奶油                 （具体装饰者）
 *      class Soy   : public CondimentDecorator 调料 - 豆子                 （具体装饰者）
 */

#include <iostream>
#include "Other_Drinks.h"
#include "Beverage.h"
#include "Other_Seasonings.h"

// 开始下订单
class StabuzzCoffee{
public:
    StabuzzCoffee( ){
        std::cout << "Begin buy my coffee ctor" << std::endl;
    }
    ~StabuzzCoffee( ){
        std::cout << "StabuzzCoffee dtor" << std::endl;
    }
public:
    void Print( ){
        // std::cout << _beverage->GetDescription() << " $ "  << _beverage->Cost() << std::endl;
        std::cout << _beverage->Cost() << "$" << std::endl;
    }
    
public:
    Beverage* _beverage;
};

// 点单系统是 一种奶茶/咖啡 + 若干小料
int main( ){
std::cout << "No.1" << std::endl;
    // 来一杯浓缩咖啡，不加调料，打印出它的描述和价格
    StabuzzCoffee coffee1;
    coffee1._beverage = new Espresso();
    std::cout << coffee1._beverage->GetDescription() << std::endl;
    coffee1.Print();

std::cout << "No.2" << std::endl;
    // 来一杯奶茶(0.89)，加 摩卡(0.2)、奶油(0.31)
    // 在调用 coffee2.Pring() 的时候调用顺序：
    // -> Cream.Cost() -> Mocha.Cost() -> TraWithMilk.Cost() 
    StabuzzCoffee coffee2;
    coffee2._beverage = new TeaWithMilk();
    coffee2._beverage = new Mocha( coffee2._beverage );
    coffee2._beverage = new Cream( coffee2._beverage );
    std::cout << coffee2._beverage->GetDescription() << std::endl;
    coffee2.Print();

    return 0;
}
