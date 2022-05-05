/**
 * ��̬��̬�Ƿ����ڱ���ʱ�ڵģ�ͨ��ģ��ͺ�������ʵ�֣�
 *  ��ȶ�̬��̬����������ϵ��
 * 
 * ���濴һ������
 */

#include <iostream>

using namespace std;

class Animal{
public :
    void shout() { cout << "��������Ľ���" << endl; };
};

class Dog{
public:
     void shout(){ cout << "������"<<endl; }
};

class Cat{
public:
     void shout(){ cout << "����~"<<endl; }
};

class Bird{
public:
     void shout(){ cout << "ߴ��!"<<endl; }
};

template <typename T>
void  animalShout(T& t){
    t.shout();
}


int main()
{
    Animal anim;
    Dog dog;
    Cat cat;
    Bird bird;
 
    animalShout(anim);
    animalShout(dog);
    animalShout(cat);
    animalShout(bird);
 
    return 0;
}