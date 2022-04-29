/**
 * @file Observer.h
 * @author JeffyGao (gaojune_better@qq.com)
 * @version 0.1
 * @date 2022-04-29
 * @copyright Copyright (c) 2022
 * 
 * @brief 观察者(Observer) 接口
 * 简介：
 *  本文件为 观察者（Observer） 的创建。
 * 所有的观察者都实现 Ovserver接口，所以它们都不得不实现 update() 方法。
 * 
 * 文件包含：
 *      class Observer  观察者
 *          Update( ) 更新数据
 */ 

#pragma once

#include <iostream>
#include "Subject.h"

class Observer{
public:
    Observer( ){
        std::cout << "ctor Observer" << std::endl;
    }
    ~Observer( ){
        std::cout << "dtor Observer" << std::endl;
    }

public:
    // 更新数据。
    // 当气象测量数据变化时观察者从 Subject获得的状态值。
    void Update( float tmep, float humidity, float pressure ){
        std::cout << "func_Update 温度： " << tmep << " 湿度： " << humidity << " 气压：" << pressure << std::endl;
    }
};
