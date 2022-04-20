#include <iostream>
#include <cstring>

class String
{
private:
    unsigned int _Size_Buffer;
    char* _Buffer;

public:
    // 默认构造函数, 浅拷贝
    String( const char* str )
    {
        _Size_Buffer = strlen( str );
        _Buffer = new char[_Size_Buffer + 1];
        memcpy( _Buffer, str, _Size_Buffer + 1 );
    }

    // 拷贝构造函数，深拷贝
    String( const String& other_str ) : _Size_Buffer( other_str._Size_Buffer )
    {
        _Buffer = new char[_Size_Buffer + 1];
        memcpy( _Buffer, other_str._Buffer, _Size_Buffer + 1 );
    }

    // operator <<
    friend std::ostream& operator<< ( std::ostream &stream, const String string  );

    // operator[]
    char& operator[] ( unsigned int index );

};

std::ostream& operator<< ( std::ostream &stream, const String string )
{
    stream << "buffer: " <<  string._Size_Buffer << "  string:  " << string._Buffer << std::endl;
    return stream;
}

// operator[]
char& String::operator[] ( unsigned int index )
{
    return _Buffer[index];
}


int main()
{
    String str1( "hello_01" );
    std::cout << str1 << std::endl;

// 把深拷贝代码注释掉，就会调用默认的拷贝构造函数
    std::cout << "使用浅拷贝" << std::endl;
    String str2(str1);      
    std::cout << str2 << std::endl;
    str2[2] = 'E';
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;

// 使用深拷贝
    std::cout << "使用深拷贝" << std::endl;
    String str3( "yes_sir" );
    String str4(str3);      
    std::cout << str4 << std::endl;
    str4[2] = 'E';
    std::cout << str3 << std::endl;
    std::cout << str4 << std::endl;

    return 0;
}