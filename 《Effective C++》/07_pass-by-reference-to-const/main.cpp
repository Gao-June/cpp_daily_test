/**
 * 尽量以 pass-by-reference-to-const 替换 pass-by-value
 * 本节探索 以&传递参数和 value传递参数的区别
 * 
 * 结论=>
 *  pass-by-reference 不会再调用 ctor 生成对象
 *  pass-by-value 会调用 class的 copy cotr 和 dtor
 */

#include <iostream>

class Entity{
public:
    Entity( ){
        std::cout << "ctor" << std::endl;
    }
    Entity( int x, int y) : _x(x), _y(y){
        std::cout << "ctor(int x, int y)" << std::endl;
    }
    // copy ctor
    Entity( const Entity& e ) : _x(e._x), _y(e._y){
         std::cout << "copy ctor" << std::endl;
    }

    ~Entity( ){
        std::cout << "dtor" << std::endl;
    }

    void Print( ) const{
        std::cout << "x: " << _x << "  y: " << _y << std::endl;
    }

private:
    int _x, _y;
};

// 用 &e 不会生成新的 ctor 和 dtor
// 用 e  会调用 copy ctor 和 dtor
void Print_Class( const Entity& e ){
    std::cout << "func(): " << std::endl;
    e.Print(); 
}

int main( ){
    Entity e1(1, 2);
    Print_Class( e1 );


    return 0;
}