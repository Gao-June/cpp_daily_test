// 再练习一下 operator 操作

#include <iostream>

class Entity
{
private:
    int _x, _y;

public:
    Entity( int x, int y ) : _x(x), _y(y) {}

    void Print();
    Entity operator+ ( const Entity& entity);
    Entity operator+= ( const Entity& entity );
};

void Entity::Print()
{
    std::cout << "x : " << _x << "  y: " << _y << std::endl;
}

Entity Entity::operator+ ( const Entity& entity )
{
    return Entity( this->_x + entity._x, this->_y + entity._y );
}

Entity Entity::operator+= ( const Entity& entity )
{
    this->_x += entity._x;
    this->_y += entity._y;
    return *this;
}

int main()
{
    Entity a(1,1);
    a.Print();
    Entity b(2,2);
    b.Print();

    a = a+b;
    a.Print();

    Entity c(3,3);
    c += a;
    c.Print();

    return 0;
}