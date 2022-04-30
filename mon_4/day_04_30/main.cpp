#include <iostream>

using namespace std;

class Base{
public:
    virtual void Print( ) = 0;

    virtual ~Base(){
        cout << "over" << endl;
    }
};


class Entity : public Base{
public:
    virtual  ~Entity( ){
        cout << "ent" <<endl;
    }

    void Print( ){
        cout << "hello world" << endl;
    }
};

int main( ){
    Base* base = new Entity();
    base->Print();

    return 0;
}
