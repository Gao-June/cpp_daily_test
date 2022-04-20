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

    // 再补充一个 const 版本
    // const 指针只能调用 const 方法。 如果 class Entity 里函数不是  cosnt就不能调用
    const Entity* operator-> () const
    {
        return m_Obj;
    }
};

int main( )
{
    Entity e1;
    e1.Print();     // 可以直接使用

    Scoped_Ptr e2 = new Entity();
    // e2.m_Obj->Print();       //wrong! m_Obj是 private，所以无法访问
    e2.Get_Object()->Print();   // 通过函数得到 m_Obj

    /** 本节学的就是将e2像指针一样使用 ->
     * eg. Entity* entity = new Entity();
     *     entity->Print();
    */
    e2->Print();

    // 验证 const 指针只能调用 const func
    e2->Non_const_Print();

    const Scoped_Ptr e3 = new Entity();
    e3->Print();
    // e3->Non_const_Print();   // wrong 无法调用

    return 0;
}