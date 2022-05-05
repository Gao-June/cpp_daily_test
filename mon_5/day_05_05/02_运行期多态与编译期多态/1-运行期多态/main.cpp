/**
 * 运行时的多态存在于继承类中，通过虚函数实现动态选择调用。
 *  简单的说就是通过一张虚函数表——vptable，vptable中记录了基类的虚函数地址，
 *  在派生类中继承了基类的这张vptable，
 *  而且在派生类的构造函数中对继承来的vptable相关地址进行替换，
 *  因此在调用时通过vptable的实际地址能够知道调用哪个函数。
 * 
 * 总之动态多态发生在继承关系的类中，通过虚函数表实现。
 * 
 * 
 * ==编译时多态和运行时多态区别==
 * 1、运行时体现了面向对象的思想，但是虚函数表增加了内存开销
 * 2、运行时多态发生在运行时期，所以编译器无法进行优化处理
 * 3、编译时多态运用泛型编程，在编译器完成提升运行期效率，
 *      但是无法实现模板的分离编译所以对于大工程而言编译耗时
 * 4、编译时多态无法处理异质对象集合(什么是异质对象？)
 * 
 * 下面是个简单的范例
 */
 
#include <iostream>
class CBase
{
public:
	CBase(){std::cout<<"CBase::CBase"<<std::endl;}
	~CBase(){std::cout<<"CBase::~CBase"<<std::endl;}
 
	virtual int getMax(int a, int b)
	{
		std::cout<<"CBase::getMax"<<std::endl;
		return a>b?a:b;
	}
};
 
class CChild : public CBase
{
public:
	CChild(){std::cout<<"CChild::CChild"<<std::endl;}
	~CChild(){std::cout<<"CCHild::~Child"<<std::endl;}
 
	virtual int getMax(int a, int b)
	{
		std::cout<<"CChild::getMax"<<std::endl;
		return a>b?a:b;
	}
};
 
int main()
{
	CBase *pBase = new CBase;	
	CChild *pChld = new CChild;
	pBase->getMax(5, 2);
	pBase = new CChild;
	pBase->getMax(5,2);
	getchar();

	return 0;
}