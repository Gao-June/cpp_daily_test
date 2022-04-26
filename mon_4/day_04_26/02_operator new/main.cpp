/**
 * ����ʹ����C++17 ������ string_view
 * ͨ���� operator new() �Ĳ��ԣ��ܽ�ʡ һ����ڴ濪��
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
// �������� operator new�� ��ʾ������32 bytes
    std::cout << "test 1" << std::endl;
    String *Name2 = new String;
    Name2->Print();

// test 2
// �������� operator new�� ��ʾ������32 bytes
    std::cout << "test 2" << std::endl;
    String *Name3 = new String( Name1._Name.substr(0,15));
    Name3->Print();     // Jeffy

// test 3
// ʹ�� string_view�� ��ʾ������16  bytes
    std::cout << "test 3" << std::endl;
    //String_view Name4( "Jeffy_Gao2" );
    String_view *Name5 = new String_view( Name1._Name.c_str(), 15 );
    Name5->Print();


    return 0;
}
