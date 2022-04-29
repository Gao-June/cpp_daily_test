/**
* @file DisplayElement.h
 * @author JeffyGao (gaojune_better@qq.com)
 * @version 0.1
 * @date 2022-04-29
 * @copyright Copyright (c) 2022
 * 
 * @brief 数据显示(DisplayElement) 接口
 * 简介：
 *  本文件为 数据显示(DisplayElement) 的创建。
 *  DiaplayElement接口只包含一个方法 Display()，当元素需要显示时，调用此方法。
 * 
 * 文件包含：
 *      class DiaplayElement    展示数据
 *          Display( ) 展示数据
 */

#include <iostream>

class DiaplayElement{
public:
    DiaplayElement( ){
        std::cout << "ctor DiaplayElement" << std::endl;
    }
    ~DiaplayElement( ){
        std::cout << "dtor DiaplayElement" << std::endl;
    }

public:
    virtual void Display( ) = 0;

};