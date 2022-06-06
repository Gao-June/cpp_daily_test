/**
 * weak_ptr并不能作为一个单独指针来使用：
 *      不能->访问，*解引用，
 *      也不能检查是否为空，
 *      它仅仅作为 shared_ptr的观察者。
 * 它一般运用于以下场景：
 *      检测管理的内存是否释放
 *      解决循环引用问题
 * 说明：
 *      在使用 weak_ptr时，我们一般会先用 expired() 判断其是否过期，
 *      如果没有过期则可访问所管理的资源，
 *      但weak_ptr并不能操作资源（无*，->操作），
 *      当我们想要访问 weak_ptr，所指向的资源时，
 *      应使用lock()方法获取一个shared_ptr，通过 shared_ptr来访问资源。
 */

#include<iostream>
using namespace std;   

#include<boost/weak_ptr.hpp>
#include<boost/shared_ptr.hpp>
using namespace  boost;

class  A
{
public:
   A()  	
   {
   	cout << "构造A类对象！" << endl;
   }
   ~A( )  
   {
   	cout << "析构A类对象！" << endl;
   } 
   int m_a; 
};

class  B
{
public:
   B()
   {
   	cout << "构造A类对象！" << endl;
   }
   ~B()
   {
   	cout << "析构A类对象！" << endl;
   }
    
   //boost::shared_ptr<B>  m_b;  
   boost::weak_ptr<B>  m_b; //解决，因为weak_ptr不会改变引用计数
};


int main()
{ 
cout << "test.1 检测管理的内存是否释放" << endl;

   boost::shared_ptr<A>  p1(new  A);//引用计数为1
   p1->m_a = 100;

   boost::shared_ptr<A>  p2(p1);//引用计数+1

   cout << p1.use_count() << ","<< p2.use_count() << endl;

   boost::weak_ptr<A>  w1(p1);//不影响引用计数，观察者
   cout << w1.expired()<< "," << w1.use_count() << endl;

   //此刻，让p1释放管理权
   p1.reset();//引用计数-1
   cout << p1.get() << "," << p1.use_count() << endl;

   //通过w1来观察（由此可见，虽然p1放弃了管理权，但是w1依然能正常工作）
   cout << w1.expired() << "," << w1.use_count() << endl;

   if (w1.expired())//观测的内存释放了
   {
   	cout << "内存释放了!" << endl;
   }
   else
   {
   	//cout << p1->m_a << endl; //错误，已经放弃管理权了
   	//w1->m_a; //错误，weak_ptr不能->, 不能够*

   	boost::shared_ptr<A>   p3=w1.lock(); //可以使用lock返回shared_ptr
   	cout << p3->m_a << endl;
   }


cout << "test.2  解决循环引用问题" << endl;
    {
   boost::shared_ptr<B>  q1(new  B);//引用计数为1
    
   cout << q1.unique() << "," << q1.use_count() << endl;
    
   //现在制造循环引用
   q1->m_b = q1;//   shared_ptr赋值操作，导致引用数+1

   cout << q1.unique() << "," << q1.use_count() << endl;
   } //到这里时候，p1生命周期结束，产生析构，导致引用计数-1，但是注意，2-1>0
     //所以 new A这块内存不会被释放， 所以m_a成员也不会释放，这样就导致了引用计数
     //一直不为0， 则new A的这块内存泄漏


   getchar();
   return 0;
}
