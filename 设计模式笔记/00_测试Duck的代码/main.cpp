/**
 * @file main.cpp
 * @author GaoJune (gaojune_better@q.com)
 * @version 0.1
 * @date 2022-04-28
 * @copyright Copyright (c) 2022
 * 
 * @brief 
 *  ѧϰ��Head First���ģʽ���е�һ�� - ������Ѽ�ӵ���Ϊ��
 *  ����ԭ��ȫ�� java���Լ������Ǻ���Ӧ
 * 
 * ���ԭ��
 *  ��Խӿڱ�̣����������ʵ�ֱ�̡�
 * 
 * �������룺
 *  ������� Duck����е�������duck ��Ҫ fly() ������
 *      => һ�������ǣ�ֱ���� class Duck() ����� fly()������
 *      => ���ǲ������е� duck ���ܹ��ɣ��������������Ǵ���ģ����е������඼���Ե����ˣ�
 *      ���ܽᡱ: ����ͨ�� �̳� ���ﵽ ���� ��Ŀ�ģ����漰�� ά�� ʱ����鷳��
 * ����취��
 *  ʵ�й��ܷ��룺
 *      => �ѱ仯�Ĳ���ȡ������װ���������Ժ�Ϳ����޸Ļ���չ������֣�������Ӱ����������Ҫ�仯�Ĳ��֡�
 *      => ����ϵͳ����е��ԡ�
 * �ļ����ܣ�
 *  Duck.h Ϊ�������class�������װ��2���ӿڣ��Լ����� duck �Ĺ�������
 *  FlayBehavior.h �� QuackBehavior.h �ֱ�� fly()��quack() ���з�װ
 */

#include <iostream>
#include "Duck.h"

// ǰ������
class Duck;
class FlyBehavior;
class QuackBehavior;


// ���� Ѽ���� MiniDuckSimulator
class MiniDuckSimulator : public Duck{
public:
    MiniDuckSimulator() {
        std::cout << "ctor MiniDuckSimulator" << std::endl;

        // ���������һЩ������
        _fly_behavior = new FlyWithWings();
        _quack_behavior = new Squeak();
    }
    ~MiniDuckSimulator() {
        std::cout << "dtor MiniDuckSimulator" << std::endl;
    }
};

int main( ){
    // ��ʼ���� 
    Duck* mallard = new MiniDuckSimulator();
   
    mallard->Swim();
    mallard->Display();
    mallard->PerformFly();
    mallard->PerformQuack();

    return 0;
}