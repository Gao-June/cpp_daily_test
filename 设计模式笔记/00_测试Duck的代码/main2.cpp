#include <iostream>

//������Ϊ�����
class FlyBehavior 
{
public:
    FlyBehavior();
    virtual ~FlyBehavior();
public:
    virtual int Fly() = 0;        
};
 
//���о�����
class FlyWithWings : public FlyBehavior
{
public:
    FlyWithWings();
    ~FlyWithWings();
public:
    virtual int Fly();
};
 
 
//�¸½���Ϊ�����
class QuackBehavior
{
public:
    QuackBehavior();
    virtual ~QuackBehavior();
public:
    virtual int Quack() = 0;        
};
 
//�о�����
class Squeak : public QuackBehavior
{
public:
   Squeak();
    ~Squeak();
public:
    virtual int Quack();
};
 
//Ѽ����
class Duck
{
public:
    Duck();
    virtual ~Duck();
public:
    int Display();
    void PerformFly(){ m_pFlyBehavior->Fly(); }
    void PerformQuack(){ m_pQuackBehavior-> Quack(); }
    //������Ϊ
protected:
    FlyBehavior *m_pFlyBehavior;
    QuackBehavior *m_pQuackBehavior;
};
 
 
//����Ѽ����
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
 
 
//������
int main()
{
    Duck *mallard = new MallardDuck();
    mallard->PerformFly();
    mallard->PerformQuack();

    return 0;
}