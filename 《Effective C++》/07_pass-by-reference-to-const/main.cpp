/**
 * ������ pass-by-reference-to-const �滻 pass-by-value
 * ����̽�� ��&���ݲ����� value���ݲ���������
 * 
 * ����=>
 *  pass-by-reference �����ٵ��� ctor ���ɶ���
 *  pass-by-value ����� class�� copy cotr �� dtor
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

// �� &e ���������µ� ctor �� dtor
// �� e  ����� copy ctor �� dtor
void Print_Class( const Entity& e ){
    std::cout << "func(): " << std::endl;
    e.Print(); 
}

int main( ){
    Entity e1(1, 2);
    Print_Class( e1 );


    return 0;
}