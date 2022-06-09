/**
 *  
 *  ptime��
    date_time������������������������ڵ���� gregorian�ʹ���ʱ������ posix_time��
        date�����ڴ������ڣ�ptime�������ڶ���һ��ʱ�䡣

    ptime�� date_time�⴦��ʱ��ĺ����࣬
        ��ʹ��64λ��΢�룩��96λ�����룩���������ڲ��洢ʱ�����ݡ�

ͷ�ļ���
    #include<boost/date_time/posix_time/posix_time.hpp>
�����ռ䣺
    using namespace  boost::posix_time;
 */

#include<iostream>
using namespace std;   
  
//�������
#include<boost/date_time/gregorian/gregorian.hpp>
using namespace  boost::gregorian;

//ʱ�����
#include<boost/date_time/posix_time/posix_time.hpp>
using namespace  boost::posix_time;

#pragma  comment(lib, "libboost_date_time-vc100-mt-gd-x32-1_67.lib")

int  main()
{ 
   //ʱ��Ĺ���
   ptime  t1 = time_from_string("2000-01-01 10:00:02");
   cout << t1 << endl;

   ptime  t2 = from_iso_string("20000101T100003");//����ĸT�ָ�����ʱ��
   cout << t2 << endl;
    
   ptime   t3 = second_clock::local_time();//�뾫��
   cout << t3 << endl;

   ptime   t4 = microsec_clock::local_time();//΢�뾫��
   cout << t4 << endl;

   ptime   t5 (min_date_time);//����ֵ
   cout << t5 << endl;

   ptime   t6(max_date_time);//����ֵ
   cout << t6 << endl;

   //�������ڳ���date_duration��Ҳ��ʱ�䳤��

   //1Сʱ10����20��99����
   time_duration  td1(1, 10, 20, 99*1000); //���һ�������ĵ�λ��΢��
   cout << td1 << endl;


   //1Сʱ10����21�� ���Զ���ǰ��λ��
   time_duration  td2(1, 10, 20,1000 * 1000); //���һ�������ĵ�λ��΢��
   cout << td2 << endl;

   //1Сʱ10����20��  1΢�� 
   time_duration  td3=  duration_from_string("1:10:20:000001"); //���һ�������ĵ�λ��΢��
   cout << td3 << endl; 

   //hours
   hours  h(1);
   cout << h.total_seconds() << "��" << h.total_milliseconds() << "����"
   	<< h.total_microseconds() << "΢��" << h.total_nanoseconds() << "����" << endl;

   //����ʱ�䳤�ȹ���
   time_duration td4 = hours(1) + minutes(10) + seconds(20) +microsec(30)+ microseconds(10);
   cout << td4 << endl;


   return 0;
}
