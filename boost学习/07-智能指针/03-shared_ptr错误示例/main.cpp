/**
 * ��ע�����
    1 - shared_ptr ��������ջ�ڴ�
    2 - shared_ptr ���ܶ������ͬһԭʼָ�룬����ͬһ�ڴ�ᱻ delete ���
    3 - shared_ptr ѭ�����õ����ڴ�й¶
    4 - shared_ptr ������ڴ������new������
 * 
 */

#include<iostream>
#include<boost/shared_ptr.hpp>

using namespace std;  
using namespace  boost;

class B;//���ǰ������

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
    boost::shared_ptr<B>  m_pb; //ָ��B���ڴ�
};


class  B
{
public:
   B()
   {
   	cout << "����B�����" << endl;
   }
   ~B()
   {
   	cout << "����B�����" << endl;
   }
   boost::shared_ptr<A>  m_pa;  //ָ��A���ڴ�
};

int main()
{ 
// ����1����Ҫ��ջ�ڴ��ַ����  scoped_ptr, scoped_array, shared_ptr
/* 
   int   a = 100;
   boost::shared_ptr<int >  p(&a);//����ʱ����
   cout << p.use_count() << endl;  

// ����2��shared_ptr ���ܶ������ͬһԭʼָ�룬����ͬһ�ڴ�ᱻ delete ���
   A  *pA = new  A;

   boost::shared_ptr<A>  p1(pA);
   cout << p1.use_count() << endl; 

   //boost::shared_ptr<A>  p2(pA);  // ���� p2 ����֪��p1�Ĵ���
   boost::shared_ptr<A>  p2(p1);    // ��ȷд��
   cout << p2.use_count() << endl;
   // p1 p2�ڶ�������ʱ������� delete pA���Ӷ�����
   

// ����3��shared_ptr ѭ�����õ����ڴ�й¶�� 
   boost::shared_ptr<A> pA(new  A);
   boost::shared_ptr<B> pB(new  B);
   cout << pA.use_count() << "   ,   " << pB.use_count() << endl;

   pA->m_pb = pB;   // �˿� ��pB ָ����ڴ����ü���Ϊ2
   pB->m_pa = pA;   // �˿� ��pA ָ����ڴ����ü���Ϊ2
   cout << pA.use_count() << "   ,   " << pB.use_count() << endl;
   
   // �˿̣�pA��pB������ʱ����ֻ�Ὣ���ü���-1�� ����ʣ�����ü���Ϊ1���򲻻��ͷ�
   // �Ӷ�����A��B�ڴ�й©

   

   //����4��  shared_ptr������ڴ������new������
   A  *pA = (A *)malloc(sizeof(A)); 
   boost::shared_ptr<A>  p(pA);     //�����϶��������

*/
   getchar();
   return 0;
}
