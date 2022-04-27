/**
 * ��� ��02_move ���캯��������������ʾ��
 * �ٴ���Ϥʹ�� std::move
 * 
 *      std::move ��һ���ɱ�׼���ṩ��ʵ�ú���
 *      �ڱ���ʱ�������ҳ��������ʲô���͡�
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

    // copy ���캯��
    String( const String& other ){
        std::cout << "Copy! " << std::endl;
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy( m_Data, other.m_Data, m_Size );
    }

    String( String&& other ) noexcept{
        std::cout << "Move! " << std::endl;


        m_Size = other.m_Size;
        m_Data = other.m_Data;  

        other.m_Size = 0;
        other.m_Data = nullptr;
    }


    // ��������
    ~String( ){
        std::cout << "Destroyed!" << std::endl;
    
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
    String str_1 = "hello_world";
    String str_2( std::move(str_1) );
    str_2.Print_String();

    return 0;
}