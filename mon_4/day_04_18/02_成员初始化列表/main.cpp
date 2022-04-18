/*
    当 class 的成员变量有 class_a 的时候，
    使用 成员初始化列表指挥调用一次a的构造函数，
    而使用默认什么都不写的构造函数，要调用2次a的构造函数
*/

#include <iostream>
#include <string>

class Example{
public:
    int _x;

    Example()
    {
        std::cout << "This is Example() " << std::endl;
    }

    Example( int x )
    {
        std::cout << "This is Example(int x)" << x << std::endl;
    }
};

class Entity{
private:
    std::string e_Name;
    Example e_Example;

public:
    // 使用默认构造函数 这里会调用两次 Example的构造函数。
    // 在创建 e_Example变量的时候调用一次，在赋值的时候调用一次
    Entity()
    {
        e_Name = std::string( "unknown" );
        e_Example = Example(8);
    }

    // 使用成员初始化列表，只会调用一次 Example 的构造函数
    Entity( std::string Name, Example example ) : e_Name(Name), e_Example(example){}

};

int main( ){
    //Entity e0;      

    Entity e1( "GaoJune", Example(9) );


    return 0;
}