/**
 * 问题抛出：不允许类被拷贝、赋值
 *          每个 class 都是独一无二的，不希望 copy ctor和 assignment
 * 
 * 很奇怪，我只要不定义 copy()，那么在 main() 中就不能调用了呀？
 * 其它方法：
 *  1 - 将 copy() 放到 private
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
    e1(e2);     // 将copy()放到 private中
                //      wrong: 'Entity& Entity::operator()(Entity&)' is private within this context
                // 使用 Entity& operator() (Entity& e) = delete;
                //      error: use of deleted function 'Entity& Entity::operator()(Entity&)'
    
    e1.Print();

    return 0;
}