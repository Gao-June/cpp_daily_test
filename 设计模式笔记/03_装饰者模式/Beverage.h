/**
 * @file Beverage.h
 * @author JeffyGao (gaojune)better@qq.com) 
 * @version 0.1
 * @date 2022-04-30
 * @copyright Copyright (c) 2022
 * 
 * @brief 这是一个抽象类 的基类
 * 
 * 文件包含：
 *      GetDescription() 商品描述
 *      virtual double Cost() = 0 商品花费
 *      
 * 
 */

#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <iostream>
#include <string.h>

class Beverage{
public:
    Beverage( ){
        std::cout << "Beverage ctor" << std::endl;
    }

    // 要定义 虚函数
    virtual ~Beverage( ){
        std::cout << "Beverage dtor" << std::endl;
    }

public:
    // 公共接口
    // 商品描述
    virtual std::string GetDescription( ){
        return _description;
    }

    // 商品花费
    // 这里不能定义为 纯虚函数，不然 class CondimentDecorator 无法实例化_beverage
    virtual double Cost( ) = 0;
    //virtual double Cost( ) {}     // 如果要定义为虚函数的话要定义 {}
    // double Cost( ){
    //     std::cout << " Beverage Cost()" << std::endl;
    //     return (double)12345.1234;
    // }

    // 不能设置为 private，不然派生类无法更改改变量
    std::string _description = "Unknown Beverage  ";

};


// 为调料实现抽象类
class CondimentDecorator : public Beverage{
public:
    CondimentDecorator( ){
        std::cout << "CondimentDecorator ctor" << std::endl;
    }
    ~CondimentDecorator( ){
        std::cout << "CondimentDecorator dtor" << std::endl;
    }

public:
    // 书中这一行没看懂 =>  在 Other_Seasonings.h 中要实例化
    // 我在 Beverage 中将 Cost( ) 定义了纯虚函数，因此不能直接实例化，只能实例化其指针
    // 要想能实例化其对象的话，另一种方法是定义好其虚构函数{}
    Beverage* _beverage;

    // 重写 GetDescription()
    virtual std::string GetDescription( ) {
        return _description;
    }

};


#endif