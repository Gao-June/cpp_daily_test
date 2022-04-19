// ̽����ʽת��

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
        std::cout << " Ĭ�Ϲ��캯�� " << std::endl;
    }

    // ��������� explicit Entity���� �������ʽת���Ͳ������ˡ�
    Entity( int age ) : _Age(age), _Name( "Unknown" ) 
    {
        std::cout << " ������ age �Ĺ��캯�� " << std::endl;
    }

    Entity( const std::string name ) : _Age( -1 ), _Name( name ) 
    {
        std::cout << " ������ name �Ĺ��캯�� " << std::endl;
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
    std::cout << "�鿴��ʽת���Ľ��" << std::endl;
    // entity.Print();      // Ϊʲô��������޷�������
    entity.Hello();
}

int main( ){
    Entity e1(12);
    e1.Print();

    Entity e2("jeffy");     // char* -> std::string
    e2.Print();
    
    Print_Entity(14);   // int -> int -> Entity

    // Print_Entity("gao");  // ������ʾ ���ܶ� gao ������ʽת��
    Print_Entity( (std::string)"gao" );     // char* -> string -> Entity;

    
    Entity a =  16;         // int - > Entity
    // Entity b = "maffy";  // ������ʽת��
    Entity c = (std::string)"jack";     // char* -> string -> Entity;

    return 0;
}