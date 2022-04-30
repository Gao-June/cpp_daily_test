/**
 * @file Other_Seasonings.h
 * @author effyGao (gaojune)better@qq.com)
 * @version 0.1
 * @date 2022-04-30
 * @copyright Copyright (c) 2022
 * 
 * @brief   一些调料~ 
 *  基于 基类 CondimentDecorator (Beverage.h)，派生的一些其它调料
 * 
 * 文件包含：
 *  class Mocha : public CondimentDecorator 调料 - 摩卡 （具体装饰者）
 *  class Cream : public CondimentDecorator 调料 - 奶油 （具体装饰者）
 *  class Soy   : public CondimentDecorator 调料 - 豆子 （具体装饰者）
 * 
 *  // 构造函数 传入 Beverage* 型， 在 main.cpp 中通过包裹对象来实现“加小料”，反馈相应的Cost()
 */

#ifndef OTHER_SEASONINGS_H
#define OTHER_SEASONINGS_H

#include <iostream>
#include "Beverage.h"
#include <string>

// 调料 - 摩卡 具体装饰着
class Mocha : public CondimentDecorator{
public:
    Mocha( ){
        std::cout << "Mocha ctor" << std::endl;
    }

    Mocha( Beverage* beverage ){
        std::cout << "Mocha( Beverage beverage )" << std::endl;

        // 在这里实例变量为正在包裹的对象。
        // 这里，我们可以传递正在包装的饮料给装饰者的构造器。
        this->_beverage = beverage;
    }

    ~Mocha( ){
        std::cout << "Mocha dtor" << std::endl;
    }

public:
    // 重写方法
    // 饮料 Description + Mocha 描述
    std::string GetDescription( ){
        std::string name = _beverage->GetDescription() + " , Mocha";
        return  name;
    }

    // 饮料 Cost +  Mocha 价格
    double Cost( ){
        return _beverage->Cost() + 0.20;
    }
};

// 调料 - 奶油 具体装饰着
class Cream : public CondimentDecorator{
public:
    Cream( ){
        std::cout << "Cream ctor" << std::endl;
    }
    Cream( Beverage* beverage ){
        std::cout << "Cream( Beverage beverage )" << std::endl;

        // 在这里实例变量为正在包裹的对象。
        // 这里，我们可以传递正在包装的饮料给装饰者的构造器。
        this->_beverage = beverage;
    }

    ~Cream( ){
        std::cout << "Cream dtor" << std::endl;
    }

public:
    // 重写方法
    // 饮料 Description + Cream 描述
    std::string GetDescription( ){
        //std::cout << "调用了 奶油" << std::endl;
        std::string name = _beverage->GetDescription() + " , Cream";
        return  name;
    }

    // 饮料 Cost +  Cream 价格
    double Cost( ){
        return _beverage->Cost() + 0.31;
    }
};

// 调料 - 豆子 具体装饰着
class Soy : public CondimentDecorator{
public:
    Soy( ){
        std::cout << "Soy ctor" << std::endl;
    }
    Soy( Beverage* beverage ){
        std::cout << "Soy( Beverage beverage )" << std::endl;

        // 在这里实例变量为正在包裹的对象。
        // 这里，我们可以传递正在包装的饮料给装饰者的构造器。
        this->_beverage = beverage;
    }

    ~Soy( ){
        std::cout << "Soy dtor" << std::endl;
    }

public:
    // 重写方法
    // 饮料 Description + Soy 描述
    std::string GetDescription( ){
        std::string name = _beverage->GetDescription() + " , Soy";
        return  name;

    }

    // 饮料 Cost +  Soy 价格
    double Cost( ){
        return _beverage->Cost() + 0.39;
    }
};

#endif  

