/**
 * 问题描述：
 *      class 在拷贝过程中可能调用 默认构造函数和拷贝构造函数
 *      这样可能（由2次拷贝）导致空间资源浪费
 * 解决方法：用 移动语义 来解决。
 *      在此示例中，只需写一个 move 构造函数，这和 copy构造函数相似，
 *      除了它接收的是一个右值（临时值）之外
 * 代码展示：
 *      main1.cpp 复现 2 次 copy过程
 *      main2.cpp 使用 move 构造函数对照（把 copy构造函数注释掉）
*/

#include <iostream>
#include <cstring>

class String{
public:
    String( ) = default;

    // 默认构造函数
    String( const char* string ){
        std::cout << "Created! " << std::endl;
        m_Size = strlen( string );
        m_Data = new char[m_Size];
        memcpy( m_Data, string, m_Size );
    }

    // copy 构造函数
    String( const String& other ){
        std::cout << "Copy! " << std::endl;
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy( m_Data, other.m_Data, m_Size );
    }

    // 析构函数
    ~String( ){
        std::cout << "Destroyed!" << std::endl;
        delete[] m_Data;
    }

    void Print_String( ){
        for( uint32_t i = 0; i < m_Size; i ++ ){
            std::cout << m_Data[i];
        }
        std::cout << std::endl;
    }

private:
    char*    m_Data;
    uint32_t m_Size;
};

class Entity{
public:
    Entity( const String& name ) : m_Name( name ) {}

    void Print_Entity( ){
        m_Name.Print_String();
    }
private:
    String m_Name;
};

int main( ){
/**
 * 解释：
 *      这里会首先 构造 class String， 
 *      然后调用copy构造函数 给 class Entity 
 * 函数输出：
 *      Created! 
 *      Copy!
 *      Destroyed!
 *      Jeffy_Gao
 *      Destroyed!
*/
    std::cout << "test main1.cpp" << std::endl;
    Entity entity( "Jeffy_Gao" );
    entity.Print_Entity();

// 这里防止程序直接结束
    std::cin.get();
}