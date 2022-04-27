/**
 * ��� ��02_move ���캯��������������ʾ��
 * �ٴ���Ϥʹ�� std::move()
 *      std::move ��һ���ɱ�׼���ṩ��ʵ�ú���
 *      �ڱ���ʱ�������ҳ��������ʲô���͡�
 * ���ⲹ���� assignment move��
 * ���´�����ʾ��ֻ������һ���ڴ档
*/


#include <iostream>
#include <cstring>

class String{
public:
    String( ) = default;

    // Ĭ�Ϲ��캯��
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
     * assignment move �ƶ���ֵ������
     * ע�⣺ʵ������ move ctor���ڹ��캯���й�����һ���¶��󣩲�ͬ��
     *      operator = ʵ�����ǰ���һ������move����ǰ������
     *      ��˸����˵�ǰ����
     *      �֣���ǰ��������Ѿ��������ڴ�
     *      �ʣ���Ҫ������ǰ�ͷţ������ڴ�й©����
     * ���⣬����һ����Ҫע��ģ�
     *      ��Ҫȷ����ֵǰ �������󲢲���ȣ���Ȼ delete[]��Ͱű�Q�ˡ�
    */ 
    String& operator= ( String&& other ) noexcept{
        std::cout << "Assignment" << std::endl;

        // ��������ж�
        if ( this != &other ){
            delete[] m_Data;    // ��һ�м�����Ҫ��

            m_Size = other.m_Size;
            m_Data = other.m_Data;  
            other.m_Size = 0;
            other.m_Data = nullptr;
        }
        return *this;
    }


    // ��������
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
 * ����ϣ�� str_1 ����ֵ
 *      String str_2 = str_1;   
 * ����-1 
 *  =>    String str_2 = (String &&) str_1;
 * ����-2 ������ʽת��
 *  =>    String str_2( (String &&)str_1 );
 * ���Ƿ���-1��-2����̫��û��Ҳ���Ƕ�ÿ�����Ͷ�����
 * ����-3 std::move
 *        ʹ����΢���һ��ĺ������ڱ���ʱ�������ҳ��������ʲô���͡�
 *  =>    String str_2( std::move(str_1) );
 *      std::move ��һ���ɱ�׼���ṩ��ʵ�ú�����
 * 
 * ���������
 *      Created!       str_1 ��ʵ�� 
 *      Move!          "hello_world"���� String����ʱ����Ҫ���¿��ٶ��ϵĿռ�
 *      hello_world    str_2.Print_Entity()
 *      Destroyed!     str_1��str_2������
 *      Destroyed!     
*/
int main( ){
std::cout << "Test No.1" << std::endl;
    String str_1 = "hello_world";

std::cout << "Test No.2" << std::endl;
    // ͬ String str_2 = std::move( str_1 );
    String str_2( std::move(str_1) );
    str_2.Print_String();

std::cout << "Test No.3" << std::endl;
    // ��չ�� operator = 
    // ʹ֮�ܹ�ʵ�� str3 = str2;
    String str_3 = "hello_world";
    String str_4;
    std::cout << "01_  str_3: ";
    str_3.Print_String();
    std::cout << "02_  str_4: ";
    str_4.Print_String();

    str_4 = std::move(str_3);   // assignment
    std::cout << "03_  str_3: ";
    str_3.Print_String();       // ��ʱ���������
    std::cout << "04_  str_4: ";
    str_4.Print_String();


    std::cout << "Test End" << std::endl;
    return 0;
}