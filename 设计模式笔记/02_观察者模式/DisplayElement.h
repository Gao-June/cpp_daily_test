/**
* @file DisplayElement.h
 * @author JeffyGao (gaojune_better@qq.com)
 * @version 0.1
 * @date 2022-04-29
 * @copyright Copyright (c) 2022
 * 
 * @brief ������ʾ(DisplayElement) �ӿ�
 * ��飺
 *  ���ļ�Ϊ ������ʾ(DisplayElement) �Ĵ�����
 *  DiaplayElement�ӿ�ֻ����һ������ Display()����Ԫ����Ҫ��ʾʱ�����ô˷�����
 * 
 * �ļ�������
 *      class DiaplayElement    չʾ����
 *          Display( ) չʾ����
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