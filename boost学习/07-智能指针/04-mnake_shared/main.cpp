/**
 * make_shared
 * 用法其实和 shared_ptr差不多，只是屏蔽了 new，也避免了其带来的麻烦
 * 
 * 【目的】消除 new 带来的麻烦
 *      shared_ptr消除了显式的 delete调用，
 *      很大程度上避免了程序员忘记 delete而导致的内存泄漏。
 *      但 shared_ptr的构造依然需要ηew，这导致了代码中的某种不对称性，
 *      它应该使用工厂模式来解决。
 * make_shared()
 *      Boost库提供了一个自由工厂函数 make shared<T>()，来消除显式的new调用，
 *  声明如下：
 *          template<class T,class... Args>
            shared_ptr<T> make_shared(Args && ... args);
        make_shared()函数模板使用变长参数模板，
        最多可接受10个参数然后把它们传递给T的构造函数，
        创建一个 shared_ptr<T>的对象并返回。
        make_shared()函数要比直接创建 shared_ptr对象的方式更高效，
        因为它內部仅分配一次內存。
    头文件：
        #include<boost/make_shared.hpp>

 */


#include<iostream>
#include<boost/make_shared.hpp>

using namespace  boost;
using namespace std; 

class  A
{
public:
   A(int _a ,float _b, char _c ,string _d)  	
   {
        a=_a ; b = _b; c = _c; d = _d;
        cout << "构造A类对象！" << endl;
   }

   ~A( )  
   {
   	    cout << "析构A类对象！" << endl;
   } 

   int a; 
   float b; 
   char c; 
   string d;
};

int main()
{ 
//原始的方式构造 shared_ptr，需要 new，产生一种不对称性
   boost::shared_ptr<A>  p1(new A(100, 1.234f, 'C', "hello"));
   cout << p1->a << ", " << p1->b << ", " << p1->c<< ", " << p1->d << endl;

//推荐使用工厂函数，屏蔽 new ,更高效
   boost::shared_ptr<A>  p2  =  boost::make_shared<A>(100, 1.234f, 'C', "hello");
   cout << p2->a << ", " << p2->b << ", " << p2->c << ", " << p2->d << endl;

   getchar();
   return 0;
}
