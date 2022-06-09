/**
    �������ݣ� data ��
    p.s. ���������˸�С����


 * date_time���ṩ��ʱ��������صļ��㡢��ʽ����ת�����������ȹ���
 *  ΪC++������ʱ�����ṩ�˼��������
 * 
 * ͷ�ļ���
    #include<boost/date_time/gregorian/gregorian.hpp>
 * �����ռ䣺
    using namespace  boost::gregorian;
 */

#include<iostream>
#include<boost/date_time/gregorian/gregorian.hpp>

using namespace  boost::gregorian;
using namespace std;  

int  main()
{ 
   // ��������
   date   d1(2000, 1, 1);
   date   d2 = from_string("2010-02-02");
   date   d3 = from_string("2010/03/03");
   date   d4 = from_undelimited_string("20100404");//�޽綨���ַ���

   date  d5(min_date_time);//����ʱ��ֵ1400-01-01
   date  d6(max_date_time);//����ʱ��ֵ9999-12-31

   //�������

   // month() ��ת int �Ļ�������� Jan
   cout << d1.year() << "��" <<(int) d1.month() << "��" << d1.day() << endl;

   cout << to_simple_string(d2) << endl;//2010-Feb-02
   cout << to_iso_string(d3) << endl;//20100303
   cout << to_iso_extended_string(d4) << endl;//2010-03-03
   cout << to_iso_string(d5) << endl;
   cout << to_iso_string(d6) << endl;

   //��ȡ���������
   date  today = day_clock::local_day();

   cout << "��"<< today.year() << endl;
   cout << "��"<< today.month() << endl;
   cout << "��"<< today.day() << endl;
   cout <<"����"<< today.day_of_week() << endl; 
   cout << "һ���еĵڼ���" << today.week_number() << endl;
   cout << "һ���еĵڶ�����" << today.day_of_year() << endl;
   cout << "����µĽ�������" << today.end_of_month() << endl;

// ����������һ��С����
    cout << "���Կ�ʼ" << endl;
    date   d_my = from_string("2022-01-18");
    cout << "��"<< d_my.year() << endl;
    cout << "��"<< d_my.month() << endl;
    cout << "��"<< d_my.day() << endl;
    cout <<"����"<< d_my.day_of_week() << endl; 
    cout << "һ���еĵڼ���" << d_my.week_number() << endl;
    cout << "һ���еĵڶ�����" << d_my.day_of_year() << endl;
    cout << "����µĽ�������" << d_my.end_of_month() << endl;
    cout << "���Խ���" << endl;


   //ʱ�䳤��(��С��λ�� ��)
   days  day1(10);
   days  day2(-5);
   date_duration  du1  = day1 + day2;
   cout <<"10��-5��"<< du1.days() << endl;

   weeks  w1(1);
   cout << "1�ܵ�����" << w1.days() << endl;
   date_duration  du2 = w1 + day1;
   cout << "1��+ 10��" << du2.days() << endl;

   months   mon1(1);//һ�����޷�֪���Ƕ����� �������޷�������
   cout << "1����" << mon1.number_of_months() << endl;

   years  year1(1);//һ���޷�֪���Ƕ����죬�����޷�������
   cout << "1��" << year1.number_of_years()<< endl;

   //���֪��һ����ٸ���
   months mon2= year1 + months(0);
   cout << "1����ٸ���" << mon2.number_of_months() << endl;

   //����+  ���ڳ��� = ������ ����ʵ��
   date   d10(2018, 1, 31);

   cout << "������ǰ��10���Ǽ��¼���:" ;
   cout <<  to_iso_extended_string(  d10 + days(-10) ) << endl;

   cout << "���������2���Ǽ��¼���:";
   cout << to_iso_extended_string(d10 + weeks(2)) << endl;

   cout << "����������һ�����Ǽ��¼���:";
   cout << to_iso_extended_string(d10 + months(1)) << endl;

   cout << "����������һ�����Ǽ��¼���:";
   cout << to_iso_extended_string(d10 + years(1)) << endl;

   getchar();
   return 0;
}
