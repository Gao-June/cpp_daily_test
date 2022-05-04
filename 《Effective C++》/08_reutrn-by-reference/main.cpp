/**
 * ����̽�� return-by-reference �� return by object������
 * 
 * ������
 *  дһ��class������ operator +����̽���� ctor��dtor
 * ����:
 *  Entity& : return by reference ������ + �Ĺ����е��� ctor��dtor
 *  Entity  : return by value     ����+ �Ĺ����е��� copy ctor��dtor
 */

#include <iostream>

class Entity{
public:
    Entity( int x, int y ) : _x(x), _y(y){
        std::cout << "ctor" << std::endl;
    }
    Entity( const Entity& e ) : _x(e._x), _y(e._y){
        std::cout << "copy ctor" << std::endl;
    }
    ~Entity( ){
        std::cout << "dtor" << std::endl;
    }

public:
    // Entity& : return by reference ������ + �Ĺ����е��� ctor��dtor
    // Entity  : return by value     ����+ �Ĺ����е��� copy ctor��dtor
    //Entity operator+ ( const Entity& e ){
    Entity& operator+ ( const Entity& e ){
        this->_x += e._x;
        this->_y += e._y;
        return *this;
    }

    void Print( ) const{
        std::cout << "x: " << _x << "  y: " << _y << std::endl;
    }

private:
    int _x, _y;
};

int main( ){
    Entity e1(1, 2);
    Entity e2(2, 4);
    e1.Print();
    e2.Print();

    std::cout << "test: " << std::endl;
    e1 = e1 + e2;
    e1.Print();

    return 0;
}