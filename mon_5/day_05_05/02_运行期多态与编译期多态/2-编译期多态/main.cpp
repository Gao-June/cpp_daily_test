/**
 * 静态多态是发生在编译时期的，通过模板和函数重载实现，
 *  相比动态多态不需派生关系。
 * 
 * 下面看一个范例
 */

#include <iostream>

using namespace std;

class Animal{
public :
    void shout() { cout << "发出动物的叫声" << endl; };
};

class Dog{
public:
     void shout(){ cout << "汪汪！"<<endl; }
};

class Cat{
public:
     void shout(){ cout << "喵喵~"<<endl; }
};

class Bird{
public:
     void shout(){ cout << "叽喳!"<<endl; }
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