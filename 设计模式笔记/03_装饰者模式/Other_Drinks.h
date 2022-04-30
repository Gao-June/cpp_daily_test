/**
 * @file Other_dring.h
 * @author effyGao (gaojune)better@qq.com)
 * @version 0.1
 * @date 2022-04-30
 * @copyright Copyright (c) 2022
 * 
 * @brief 基于 基类 Beverage (Beverage.h)，派生的一些其它饮料
 * 
 * 文件包含：
 *  class Espresso : public Beverage ，浓缩咖啡
 *      Espresso()      更改 _description
 *      Cost()          重写了 Cost()
 *  class TeaWithMilk : public Beverage， 奶茶
 *      TeaWithMilk()   更改 _description
 *      Cost()          重写了 Cost()
 */

#ifndef OTHER_DRINKS_H
#define OTHER_DRINKS_H


#include "Beverage.h"
#include <iostream>

// 浓缩咖啡 （具体组件）
class Espresso : public Beverage{
public:
    Espresso( ){
        std::cout << "Espresso ctor" << std::endl;
        _description= "Espresso";   // 并更改描述
    }
    ~Espresso( ){
        std::cout << "Espresso dtor" << std::endl;
    }

public:
    // 重写了 Cost()
    double Cost( ){
        std::cout << "class Espresso Cost() " << std::endl;
        return 1.99;
    }
};

// 奶茶    （具体组件）
class TeaWithMilk : public Beverage{
public:
    TeaWithMilk( ){
        std::cout << "TeaWithMilk ctor" << std::endl;
        _description= "Tea_With_Milk";   // 并更改描述
    }
    ~TeaWithMilk( ){
        std::cout << "TeaWithMilk dtor" << std::endl;
    }

public:
    // 重写了 Cost()
    double Cost( ){
        std::cout << "class TeaWithMilk Cost() " << std::endl;
        return 0.89;
    }
};

#endif