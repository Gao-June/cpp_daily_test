/*
简述：
    只有一个实例

使用场景：
    在使用 日志 class的时候，可以使用单例模式，这样它就只有一个实例了。
    不用考虑对象的生成，和释放。

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
    5 - 内存释放问题需要考虑
        如果不按照 - 5 改进，会发现程序没调用析构函数
        因此将 指针对象放到 CreateObject() 里
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
    // 这里有一个细节：
    //      不能将 Obj 写成下面这种指针类型； 不然用户调用 delete Obj1、Obj2就完犊子了
    //      所以应该 return by reference
    //static Singleton* CreateObject( ){
    static Singleton& CreateObject( ){
        // 如果对象指针是 Null，就创建
        // if( m_pObject == nullptr ){
        //     m_pObject = new Singleton( );
        // }
        // return m_pObject;

        // 由理由 - 5 改进：
        static Singleton obj;

        //return &obj;
        return obj;
    }

    // 禁止其 copy ctor
    Singleton( Singleton& obj ) = delete;

    void Change_num( int num ){
        m_num = num;
    }

    int Return_num( ){
        return m_num;
    }

private:
    // 构造函数放在 private 中，
    // 则外界在创建该对象的时候无法调用该构造函数（即，无法在外界创建该对象）。
    Singleton( ){
        std::cout << "ctor" << std::endl;
    }

    // static Singleton* m_pObject;     // 由理由 - 5 取消了这句
    int m_num = 0;
};

// 给该calss指针初始化一下。（不写也行）
//Singleton* Singleton::m_pObject = nullptr;    // 由理由 - 5 取消了这句

int main( ){
    // 这样写的话 用户可以 delete Obj1、Obj2
    // Singleton* Obj1 = Singleton::CreateObject();
    // Singleton* Obj2 = Singleton::CreateObject();
    
    // 这样写的话 用户可以 不用 reference  比如: Singleton Obj3 = Singleton::CreateObject();
    // 因此还需要对 class 里的 ctor 进行限制，禁止其 copy ctor
    // 这样 = 左边只能用 reference 来接收
    Singleton& Obj1 = Singleton::CreateObject();
    Singleton& Obj2 = Singleton::CreateObject();
    // Singleton Obj3 = Singleton::CreateObject();     // wrong


    //发现，不管创建多少个对象，都是同一个 class
    std::cout << "Obj1地址：" << &Obj1 << "\tObj2地址：" << &Obj2 << std::endl;

    // 测试其具体元素：
    std::cout << "Obj1 num = " << Obj1.Return_num() << "\tObj2 num = " << Obj2.Return_num() << std::endl;
    Obj1.Change_num(15);
    std::cout << "Obj1 num = " << Obj1.Return_num() << "\tObj2 num = " << Obj2.Return_num() << std::endl;
    Obj2.Change_num(18);
    std::cout << "Obj1 num = " << Obj1.Return_num() << "\tObj2 num = " << Obj2.Return_num() << std::endl;

    return 0;
}