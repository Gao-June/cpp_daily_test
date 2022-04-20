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
        std::cout << "调用了默认构造函数" << std::endl;
        _Size_Buffer = strlen( str );
        _Buffer = new char[_Size_Buffer + 1];
        memcpy( _Buffer, str, _Size_Buffer + 1 );
    }

    //拷贝构造函数，深拷贝
    String( const String& other_str ) : _Size_Buffer( other_str._Size_Buffer )
    {
        std::cout << "调用了 深拷贝" << std::endl;
        _Buffer = new char[_Size_Buffer + 1];
        memcpy( _Buffer, other_str._Buffer, _Size_Buffer + 1 );
    }

    // operator <<
    // 【注】 后面如果写成 const String string 的话，还会调用一次深拷贝哦~
    // 所以传参的时候一般都是  const + & 结合
    friend std::ostream& operator<< ( std::ostream &stream, const String& string  );

    // operator[]
    char& operator[] ( unsigned int index );

};

std::ostream& operator<< ( std::ostream &stream, const String& string )
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
// 把深拷贝代码注释掉，就会调用默认的拷贝构造函数(浅拷贝)
    String str1( "hello_01" );
    String str2(str1);
    std::cout << "using operator<< :" << std::endl;       
    std::cout << str2 << std::endl;
    str2[2] = 'E';
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;


    return 0;
}