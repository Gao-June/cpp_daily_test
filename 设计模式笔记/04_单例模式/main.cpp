/*
简述：
    只有一个实例

想法：
    需要对 ctor 进行限制。使其变成 private，这样用户不能通过ctor产生对象。
    
【注意事项】：
    1 - 需要提供一个接口，（用户能）去创建对象。
    2 - 该接口应该返回一个 指针类型的 class
    3 - 函数类型应该是  static，这样这个函数就是一个静态函数。
        不然的话，必须要先创建对象，才能调用CreateObject函数。
        这样没有对象的时候也能调用该函数（这是一个非成员函数）
    4 - 需要加一个 对象指针（prvate）
        不然还是可以创建很多 class
        另，需要是 static 的，不然还是跟 class 绑定了
【验证】
    我在 private 里加了个变量 test_num，然后创建成员函数 Change_num 进行测试
*/

#include <iostream>

class Singleton{
public:
    ~Singleton( ){
        std::cout << "dtor" << std::endl;
    }

    // 接口，用于创建该 单例
    static Singleton* CreateObject( ){
        // 如果对象指针是 Null，就创建
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

// 给该calss指针初始化一下。（不写也行）
Singleton* Singleton::m_pObject = nullptr;

int main( ){
    Singleton* Obj1 = Singleton::CreateObject();
    Singleton* Obj2 = Singleton::CreateObject();

    //发现，不管创建多少个对象，都是同一个 class
    std::cout << "Obj1地址：" << Obj1 << "\tObj2地址：" << Obj2 << std::endl;

    // 测试其具体元素：
    std::cout << "Obj1 num = " << Obj1->Return_num() << "\tObj2 num = " << Obj2->Return_num() << std::endl;
    Obj1->Change_num(15);
    std::cout << "Obj1 num = " << Obj1->Return_num() << "\tObj2 num = " << Obj2->Return_num() << std::endl;
    Obj2->Change_num(18);
    std::cout << "Obj1 num = " << Obj1->Return_num() << "\tObj2 num = " << Obj2->Return_num() << std::endl;

    return 0;
}