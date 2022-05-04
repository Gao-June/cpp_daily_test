/**
 * 有些场景仍然需要 写成 non-member func进行隐式类型转换（implicit type conversion）
 * 《Effective C++》 条款-24：若所有参数皆需类型转换，请为此采用 Non-member func()
 * 
 * 举例： 写一个 operator*， 然后测试其交换律
 * 结论：
 *  当在 member func() 中，写成Entity operator* ( const Entity& e) 会造成不能隐式转换的问题；
 *  当写成 non-member func()时候，写成Entity operator* ( const Entity& e1, const Entity& e2 )
 *      可以完成隐式转换
 * 【注】
 *      在写 operator* 的时候，e1 * e2 return的是一个 临时值，所以函数要 return-by-value
 *      我自己写了一个 operator *=， 可以发现返回值是自身，因此可以 return-by-reference
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

    // p.s 接下面（operator*），如果我写成 *=， 这样能用 const Entity& operator*=(...)吗？
    // 可以的！
    const Entity& operator*= ( const Entity& e){
        this->_x *= e.Get_x();
        this->_y *= e.Get_y();
        return *this;
    }


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
// p.s. 这里不能写成 const Entity& operator*(...) 因为不能对一个临时值进行返回其 reference
const Entity operator* ( const Entity& e1, const Entity& e2 ){
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

    // 测试 *=
    std::cout << "test No.3" << std::endl;
    Entity e5(1, 2);
    Entity e6(1, 2);
    e5 *= e6;
    e5.Print();

    return 0;
}