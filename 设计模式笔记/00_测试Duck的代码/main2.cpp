#include <iostream>

//飞行行为虚基类
class FlyBehavior 
{
public:
    FlyBehavior();
    virtual ~FlyBehavior();
public:
    virtual int Fly() = 0;        
};
 
//飞行具体类
class FlyWithWings : public FlyBehavior
{
public:
    FlyWithWings();
    ~FlyWithWings();
public:
    virtual int Fly();
};
 
 
//嘎嘎叫行为虚基类
class QuackBehavior
{
public:
    QuackBehavior();
    virtual ~QuackBehavior();
public:
    virtual int Quack() = 0;        
};
 
//叫具体类
class Squeak : public QuackBehavior
{
public:
   Squeak();
    ~Squeak();
public:
    virtual int Quack();
};
 
//鸭子类
class Duck
{
public:
    Duck();
    virtual ~Duck();
public:
    int Display();
    void PerformFly(){ m_pFlyBehavior->Fly(); }
    void PerformQuack(){ m_pQuackBehavior-> Quack(); }
    //其他行为
protected:
    FlyBehavior *m_pFlyBehavior;
    QuackBehavior *m_pQuackBehavior;
};
 
 
//具体鸭子类
class MallardDuck : public Duck
{
public: 
    MallardDuck();
    ~MallardDuck();
};
 
MallardDuck :: MallardDuck()
{
    m_pFlyBehavior = new FlyWithWings();
    m_pQuackBehavior =  new Squeak();
}
 
MallardDuck :: ~MallardDuck()
{
}
 
 
//测试类
int main()
{
    Duck *mallard = new MallardDuck();
    mallard->PerformFly();
    mallard->PerformQuack();

    return 0;
}