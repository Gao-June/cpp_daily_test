/**
 * @file main.cpp
 * @author JeffyGao (gaojune)better@qq.com)
 * 
 * @version 0.1
 * @date 2022-04-30
 * @copyright Copyright (c) 2022
 * 
 * @brief  ���ڿ�ʼ���� ���ģʽ03 - װ����ģʽ
 * ���룺
 *  ������Ϊ�̳��ܽ��һ�����⡣�ڳ�������ʱ���֣���չ������Զ���ڱ���ʱ��չ��������
 * װ����ģʽ��
 *  �ô���
 *      һ��֪��װ�εļ��ɣ��㽫�ܸ���ģ�����˵ģ�����һ���µ����Σ�������Ҫ�Եײ�class�Ĵ������κθı�
 *      p.s. д�����ʱ�򣬾����ٶԵײ�������޸ġ�
 *  ������
 *      װ����ģʽ��̬�ؽ��������θ��ӵ������ϡ�
 *      ������չ���ܣ�װ�����ṩ���໯֮��ص������������
 * 
 * ���ԭ��
 *  ��Ӧ�ö���չ���ţ������޸Ĺرա�
 *      ���ǵ�Ŀ����������������չ�������µ���Ϊ���������޸����д��롣
 *      ������Ŀ�꣬��ʲô�ô���
 *      ��������ƿ��Ե��Ե�Ӧ�Ըı䣬���㹻���Խ����µĹ�����Ӧ�Ըı������
 * �ļ�������
 *  Beverage.h:
 *      class Beverage      ����                                           �����������
 *      class CondimentDecorator : public Beverage Ϊ����ʵ�ֳ�����         ������װ���ߣ�
 *  other_Drinks.h:         ���� Beverage (Beverage.h)��������һЩ��������
 *      class Espresso   : public Beverage    Ũ������                      �����������
 *      class TeaWithMilk : public Beverage   �̲�                          �����������
 *      
 *  other_Seasonings.h ���� CondimentDecorator (Beverage.h)��������һЩ��������
 *      class Mocha : public CondimentDecorator ���� - Ħ��                 ������װ���ߣ�
 *      class Cream : public CondimentDecorator ���� - ����                 ������װ���ߣ�
 *      class Soy   : public CondimentDecorator ���� - ����                 ������װ���ߣ�
 */

#include <iostream>
#include "Other_Drinks.h"
#include "Beverage.h"
#include "Other_Seasonings.h"

// ��ʼ�¶���
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
        std::cout << _beverage->GetDescription() << " $ "  << _beverage->Cost() << std::endl;
    }
    
public:
    Beverage* _beverage;
};


int main( ){
    // ��һ��Ũ�����ȣ����ӵ��ϣ���ӡ�����������ͼ۸�
    StabuzzCoffee coffee1;
    coffee1._beverage = new Espresso();
    coffee1.Print();

    StabuzzCoffee coffee2;
    coffee1._beverage = new TeaWithMilk();
    coffee1.Print();

  

    return 0;
}
