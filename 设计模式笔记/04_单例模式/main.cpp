/*
������
    ֻ��һ��ʵ��

ʹ�ó�����
    ��ʹ�� ��־ class��ʱ�򣬿���ʹ�õ���ģʽ����������ֻ��һ��ʵ���ˡ�
    ���ÿ��Ƕ�������ɣ����ͷš�

�뷨��
    ��Ҫ�� ctor �������ơ�ʹ���� private�������û�����ͨ��ctor��������
    
��ע�������
    1 - ��Ҫ�ṩһ���ӿڣ����û��ܣ�ȥ��������
    2 - �ýӿ�Ӧ�÷���һ�� ָ�����͵� class
    3 - ��������Ӧ����  static�����������������һ����̬������
        ��Ȼ�Ļ�������Ҫ�ȴ������󣬲��ܵ���CreateObject������
        ����û�ж����ʱ��Ҳ�ܵ��øú���������һ���ǳ�Ա������
    4 - ��Ҫ��һ�� ����ָ�루prvate��
        ��Ȼ���ǿ��Դ����ܶ� class
        ����Ҫ�� static �ģ���Ȼ���Ǹ� class ����
    5 - �ڴ��ͷ�������Ҫ����
        ��������� - 5 �Ľ����ᷢ�ֳ���û������������
        ��˽� ָ�����ŵ� CreateObject() ��
����֤��
    ���� private ����˸����� test_num��Ȼ�󴴽���Ա���� Change_num ���в���
*/

#include <iostream>

class Singleton{
public:
    ~Singleton( ){
        std::cout << "dtor" << std::endl;
    }

    // �ӿڣ����ڴ����� ����
    // ������һ��ϸ�ڣ�
    //      ���ܽ� Obj д����������ָ�����ͣ� ��Ȼ�û����� delete Obj1��Obj2���궿����
    //      ����Ӧ�� return by reference
    //static Singleton* CreateObject( ){
    static Singleton& CreateObject( ){
        // �������ָ���� Null���ʹ���
        // if( m_pObject == nullptr ){
        //     m_pObject = new Singleton( );
        // }
        // return m_pObject;

        // ������ - 5 �Ľ���
        static Singleton obj;

        //return &obj;
        return obj;
    }

    // ��ֹ�� copy ctor
    Singleton( Singleton& obj ) = delete;

    void Change_num( int num ){
        m_num = num;
    }

    int Return_num( ){
        return m_num;
    }

private:
    // ���캯������ private �У�
    // ������ڴ����ö����ʱ���޷����øù��캯���������޷�����紴���ö��󣩡�
    Singleton( ){
        std::cout << "ctor" << std::endl;
    }

    // static Singleton* m_pObject;     // ������ - 5 ȡ�������
    int m_num = 0;
};

// ����calssָ���ʼ��һ�¡�����дҲ�У�
//Singleton* Singleton::m_pObject = nullptr;    // ������ - 5 ȡ�������

int main( ){
    // ����д�Ļ� �û����� delete Obj1��Obj2
    // Singleton* Obj1 = Singleton::CreateObject();
    // Singleton* Obj2 = Singleton::CreateObject();
    
    // ����д�Ļ� �û����� ���� reference  ����: Singleton Obj3 = Singleton::CreateObject();
    // ��˻���Ҫ�� class ��� ctor �������ƣ���ֹ�� copy ctor
    // ���� = ���ֻ���� reference ������
    Singleton& Obj1 = Singleton::CreateObject();
    Singleton& Obj2 = Singleton::CreateObject();
    // Singleton Obj3 = Singleton::CreateObject();     // wrong


    //���֣����ܴ������ٸ����󣬶���ͬһ�� class
    std::cout << "Obj1��ַ��" << &Obj1 << "\tObj2��ַ��" << &Obj2 << std::endl;

    // ���������Ԫ�أ�
    std::cout << "Obj1 num = " << Obj1.Return_num() << "\tObj2 num = " << Obj2.Return_num() << std::endl;
    Obj1.Change_num(15);
    std::cout << "Obj1 num = " << Obj1.Return_num() << "\tObj2 num = " << Obj2.Return_num() << std::endl;
    Obj2.Change_num(18);
    std::cout << "Obj1 num = " << Obj1.Return_num() << "\tObj2 num = " << Obj2.Return_num() << std::endl;

    return 0;
}