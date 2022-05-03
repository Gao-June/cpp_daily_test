/**
 * copy ctor 里参数写 const，能调用非const class吗？
 * 可以， 不过要注意，const class只能调用 func() const{}
 */

#include <iostream>

class Entity{
public:
    Entity( int a, int b ) : _a(a), _b(b){
        std::cout << "ctor" << std::endl;
    }

    Entity( const Entity& e ){
        std::cout << "copy ctor" << std::endl;
        this->_a = e._a;
        this->_b = e._b;
    }

    void Print(  ){
        std::cout <<"non const Print(): " <<  "a: " << _a << "  b: " << _b << std::endl;
    }
    void Print(  ) const{
        std::cout <<"const Print(): " <<  "a: " << _a << "  b: " << _b << std::endl;
    }

private:
    int _a, _b;
};

int main( ){
    Entity a1(1, 2);
    const Entity a2(11, 12);
    a1.Print();
    a2.Print();

    Entity a3(a2);
    a3.Print();

    return 0;
}