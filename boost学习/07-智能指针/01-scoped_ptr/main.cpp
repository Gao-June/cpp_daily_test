/**
 * scoped_ptr
 *  ���� scoped_ptr�Լ��������κ��˶���ǧ���ʱ������ָ��
 *  ����Ҳ��֤��ָ��İ�ȫ��
 * 
 * auto_ptr
 *  auto_ptr֮�䲻�ܹ���ӵ��Ȩ��������ͨ����ֵ����ת��ӵ��Ȩ��
 *  һ��ӵ��Ȩת�ƣ��������ٴ�ʹ�ô�auto_ptr������Ա�������һ��ԭʼָ�뱻����auto_ptr��ӵ�С�
 *��ע�� auto_ptr�Ѿ��� C++��׼�б�����Ϊ ��������
 * 
 * ʾ����
 *  ����Ĵ��� �ֱ������ auto_ptr��scoped_ptr������
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
// auto_ptr��ע��auto_ptr�ѷ���
std::cout << "test 1 auto_ptr" << std::endl;

    std::auto_ptr<A> p1( new A(100) );
    std::cout << p1->m_a << std::endl;

    // warning:  'template<class> class std::auto_ptr' is deprecated: use 'std::unique_ptr'
    std::auto_ptr<A> p2(p1);    // ���� copy ctor()     ��ʱp1ʧȥ����Ȩ
    //std::cout << "p1: " << p1->m_a << "\tp2: " << p2->m_a << std::endl;
    std::cout << "p2: " << p2->m_a << std::endl;

    std::auto_ptr<A> p3;
    p3 = p2;
    // std::cout << "p2: " << p2->m_a << std::endl;     // wrong
    // std::cout << "p3: " << p3->m_a << std::endl;     // wrong

// scoped_ptr ����ѧϰ���ص�
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
