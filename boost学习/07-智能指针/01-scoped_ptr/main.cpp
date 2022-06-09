/**
 * scoped_ptr
 *  除了 scoped_ptr自己，其他任何人都五千访问被管理的指针
 *  这样也保证了指针的安全性
 * 
 * auto_ptr
 *  auto_ptr之间不能共享拥有权，但可以通过赋值或构造转移拥有权，
 *  一旦拥有权转移，不可以再次使用此auto_ptr。程序员必须防范一个原始指针被两个auto_ptr所拥有。
 *【注】 auto_ptr已经在 C++标准中被声明为 “废弃”
 * 
 * 示例：
 *  下面的代码 分别给出了 auto_ptr、scoped_ptr的例子
 */

#include <iostream>
#include <boost/scoped_ptr.hpp>

using namespace boost;

class A{
public:
    A( int _a ) : m_a(_a){
        std::cout << "ctor" << std::endl;
    }
    ~A( ){
        std::cout << "dtor" << std::endl;
    }

    int m_a;
};


int main( ){
// auto_ptr，注：auto_ptr已废弃
std::cout << "test 1 auto_ptr" << std::endl;

    std::auto_ptr<A> p1( new A(100) );
    std::cout << p1->m_a << std::endl;

    // warning:  'template<class> class std::auto_ptr' is deprecated: use 'std::unique_ptr'
    std::auto_ptr<A> p2(p1);    // 调用 copy ctor()     此时p1失去所有权
    //std::cout << "p1: " << p1->m_a << "\tp2: " << p2->m_a << std::endl;
    std::cout << "p2: " << p2->m_a << std::endl;

    std::auto_ptr<A> p3;
    p3 = p2;
    // std::cout << "p2: " << p2->m_a << std::endl;     // wrong
    // std::cout << "p3: " << p3->m_a << std::endl;     // wrong

// scoped_ptr 本节学习的重点
std::cout << "test 2 scoped_ptr" << std::endl;
    scoped_ptr<A> s1( new A(150) );
    std::cout << "s1 value:\t" << s1->m_a << std::endl;
    s1->m_a = 200;
    std::cout << "s1 value:\t" << s1->m_a << std::endl;

    // copy()
    // scoped_ptr<A> s2(s1);    // private

    // operator =
    scoped_ptr<A> s3;
    // s3 = s1;                 // private

    getchar();

    return 0;
}
