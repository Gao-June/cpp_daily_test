/**
 * 这里使用了C++17 的特性 string_view
 * 通过对 operator new() 的测试，能节省 一半的内存开销
*/

#include <iostream>
#include <string>

class String{
public:
    std::string _Name;

    String( ) : _Name( "unknown" ) {}
    String( std::string name ) : _Name( name ){}

    void* operator new( size_t Size ){
        std::cout << "Allocate String" << Size << "  bytes\n";
        return malloc( Size );
    }

    void Print( ){
        std::cout << "String  " << _Name << std::endl;
    }
};

class String_view{
public:
    std::string_view _Name_view;

    String_view( std::string_view name, size_t a ) : _Name_view( name ){}

    void* operator new( size_t Size ){
        std::cout << "Allocate " << Size << "  bytes\n";
        return malloc( Size );
    }

    void Print( ){
        std::cout << "String_view  " <<  _Name_view << std::endl;
    }
};

int main( ){
    String Name1( "abcdefghijklmnopqrstuvwxyz" );
    Name1.Print();

// test 1
// 这里会调用 operator new， 显示开辟了32 bytes
    std::cout << "test 1" << std::endl;
    String *Name2 = new String;
    Name2->Print();

// test 2
// 这里会调用 operator new， 显示开辟了32 bytes
    std::cout << "test 2" << std::endl;
    String *Name3 = new String( Name1._Name.substr(0,15));
    Name3->Print();     // Jeffy

// test 3
// 使用 string_view， 显示开辟了16  bytes
    std::cout << "test 3" << std::endl;
    //String_view Name4( "Jeffy_Gao2" );
    String_view *Name5 = new String_view( Name1._Name.c_str(), 15 );
    Name5->Print();


    return 0;
}
