/**
 * make_shared
 * �÷���ʵ�� shared_ptr��ֻ࣬�������� new��Ҳ��������������鷳
 * 
 * ��Ŀ�ġ����� new �������鷳
 *      shared_ptr��������ʽ�� delete���ã�
 *      �ܴ�̶��ϱ����˳���Ա���� delete�����µ��ڴ�й©��
 *      �� shared_ptr�Ĺ�����Ȼ��Ҫ��ew���⵼���˴����е�ĳ�ֲ��Գ��ԣ�
 *      ��Ӧ��ʹ�ù���ģʽ�������
 * make_shared()
 *      Boost���ṩ��һ�����ɹ������� make shared<T>()����������ʽ��new���ã�
 *  �������£�
 *          template<class T,class... Args>
            shared_ptr<T> make_shared(Args && ... args);
        make_shared()����ģ��ʹ�ñ䳤����ģ�壬
        ���ɽ���10������Ȼ������Ǵ��ݸ�T�Ĺ��캯����
        ����һ�� shared_ptr<T>�Ķ��󲢷��ء�
        make_shared()����Ҫ��ֱ�Ӵ��� shared_ptr����ķ�ʽ����Ч��
        ��Ϊ���Ȳ�������һ�΃ȴ档
    ͷ�ļ���
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
        cout << "����A�����" << endl;
   }

   ~A( )  
   {
   	    cout << "����A�����" << endl;
   } 

   int a; 
   float b; 
   char c; 
   string d;
};

int main()
{ 
//ԭʼ�ķ�ʽ���� shared_ptr����Ҫ new������һ�ֲ��Գ���
   boost::shared_ptr<A>  p1(new A(100, 1.234f, 'C', "hello"));
   cout << p1->a << ", " << p1->b << ", " << p1->c<< ", " << p1->d << endl;

//�Ƽ�ʹ�ù������������� new ,����Ч
   boost::shared_ptr<A>  p2  =  boost::make_shared<A>(100, 1.234f, 'C', "hello");
   cout << p2->a << ", " << p2->b << ", " << p2->c << ", " << p2->d << endl;

   getchar();
   return 0;
}
