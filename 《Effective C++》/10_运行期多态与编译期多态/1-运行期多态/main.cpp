/**
 * ����ʱ�Ķ�̬�����ڼ̳����У�ͨ���麯��ʵ�ֶ�̬ѡ����á�
 *  �򵥵�˵����ͨ��һ���麯������vptable��vptable�м�¼�˻�����麯����ַ��
 *  ���������м̳��˻��������vptable��
 *  ������������Ĺ��캯���жԼ̳�����vptable��ص�ַ�����滻��
 *  ����ڵ���ʱͨ��vptable��ʵ�ʵ�ַ�ܹ�֪�������ĸ�������
 * 
 * ��֮��̬��̬�����ڼ̳й�ϵ�����У�ͨ���麯����ʵ�֡�
 * 
 * 
 * ==����ʱ��̬������ʱ��̬����==
 * 1������ʱ��������������˼�룬�����麯�����������ڴ濪��
 * 2������ʱ��̬����������ʱ�ڣ����Ա������޷������Ż�����
 * 3������ʱ��̬���÷��ͱ�̣��ڱ������������������Ч�ʣ�
 *      �����޷�ʵ��ģ��ķ���������Զ��ڴ󹤳̶��Ա����ʱ
 * 4������ʱ��̬�޷��������ʶ��󼯺�(ʲô�����ʶ���)
 * 
 * �����Ǹ��򵥵ķ���
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