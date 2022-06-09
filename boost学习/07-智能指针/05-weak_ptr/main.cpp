/**
 * weak_ptr
 *      weak_ptr设计的目的是为了来协助 shared_ptr工作，
 *      它只可以从一个 shared_ptr或另一个 weak_ptr对象构造，
 *      它的构造和析构不起引用记数的增加或减少，
 * 使用需要包含头文件：
 *      #include<boost/weak_ptr.hpp>
 * 【注】
 *      C++11标准中的 std::weak_ptr 与 boost::weak_ptr 功能相似。
 *      shared_ptr 构造或析构导致引用计数加减1，而 weak_ptr 不会引起引用计数的改变。
 */

#include<iostream>
#include<boost/weak_ptr.hpp>
#include<boost/shared_ptr.hpp>

using namespace  boost;
using namespace std;

class  A{
public:
   A( ){
   	cout << "构造A类对象！" << endl;
   }

   ~A( ){
   	cout << "析构A类对象！" << endl;
   } 

   int m_a; 
};

int main()
{ 
   boost::shared_ptr<A>  p1( new  A);       // 引用计数+1
   cout << p1.unique() << " , " << p1.use_count() << endl;

// weak_ptr 是 shared_ptr 的协助者，或者是一个配角，主要用于观察
   boost::weak_ptr<A>  p2(p1);//不改变引用计数
   cout << p1.unique() << " , " << p1.use_count() << endl;

   /*用于观察shared_ptr指向的内存是否释放 */
   cout << p2.expired() << " , " << p2.use_count() << endl;

// weak_ptr 不管理这块内存
   // p2->m_a;//错误的
   // *p2.m_a = 100;//错误的

   boost::shared_ptr<A>  p3(p1);// 引用计数+1
   boost::shared_ptr<A>  p4(p3);// 引用计数+1

   //用weak_ptr来观察一下
   cout << p2.expired()<< " , " << p2.use_count() << endl;

   p1.reset();	 //释放管理权 ， 引用计数-1
   p3.reset();	 //释放管理权 ， 引用计数-1
   p4.reset();	 //释放管理权 ， 引用计数-1，此刻内存释放

    /* 返回1表示内存已经释放 */
   cout << p2.expired() << " , " << p2.use_count() << endl;

   return 0;
}

