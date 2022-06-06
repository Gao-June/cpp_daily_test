/**
 * weak_ptr
 *      weak_ptr��Ƶ�Ŀ����Ϊ����Э�� shared_ptr������
 *      ��ֻ���Դ�һ�� shared_ptr����һ�� weak_ptr�����죬
 *      ���Ĺ���������������ü��������ӻ���٣�
 * ʹ����Ҫ����ͷ�ļ���
 *      #include<boost/weak_ptr.hpp>
 * ��ע��
 *      C++11��׼�е� std::weak_ptr �� boost::weak_ptr �������ơ�
 *      shared_ptr ����������������ü����Ӽ�1���� weak_ptr �����������ü����ĸı䡣
 */

#include<iostream>
#include<boost/weak_ptr.hpp>
#include<boost/shared_ptr.hpp>

using namespace  boost;
using namespace std;

class  A{
public:
   A( ){
   	cout << "����A�����" << endl;
   }

   ~A( ){
   	cout << "����A�����" << endl;
   } 

   int m_a; 
};

int main()
{ 
   boost::shared_ptr<A>  p1( new  A);       // ���ü���+1
   cout << p1.unique() << " , " << p1.use_count() << endl;

// weak_ptr �� shared_ptr ��Э���ߣ�������һ����ǣ���Ҫ���ڹ۲�
   boost::weak_ptr<A>  p2(p1);//���ı����ü���
   cout << p1.unique() << " , " << p1.use_count() << endl;

   /*���ڹ۲�shared_ptrָ����ڴ��Ƿ��ͷ� */
   cout << p2.expired() << " , " << p2.use_count() << endl;

// weak_ptr ����������ڴ�
   // p2->m_a;//�����
   // *p2.m_a = 100;//�����

   boost::shared_ptr<A>  p3(p1);// ���ü���+1
   boost::shared_ptr<A>  p4(p3);// ���ü���+1

   //��weak_ptr���۲�һ��
   cout << p2.expired()<< " , " << p2.use_count() << endl;

   p1.reset();	 //�ͷŹ���Ȩ �� ���ü���-1
   p3.reset();	 //�ͷŹ���Ȩ �� ���ü���-1
   p4.reset();	 //�ͷŹ���Ȩ �� ���ü���-1���˿��ڴ��ͷ�

    /* ����1��ʾ�ڴ��Ѿ��ͷ� */
   cout << p2.expired() << " , " << p2.use_count() << endl;

   return 0;
}

