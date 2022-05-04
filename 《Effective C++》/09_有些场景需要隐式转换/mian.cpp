/**
 * 有些场景仍然需要 写成 non-member func进行隐式类型转换（implicit type conversion）
 * 《Effective C++》 条款-24：若所有参数皆需类型转换，请为此采用 Non-member func()
 * 
 * 举例： 写一个 operator*， 然后测试其交换律
 * 结论：
 *  当在 member func() 中，写成Entity operator* ( const Entity& e) 会造成不能隐式转换的问题；
 *  当写成 non-member func()时候，写成Entity operator* ( const Entity& e1, const Entity& e2 )
 *      可以完成隐式转换
 */

#include <iostream>

class Entity{
public:
    // 在构造函数中给个初始值，方便后面的 * 运算
    Entity( int x = 0, int y = 0) : _x(x), _y(y){
        std::cout << "ctor" << std::endl;
    }
    Entity( const Entity& e ) : _x(e._x), _y(e._y){
        std::cout << "copy ctor" << std::endl;
    }
    ~Entity( ){
        std::cout << "dtor" << std::endl;
    }

public:
    void Print( ) const{
        std::cout << "x: " << _x << " y: " << _y << std::endl;
    }

    // Entity operator* ( const Entity& e){
    //     this->_x *= e._x;
    //     this->_y *= e._y;
    //     return *this;
    // }

    // 由于 _x, _y 是 private，所以需要写 func() 得到该变量
    int Get_x( ) const{
        return _x;
    }
    int Get_y( ) const {
        return _y;
    }

private:
    int _x, _y;
};

// 写成 non-member func()
    Entity operator* ( const Entity& e1, const Entity& e2 ){
        return Entity( e1.Get_x() * e2.Get_x(), e1.Get_y() * e2.Get_y());
    }

int main( ){
    std::cout << "test No.1" << std::endl;
    Entity e1(1, 2);
    Entity e2(3, 4);
    e1.Print();
    e2.Print();
    e1 = e1 * e2;
    e1.Print();

    std::cout << "test No.2" << std::endl;
    Entity e3(1, 2);
    Entity e4(1,2);
    e3 = e3 * 2;
    e3.Print();

    // Entity operator* ( const Entity& e) 时不能隐式转换
    // 写成 non-member func时候可以隐式转换
    e4 = 2 * e4;

    e4.Print();

    return 0;
}