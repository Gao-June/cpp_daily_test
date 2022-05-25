/*
������
    ֻ��һ��ʵ��

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
    static Singleton* CreateObject( ){
        // �������ָ���� Null���ʹ���
        if( m_pObject == nullptr ){
            m_pObject = new Singleton( );
        }
        return m_pObject;
    }

    void Change_num( int num ){
        m_num = num;
    }

    int Return_num( ){
        return m_num;
    }

private:
    Singleton( ){
        std::cout << "ctor" << std::endl;
    }

    static Singleton* m_pObject;
    int m_num = 0;
};

// ����calssָ���ʼ��һ�¡�����дҲ�У�
Singleton* Singleton::m_pObject = nullptr;

int main( ){
    Singleton* Obj1 = Singleton::CreateObject();
    Singleton* Obj2 = Singleton::CreateObject();

    //���֣����ܴ������ٸ����󣬶���ͬһ�� class
    std::cout << "Obj1��ַ��" << Obj1 << "\tObj2��ַ��" << Obj2 << std::endl;

    // ���������Ԫ�أ�
    std::cout << "Obj1 num = " << Obj1->Return_num() << "\tObj2 num = " << Obj2->Return_num() << std::endl;
    Obj1->Change_num(15);
    std::cout << "Obj1 num = " << Obj1->Return_num() << "\tObj2 num = " << Obj2->Return_num() << std::endl;
    Obj2->Change_num(18);
    std::cout << "Obj1 num = " << Obj1->Return_num() << "\tObj2 num = " << Obj2->Return_num() << std::endl;

    return 0;
}