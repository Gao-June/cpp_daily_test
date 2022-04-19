// 探究隐式转换

#include <iostream>
#include <string>

static int Num_Count = 1;

class Entity
{
private:
    int _Age;
    std::string _Name;

public:
    Entity( )
    {
        std::cout << " 默认构造函数 " << std::endl;
    }

    // 如果这里变成 explicit Entity…… 下面的隐式转换就不能用了。
    Entity( int age ) : _Age(age), _Name( "Unknown" ) 
    {
        std::cout << " 调用了 age 的构造函数 " << std::endl;
    }

    Entity( const std::string name ) : _Age( -1 ), _Name( name ) 
    {
        std::cout << " 调用了 name 的构造函数 " << std::endl;
    }

    void Print();

    void Hello() const{
        std::cout << "hello" << std::endl;
    }
};

void Entity::Print()
{
    std::cout << " The age is : " << _Age << "  The name is :  " << _Name << std::endl;
}


void Print_Entity(const Entity& entity )
{
    std::cout << "查看隐式转换的结果" << std::endl;
    // entity.Print();      // 为什么这个函数无法被调用
    entity.Hello();
}

int main( ){
    Entity e1(12);
    e1.Print();

    Entity e2("jeffy");     // char* -> std::string
    e2.Print();
    
    Print_Entity(14);   // int -> int -> Entity

    // Print_Entity("gao");  // 这里提示 不能对 gao 进行隐式转换
    Print_Entity( (std::string)"gao" );     // char* -> string -> Entity;

    
    Entity a =  16;         // int - > Entity
    // Entity b = "maffy";  // 不能隐式转换
    Entity c = (std::string)"jack";     // char* -> string -> Entity;

    return 0;
}