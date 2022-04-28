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
 */

#include <iostream>

/**
 * @brief��
 * FlyBehavior ��������Ϊ����
 *      class FlyWithWings��class FlyNoWay��̳иýӿ�
 */
class FlyBehavior{
public:
    FlyBehavior() = default;
    ~FlyBehavior() = default;

public:
    virtual void Fly( ) = 0;
};

/**
 * @brief: 
 * FlyWithWings �����ܷɵ�Ѽ�ӽ��з���ʵ��
 */
class FlyWithWings : public FlyBehavior{
public:
    FlyWithWings() = default;
    ~FlyWithWings() = default;

public:
    void Fly( ){
        std::cout << "I'm flying!" << std::endl;
    }
};

/**
 * @brief:
 * FlyNoWay ���Բ��ܷɵ�Ѽ�ӽ��з���ʵ��
 */
class FlyNoWay : public FlyBehavior{
    void Fly( ){
        std::cout << "I can't fly" << std::endl;
    }
};

/**
 * @brief
 * QuackBehavior �����ж�����Ϊ����
 *      class Quack��class MuteQuack��Squeak ��̳иýӿ�
 */
class QuackBehavior{
public:
    QuackBehavior() = default;
    ~QuackBehavior() = default;

public:
    virtual void quack( ) = 0;
};

class Quack : public QuackBehavior{
public:
    Quack();
    ~Quack();

public:
    void quack( ){
        std::cout << "Quack" << std::endl;
    }
};

class MuteQuack : public QuackBehavior{
public:
    void quack( ){
        std::cout << " <<Slience>> " << std::endl;
    }
};

class Squeak : public QuackBehavior{
public:
    void quack( ){
        std::cout << "Squeak" << std::endl;
    }
};


/**
 * @brief:
 * Duck���а�������������: FlyBehavior�� QuackBehavior
 *      FlyBehavior   �ӿڣ��� fly ���˷�װ
 *      QuackBehavior �ӿڣ��� Quack(�¸�)���˷�װ
 */
class Duck{
public:
    Duck() = default;
    ~Duck(){
        delete _fly_behavior;
        delete _quack_behavior;
    }

public:
    // ����Ѽ�ӵĹ�����Ϊ
    void Swim( ){
        std::cout << "All ducks float, even decoys!" << std::endl;
    }
    
    void Display( ){
        std::cout << "Duck's Display" << std::endl;
    }

    // ί�и��ӿ�ִ��
    void PerformFly( ){
        _fly_behavior->Fly();
    }

    void PerformQuack( ){
        _quack_behavior->quack();
    }

// ���ﲻ������ private����Ȼ�޷��޸�ָ��ָ��
protected:
    FlyBehavior*     _fly_behavior;
    QuackBehavior*   _quack_behavior; 
};



// ���� Ѽ���� MiniDuckSimulator
class MiniDuckSimulator : public Duck{
public:
    MiniDuckSimulator() {
        _fly_behavior = new FlyWithWings();
        _quack_behavior = new Squeak();
    }
    ~MiniDuckSimulator();
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