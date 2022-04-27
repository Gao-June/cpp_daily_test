/**
 * ����������
 *      class �ڿ��������п��ܵ��� Ĭ�Ϲ��캯���Ϳ������캯��
 *      �������ܣ���2�ο��������¿ռ���Դ�˷�
 * ����������� �ƶ����� �������
 *      �ڴ�ʾ���У�ֻ��дһ�� move ���캯������� copy���캯�����ƣ�
 *      ���������յ���һ����ֵ����ʱֵ��֮�⡣
 *      ���Կ�����ʵ��ֻ������һ���ڴ�ռ䣨������2�飩
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

// move ���캯��
// ͨ��ָ�� move ���캯����ϣ����ִ�С����ơ�ʱ�����Ḵ���ڴ棬���Ǳ���ƶ�
// ��û�� move ctorʱϵͳ����� copy ctor�� ��ʱ������� move ctor
// noexcept ��������б���ʱ��飬�����ʽ����Ϊ���׳��κ��쳣�򷵻�true��
    String( String&& other ) noexcept{
        std::cout << "Move! " << std::endl;

// ������ֱ�Ӹ������ݣ������Ƿ����µ��ڴ滺����
// ����������ָ����ʵָ�� ͬһ���ڴ�����
        m_Size = other.m_Size;
        m_Data = other.m_Data;  

/**�������ʱ������һ�����⣺
* ��Ϊ���Ǵ˿���Ȼ�� 2 ���ַ���ʵ����m_Data, other.m_Data�������ɵ�
* ��ɾ��֮��ᷢ��ʲô�� => ��������ݴ���
* ���ǿ����� other.m_Data��͵���� other.m_Data������
* ��ˣ�����Ҫ������һ���ַ����� 
*/
        other.m_Size = 0;
        other.m_Data = nullptr;
/**
 * ������ֻ�ǽӹ��˾��ַ���(other.m_Data)��������ͨ�����������е����ݺ�
 * �����µ��ڴ�������������������൱������һ��ǳ������
*/
    }


    // ��������
    ~String( ){
        std::cout << "Destroyed!" << std::endl;

/**
 *  �����ַ���ʵ�������ٺ� delete m_Data��ɾ�� other.m_Data ��nullptr
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

/** ����������Ӧ���ģ������ܹ�������ֵ����������д��һ��
 *      Entity( String&& name ) : m_Name( (String&&)name ) {}
 * ���⣬������
 *      name�ڴ��ε�ʱ���Ѿ������� String &&����ֵ��Ϊʲô�������ڻ�Ҫ std::move(name)?
 * =>   ��ֵ�����ڽ��뺯�����ں������ֵ����רҵ��˵���� "�����۵�"
 * ʾ����
 *      int &&rr1 = 42; // ��ȷ
 *      int &&rr2 = rr1; // ����
 *      int &&rr3 = std::move(rr1); // ��ȷ
 * 
 * ������ͣ�
 *      ��Ϊ��ֵ�����ڽ��뺯�����ڵ�֮��, �������ͻ��Ϊ��ֵ
 *      Ҳ�����ں�����������Զ� String&& name�е� nameȡ &
 *      ����Ҫ�����ƶ��������������Ϊ��ֵ����, std::move ���Ǹ����ת����
 *      �㿴std::move�Ĵ��� ���Ǹ���һ���ҵ�Դ�������͵�static_castת��
 *      �Ѳ��������� &&�� �͡����Ծ��ܴ���������ƶ����캯��
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
 * ���ͣ�
 *      ��������� ���� class String�� 
 *      Ȼ�����copy���캯�� �� class Entity 
 * ���������
 *      Created!      "Jeffy_Gao" ��ʵ�� 
 *      Move!         "Jeffy_Gao"���� Entity����ʱ����Ҫ���¿��ٶ��ϵĿռ�
 *      Destroyed!    "Jeffy_Gao" ������
 *      Jeffy_Gao     entity.Print_Entity()
 * 
 *      // �����������һ�� Destroyed�� �� Entity��� m_Name ������
*/
    std::cout << "test main2.cpp" << std::endl;
    Entity entity( "Jeffy_Gao" );
    entity.Print_Entity();

// �����ֹ����ֱ�ӽ���
    std::cin.get();
}