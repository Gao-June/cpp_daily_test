/**
 * �����׳����������౻��������ֵ
 *          ÿ�� class ���Ƕ�һ�޶��ģ���ϣ�� copy ctor�� assignment
 * 
 * ����֣���ֻҪ������ copy()����ô�� main() �оͲ��ܵ�����ѽ��
 * ����������
 *  1 - �� copy() �ŵ� private
 *  2 - operator()  = delete;
 */

#include <iostream>

class Entity{
public:
    Entity( int x, int y ) : _x(x), _y(y) {
        std::cout << "ctor" << std::endl;
    }
    ~Entity( ){
        std::cout << "dtor" << std::endl;
    } 

    // opertor()
    // Entity& operator() ( Entity& e ){
    //     this->_x = e._x;
    //     this->_y = e._y;
    //     return *this;
    // }

    Entity& operator() (Entity& e) = delete;

    void Print( ){
        std::cout << "x: " << _x << "  y:" << _y << std::endl;
    }

public:
    int _x, _y;

private:
    // Entity& operator() ( Entity& e );
};

int main( ){
    Entity e1(1,2);
    e1.Print();
    Entity e2(3,4);
    e2.Print();

    // copy()
    std::cout << "copy()" << std::endl;
    e1(e2);     // ��copy()�ŵ� private��
                //      wrong: 'Entity& Entity::operator()(Entity&)' is private within this context
                // ʹ�� Entity& operator() (Entity& e) = delete;
                //      error: use of deleted function 'Entity& Entity::operator()(Entity&)'
    
    e1.Print();

    return 0;
}