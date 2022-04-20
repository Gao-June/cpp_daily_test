#include <iostream>

class Entity
{
private:
    int x;
public:
    void Print( ) const
    {
        std::cout << "hello world!" << std::endl;
    }

    void Non_const_Print( )
    {
        std::cout << "this is non const func" << std::endl;
    }
};

class Scoped_Ptr
{
private:
    Entity* m_Obj;
public:
    Scoped_Ptr( Entity* entity ) : m_Obj(entity) {}

    ~Scoped_Ptr()
    {
        delete m_Obj;
    }

    Entity* Get_Object()
    {
        return m_Obj;
    }

    // operator ->
    Entity* operator-> ()
    {
        return m_Obj;
    }

    // �ٲ���һ�� const �汾
    // const ָ��ֻ�ܵ��� const ������ ��� class Entity �ﺯ������  cosnt�Ͳ��ܵ���
    const Entity* operator-> () const
    {
        return m_Obj;
    }
};

int main( )
{
    Entity e1;
    e1.Print();     // ����ֱ��ʹ��

    Scoped_Ptr e2 = new Entity();
    // e2.m_Obj->Print();       //wrong! m_Obj�� private�������޷�����
    e2.Get_Object()->Print();   // ͨ�������õ� m_Obj

    /** ����ѧ�ľ��ǽ�e2��ָ��һ��ʹ�� ->
     * eg. Entity* entity = new Entity();
     *     entity->Print();
    */
    e2->Print();

    // ��֤ const ָ��ֻ�ܵ��� const func
    e2->Non_const_Print();

    const Scoped_Ptr e3 = new Entity();
    e3->Print();
    // e3->Non_const_Print();   // wrong �޷�����

    return 0;
}