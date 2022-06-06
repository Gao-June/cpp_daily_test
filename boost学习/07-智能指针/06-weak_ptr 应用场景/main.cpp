/**
 * weak_ptr��������Ϊһ������ָ����ʹ�ã�
 *      ����->���ʣ�*�����ã�
 *      Ҳ���ܼ���Ƿ�Ϊ�գ�
 *      ��������Ϊ shared_ptr�Ĺ۲��ߡ�
 * ��һ�����������³�����
 *      ��������ڴ��Ƿ��ͷ�
 *      ���ѭ����������
 * ˵����
 *      ��ʹ�� weak_ptrʱ������һ������� expired() �ж����Ƿ���ڣ�
 *      ���û�й�����ɷ������������Դ��
 *      ��weak_ptr�����ܲ�����Դ����*��->��������
 *      ��������Ҫ���� weak_ptr����ָ�����Դʱ��
 *      Ӧʹ��lock()������ȡһ��shared_ptr��ͨ�� shared_ptr��������Դ��
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
   	cout << "����A�����" << endl;
   }
   ~A( )  
   {
   	cout << "����A�����" << endl;
   } 
   int m_a; 
};

class  B
{
public:
   B()
   {
   	cout << "����A�����" << endl;
   }
   ~B()
   {
   	cout << "����A�����" << endl;
   }
    
   //boost::shared_ptr<B>  m_b;  
   boost::weak_ptr<B>  m_b; //�������Ϊweak_ptr����ı����ü���
};


int main()
{ 
cout << "test.1 ��������ڴ��Ƿ��ͷ�" << endl;

   boost::shared_ptr<A>  p1(new  A);//���ü���Ϊ1
   p1->m_a = 100;

   boost::shared_ptr<A>  p2(p1);//���ü���+1

   cout << p1.use_count() << ","<< p2.use_count() << endl;

   boost::weak_ptr<A>  w1(p1);//��Ӱ�����ü������۲���
   cout << w1.expired()<< "," << w1.use_count() << endl;

   //�˿̣���p1�ͷŹ���Ȩ
   p1.reset();//���ü���-1
   cout << p1.get() << "," << p1.use_count() << endl;

   //ͨ��w1���۲죨�ɴ˿ɼ�����Ȼp1�����˹���Ȩ������w1��Ȼ������������
   cout << w1.expired() << "," << w1.use_count() << endl;

   if (w1.expired())//�۲���ڴ��ͷ���
   {
   	cout << "�ڴ��ͷ���!" << endl;
   }
   else
   {
   	//cout << p1->m_a << endl; //�����Ѿ���������Ȩ��
   	//w1->m_a; //����weak_ptr����->, ���ܹ�*

   	boost::shared_ptr<A>   p3=w1.lock(); //����ʹ��lock����shared_ptr
   	cout << p3->m_a << endl;
   }


cout << "test.2  ���ѭ����������" << endl;
    {
   boost::shared_ptr<B>  q1(new  B);//���ü���Ϊ1
    
   cout << q1.unique() << "," << q1.use_count() << endl;
    
   //��������ѭ������
   q1->m_b = q1;//   shared_ptr��ֵ����������������+1

   cout << q1.unique() << "," << q1.use_count() << endl;
   } //������ʱ��p1�������ڽ����������������������ü���-1������ע�⣬2-1>0
     //���� new A����ڴ治�ᱻ�ͷţ� ����m_a��ԱҲ�����ͷţ������͵��������ü���
     //һֱ��Ϊ0�� ��new A������ڴ�й©


   getchar();
   return 0;
}
