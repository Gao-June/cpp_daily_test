// 我自己再写一遍试试

#include <iostream>

class Singleton{
public:
    ~Singleton( ){
        std::cout << "dtor" << std::endl;
    }

    // 禁止 copy ctor
    Singleton( Singleton& obj ) = delete;

    // 以 引用 形式返回 单例
    static Singleton& CreateSingle( ){
        static Singleton obj;
        return obj;
    }

    int Print_num( ){
        return m_value;
    }

    void Change_num( int val ){
        m_value = val;
    }

private: 
    Singleton( ){
        std::cout << "ctor" << std::endl;
    }

    int m_value = 0;
};

int main( ){
    Singleton& obj1 = Singleton::CreateSingle();
    Singleton& obj2 = Singleton::CreateSingle();
    // Singleton obj3 = Singleton::CreateSingle();     // wrong

    std::cout << "obj1 : " << obj1.Print_num() << "\tobj2 : " << obj2.Print_num() << std::endl;
    obj1.Change_num(100);
    std::cout << "obj1 : " << obj1.Print_num() << "\tobj2 : " << obj2.Print_num() << std::endl;
    obj2.Change_num(200);
    std::cout << "obj1 : " << obj1.Print_num() << "\tobj2 : " << obj2.Print_num() << std::endl;

    return 0;
}