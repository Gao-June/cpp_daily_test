/**
 * 针对 “02_move 构造函数”给出的两个示例
 * 再次熟悉使用 std::move()
 *      std::move 是一个由标准库提供的实用函数
 *      在编译时，它会找出输入的是什么类型。
 * 另外补充了 assignment move版
 * 如下代码所示，只开辟了一次内存。
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

    // copy ctor
    String( const String& other ){
        std::cout << "Copy! " << std::endl;
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy( m_Data, other.m_Data, m_Size );
    }

    // move ctor
    String( String&& other ) noexcept{
        std::cout << "Move" << std::endl;

        m_Size = other.m_Size;
        m_Data = other.m_Data;  
        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    /**
     * assignment move 移动赋值操作符
     * 注意：实际上与 move ctor（在构造函数中构造了一个新对象）不同，
     *      operator = 实际上是把另一个对象move到当前对象中
     *      因此覆盖了当前对象
     *      又，当前对象可能已经分配了内存
     *      故，需要做到提前释放（避免内存泄漏）。
     * 另外，还有一个需要注意的：
     *      需要确保赋值前 两个对象并不相等，不然 delete[]后就芭比Q了。
    */ 
    String& operator= ( String&& other ) noexcept{
        std::cout << "Assignment" << std::endl;

        // 特殊情况判断
        if ( this != &other ){
            delete[] m_Data;    // 这一行极其重要！

            m_Size = other.m_Size;
            m_Data = other.m_Data;  
            other.m_Size = 0;
            other.m_Data = nullptr;
        }
        return *this;
    }


    // 析构函数
    ~String( ){
        std::cout << "Destroyed" << std::endl;
    
        delete m_Data;
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

    Entity( String&& name ) : m_Name( std::move(name) ) {}

    void Print_Entity( ){
        m_Name.Print_String();
    }
private:
    String m_Name;
};


/**
 * 现在希望 str_1 是右值
 *      String str_2 = str_1;   
 * 方法-1 
 *  =>    String str_2 = (String &&) str_1;
 * 方法-2 做了隐式转换
 *  =>    String str_2( (String &&)str_1 );
 * 但是方法-1、-2都不太有没，也不是对每个类型都适用
 * 方法-3 std::move
 *        使用稍微灵活一点的函数，在编译时，它会找出输入的是什么类型。
 *  =>    String str_2( std::move(str_1) );
 *      std::move 是一个由标准库提供的实用函数，
 * 
 * 函数输出：
 *      Created!       str_1 被实例 
 *      Move!          "hello_world"传入 String，这时候不需要重新开辟堆上的空间
 *      hello_world    str_2.Print_Entity()
 *      Destroyed!     str_1、str_2被析构
 *      Destroyed!     
*/
int main( ){
std::cout << "Test No.1" << std::endl;
    String str_1 = "hello_world";

std::cout << "Test No.2" << std::endl;
    // 同 String str_2 = std::move( str_1 );
    String str_2( std::move(str_1) );
    str_2.Print_String();

std::cout << "Test No.3" << std::endl;
    // 扩展了 operator = 
    // 使之能够实现 str3 = str2;
    String str_3 = "hello_world";
    String str_4;
    std::cout << "01_  str_3: ";
    str_3.Print_String();
    std::cout << "02_  str_4: ";
    str_4.Print_String();

    str_4 = std::move(str_3);   // assignment
    std::cout << "03_  str_3: ";
    str_3.Print_String();       // 这时候无输出了
    std::cout << "04_  str_4: ";
    str_4.Print_String();


    std::cout << "Test End" << std::endl;
    return 0;
}