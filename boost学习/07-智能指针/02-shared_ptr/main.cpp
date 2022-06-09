/**
 * shared_ptr
 *      shared_ptr�ǿ��Թ�������Ȩ��ָ�롣
 *      ����ж��shared_ptr��ͬ����ͬһ������ʱ��ֻ����Щ shared_ptrȫ����ö������֮��
 *      ������Ķ���Żᱻ�ͷţ�
 *ʹ����Ҫ����ͷ�ļ���
 *      #include <boost/shared_ptr.hpp>
 *��˵����
        c++11��׼�� std::shared_ptr �� boost::shared_ptr �������ơ�
        shared_ptr ʹ�����ü�����ÿһ�� shared_ptr �Ŀ�����ָ����ͬ���ڴ棻
        ÿ����һ�Σ��ڲ������ü�����1��
 ��һЩ�������ܡ�
    unique()   : �Ƿ�ֻ��һ����
    use_count(): ���ü�������
    get()      : ����ָ���ַ
    reset()    : �ֶ��������Ȩ
 ��ע�����
    1 - shared_ptr ��������ջ�ڴ�
    2 - shared_ptr ���ܶ������ͬһԭʼָ�룬����ͬһ�ڴ�ᱻ delete ���
    3 - shared_ptr ѭ�����õ����ڴ�й¶
    4 - shared_ptr ������ڴ������new������
 */

#include <iostream>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;

class A{
public:
    A( ){
        std::cout << "ctor" << std::endl;
    }
    ~A( ){
        std::cout << "dtor" << std::endl;
    }

    int m_a;
};


int main()
{ 
   boost::shared_ptr<A>  p1(new A);//���ü���Ϊ1
   //��ʱΨһ����A���ڴ�
   cout << p1.unique() << " ,  " << p1.use_count() << endl;

   //��ʱ�� p1,p2ͬʱ����A���ڴ�
   boost::shared_ptr<A>  p2( p1 ); //�������죬���ü���+1
   cout << p2.unique() << " ,  " << p2.use_count() << endl;

   boost::shared_ptr<A>  p3; 
   p3 = p2;//��ֵ�����  ���ü���+1
   cout << p1.unique() << " ,  " << p1.use_count() << endl;

   //3������ָ��ָ��ͬһ��ַ
   cout << p1.get() << " ,  " << p2.get() << " ,  " << p3.get() << " ,  " << endl;

   //�ֶ��������Ȩ
   p1.reset();//  ���ü���-1
   cout << p2.unique() << " ,  " << p2.use_count() << endl;
   cout << p3.unique() << " ,  " << p3.use_count() << endl;

   p2.reset();//  ���ü���-1 
   cout << p3.unique() << " ,  " << p3.use_count() << endl;

   p3.reset();//���ü���-1 ����ʱ��ȫ�������˹���Ȩ��A�ڴ�ͻ��ͷ�

   cout << "������" << endl;

   return 0;
}
