/**
 * shared_ptr
 *      shared_ptr是可以共享所有权的指针。
 *      如果有多个shared_ptr共同管理同一个对象时，只有这些 shared_ptr全部与该对象分离之后，
 *      被管理的对象才会被释放，
 *使用需要包含头文件：
 *      #include <boost/shared_ptr.hpp>
 *【说明】
        c++11标准中 std::shared_ptr 与 boost::shared_ptr 功能相似。
        shared_ptr 使用引用计数，每一个 shared_ptr 的拷贝都指向相同的内存；
        每关联一次，内部的引用计数加1。
 【一些函数介绍】
    unique()   : 是否只有一个绑定
    use_count(): 引用计数数量
    get()      : 返回指针地址
    reset()    : 手动分离管理权
 【注意事项】
    1 - shared_ptr 不能引用栈内存
    2 - shared_ptr 不能多次引用同一原始指针，否则同一内存会被 delete 多次
    3 - shared_ptr 循环引用导致内存泄露
    4 - shared_ptr 管理的内存必须是new出来的
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
   boost::shared_ptr<A>  p1(new A);//引用计数为1
   //此时唯一管理A的内存
   cout << p1.unique() << " ,  " << p1.use_count() << endl;

   //此时， p1,p2同时管理A的内存
   boost::shared_ptr<A>  p2( p1 ); //拷贝构造，引用计数+1
   cout << p2.unique() << " ,  " << p2.use_count() << endl;

   boost::shared_ptr<A>  p3; 
   p3 = p2;//赋值运算符  引用计数+1
   cout << p1.unique() << " ,  " << p1.use_count() << endl;

   //3个智能指针指向同一地址
   cout << p1.get() << " ,  " << p2.get() << " ,  " << p3.get() << " ,  " << endl;

   //手动分离管理权
   p1.reset();//  引用计数-1
   cout << p2.unique() << " ,  " << p2.use_count() << endl;
   cout << p3.unique() << " ,  " << p3.use_count() << endl;

   p2.reset();//  引用计数-1 
   cout << p3.unique() << " ,  " << p3.use_count() << endl;

   p3.reset();//引用计数-1 ，此时，全部放弃了管理权，A内存就会释放

   cout << "结束！" << endl;

   return 0;
}
