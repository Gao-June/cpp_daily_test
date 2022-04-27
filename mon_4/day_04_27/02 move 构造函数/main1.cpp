/**
 * ����������
 *      class �ڿ��������п��ܵ��� Ĭ�Ϲ��캯���Ϳ������캯��
 *      �������ܣ���2�ο��������¿ռ���Դ�˷�
 * ����������� �ƶ����� �������
 *      �ڴ�ʾ���У�ֻ��дһ�� move ���캯������� copy���캯�����ƣ�
 *      ���������յ���һ����ֵ����ʱֵ��֮��
 * ����չʾ��
 *      main1.cpp ���� 2 �� copy����
 *      main2.cpp ʹ�� move ���캯�����գ��� copy���캯��ע�͵���
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

    // ��������
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
 * ���ͣ�
 *      ��������� ���� class String�� 
 *      Ȼ�����copy���캯�� �� class Entity 
 * ���������
 *      Created! 
 *      Copy!
 *      Destroyed!
 *      Jeffy_Gao
 *      Destroyed!
*/
    std::cout << "test main1.cpp" << std::endl;
    Entity entity( "Jeffy_Gao" );
    entity.Print_Entity();

// �����ֹ����ֱ�ӽ���
    std::cin.get();
}