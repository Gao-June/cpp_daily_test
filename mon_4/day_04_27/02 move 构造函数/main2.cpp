/**
 * 问题描述：
 *      class 在拷贝过程中可能调用 默认构造函数和拷贝构造函数
 *      这样可能（由2次拷贝）导致空间资源浪费
 * 解决方法：用 移动语义 来解决。
 *      在此示例中，只需写一个 move 构造函数，这和 copy构造函数相似，
 *      除了它接收的是一个右值（临时值）之外。
 *      可以看到，实际只开辟了一块内存空间（而不是2块）
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

// move 构造函数
// 通过指定 move 构造函数，希望在执行“复制”时，不会复制内存，而是变成移动
// 当没有 move ctor时系统会调用 copy ctor； 有时，则调用 move ctor
// noexcept 运算符进行编译时检查，若表达式声明为不抛出任何异常则返回true。
    String( String&& other ) noexcept{
        std::cout << "Move! " << std::endl;

// 在这里直接复制数据，而不是分配新的内存缓冲区
// 现在这两个指针其实指向 同一块内存区了
        m_Size = other.m_Size;
        m_Data = other.m_Data;  

/**在这里的时候引出一个问题：
* 因为我们此刻仍然有 2 个字符串实例（m_Data, other.m_Data），当旧的
* 被删除之后会发生什么？ => 它会把数据带走
* 我们控制了 other.m_Data，偷走了 other.m_Data的数据
* 因此：还需要处理另一个字符串： 
*/
        other.m_Size = 0;
        other.m_Data = nullptr;
/**
 * 这样就只是接管了旧字符串(other.m_Data)，而不是通过复制它所有的数据和
 * 分配新的内存来进行深拷贝。（这里相当于做了一个浅拷贝）
*/
    }


    // 析构函数
    ~String( ){
        std::cout << "Destroyed!" << std::endl;

/**
 *  当旧字符串实例被销毁后， delete m_Data会删除 other.m_Data 的nullptr
 *  
*/        
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

/** 这里做了相应更改，让其能够接收右值。下面两个写法一样
 *      Entity( String&& name ) : m_Name( (String&&)name ) {}
 * 另外，剖析：
 *      name在传参的时候已经声明了 String &&，右值，为什么函数体内还要 std::move(name)?
 * =>   右值引用在进入函数体内后会变成左值。用专业的说法叫 "引用折叠"
 * 示例：
 *      int &&rr1 = 42; // 正确
 *      int &&rr2 = rr1; // 错误
 *      int &&rr3 = std::move(rr1); // 正确
 * 
 * 具体解释：
 *      因为右值引用在进入函数体内的之后, 参数类型会变为左值
 *      也就是在函数体内你可以对 String&& name中的 name取 &
 *      所以要触发移动语义必须让他变为右值引用, std::move 就是干这个转换的
 *      你看std::move的代码 就是干了一个找到源参数类型的static_cast转换
 *      把参数换成了 &&类 型。所以就能触发后面的移动构造函数
*/
    Entity( String&& name ) : m_Name( std::move(name) ) {}

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
 *      Created!      "Jeffy_Gao" 被实例 
 *      Move!         "Jeffy_Gao"传入 Entity，这时候不需要重新开辟堆上的空间
 *      Destroyed!    "Jeffy_Gao" 被析构
 *      Jeffy_Gao     entity.Print_Entity()
 * 
 *      // 程序结束后还有一个 Destroyed， 是 Entity里的 m_Name 的析构
*/
    std::cout << "test main2.cpp" << std::endl;
    Entity entity( "Jeffy_Gao" );
    entity.Print_Entity();

// 这里防止程序直接结束
    std::cin.get();
}