/*
    ��ϰʹ�� static_cast
*/

#include <vector>
#include <iostream>

using namespace std;
 
struct B {
    int m = 0;
    void hello() const {
        std::cout << "Hello world, this is B!\n";
    }
};
struct D : B {
    void hello() const {
        std::cout << "Hello world, this is D!\n";
    }
};
 
enum class E { ONE = 1, TWO, THREE };
enum EU { ONE = 1, TWO, THREE };
 
int main()
{
    // 1: initializing conversion
    // ��ͨ��������ת��
    cout << "no.1 :  " << endl;
    int n = static_cast<int>(3.14); 
    std::cout << "n = " << n << '\n';
    std::vector<int> v = static_cast<std::vector<int>>(10);
    std::cout << "v.size() = " << v.size() << '\n';
 
    // 2: static downcast
    // ����ط���ͬĿ¼����д�Ĳ��԰���
    cout << "no.2 :  " << endl;
    D d;
    B& br = d; // upcast via implicit conversion
    br.hello();
    D& another_d = static_cast<D&>(br); // downcast     // ����ת���ǰ�ȫ�ģ�ע�� ����ת���ǲ���ȫ��
    another_d.hello();
 
    // 3: lvalue to xvalue
    cout << "no.3 :  " << endl;
    std::vector<int> v2 = static_cast<std::vector<int>&&>(v);
    std::cout << "after move, v.size() = " << v.size() << '\n';
 
    // 4: discarded-value expression
    cout << "no.4 :  " << endl;
    static_cast<void>(v2.size());
 
    // 5. inverse of implicit conversion
    void* nv = &n;
    int* ni = static_cast<int*>(nv);
    std::cout << "*ni = " << *ni << '\n';
 
    // 6. array-to-pointer followed by upcast
    D a[10];
    [[maybe_unused]]
    B* dp = static_cast<B*>(a);
 
    // 7. scoped enum to int or float
    E e = E::ONE;
    int one = static_cast<int>(e);
    std::cout << one << '\n';
 
    // 8. int to enum, enum to another enum
    E e2 = static_cast<E>(one);
    [[maybe_unused]]
    EU eu = static_cast<EU>(e2);
 
    // 9. pointer to member upcast
    int D::*pm = &D::m;
    std::cout << br.*static_cast<int B::*>(pm) << '\n';
 
    // 10. void* to any type
    void* voidp = &e;
    [[maybe_unused]]
    std::vector<int>* p = static_cast<std::vector<int>*>(voidp);
}