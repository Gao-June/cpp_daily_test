/**
 * date_period��������ʾ���ڷ�Χ�ĸ������ʱ������һ������ҿ����䣬�˵�������date����
 * 
 * ���ں͵�������
 *      ���ڵ�����������++��--�����������������ڣ�
 *      ��Щ������������day_iterator��week_iterator��month_iterator��year_iterator
 *  ע�⣺
 *      ���ǲ������ϱ�׼�������Ķ��壬û��difference_type��pointer��reference���ڲ����Ͷ��壬
 *      ����ʹ��std::advance()����+=��ǰ�����ߺ��ˡ�
 */

#include<iostream>
using namespace std;   
  
#include<boost/date_time/gregorian/gregorian.hpp>
using namespace  boost::gregorian;

#pragma  comment(lib, "libboost_date_time-vc100-mt-gd-x32-1_67.lib")

int  main()
{ 
   date  d1(2000, 1, 1);
   date  d2(2000, 2, 1);

   //����һ�����ڷ�Χ
   date_period  dp1(d1, d2);        //��������ȷ��һ����Χ
   cout << dp1 << endl;             //����ҿ���������2000/2/1
   cout << dp1.length() << endl;    //���������Χ������

   //�����ڷ�Χƽ��
   dp1.shift(date_duration(10)); 
   cout << dp1 << endl;             //����ƶ�10��

   //����������������
   dp1.expand(date_duration(1));    //�������ƶ�һ��
   cout << dp1 << endl; 

   //���ĳ�������Ƿ���������ڷ�Χ����
   cout << dp1.contains(  date(2000,2,20)  ) << endl;


   //���ڵ�����

   date  d3(2000, 1, 1);
   day_iterator  it1(d3,10);        //Ĭ�ϲ�����1
   ++it1;                           //����Ӱ��ԭ���ڣ�ֻ��������
   ++it1;
   cout <<"day_iterator   "<< *it1 << endl;


   week_iterator  it2(d3, 2);
   --it2;                           //��ǰ�ƶ�2��
   cout << "week_iterator   " << *it2 << endl;

   month_iterator  it3(d3);
   --it3;                           //��ǰ�ƶ�1��
   cout << "month_iterator   " << *it3 << endl;
    
   year_iterator  it4(d3, 10);
   ++it4;                           //����ƶ�10��
   cout << "month_iterator   " << *it4 << endl;

   return 0;
}
