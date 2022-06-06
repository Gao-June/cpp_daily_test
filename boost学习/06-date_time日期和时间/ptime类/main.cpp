/**
 *  
 *  ptime类
    date_time库它包含两个组件，处理日期的组件 gregorian和处理时间的组件 posix_time。
        date类用于创建日期，ptime类则用于定义一个时间。

    ptime是 date_time库处理时间的核心类，
        它使用64位（微秒）或96位（纳秒）的整数在内部存储时间数据。

头文件：
    #include<boost/date_time/posix_time/posix_time.hpp>
命名空间：
    using namespace  boost::posix_time;
 */

#include<iostream>
using namespace std;   
  
//日期组件
#include<boost/date_time/gregorian/gregorian.hpp>
using namespace  boost::gregorian;

//时间组件
#include<boost/date_time/posix_time/posix_time.hpp>
using namespace  boost::posix_time;

#pragma  comment(lib, "libboost_date_time-vc100-mt-gd-x32-1_67.lib")

int  main()
{ 
   //时间的构造
   ptime  t1 = time_from_string("2000-01-01 10:00:02");
   cout << t1 << endl;

   ptime  t2 = from_iso_string("20000101T100003");//用字母T分割日期时间
   cout << t2 << endl;
    
   ptime   t3 = second_clock::local_time();//秒精度
   cout << t3 << endl;

   ptime   t4 = microsec_clock::local_time();//微秒精度
   cout << t4 << endl;

   ptime   t5 (min_date_time);//特殊值
   cout << t5 << endl;

   ptime   t6(max_date_time);//特殊值
   cout << t6 << endl;

   //类似日期长度date_duration，也有时间长度

   //1小时10分钟20秒99毫秒
   time_duration  td1(1, 10, 20, 99*1000); //最后一个参数的单位是微秒
   cout << td1 << endl;


   //1小时10分钟21秒 （自动往前进位）
   time_duration  td2(1, 10, 20,1000 * 1000); //最后一个参数的单位是微秒
   cout << td2 << endl;

   //1小时10分钟20秒  1微秒 
   time_duration  td3=  duration_from_string("1:10:20:000001"); //最后一个参数的单位是微秒
   cout << td3 << endl; 

   //hours
   hours  h(1);
   cout << h.total_seconds() << "秒" << h.total_milliseconds() << "毫秒"
   	<< h.total_microseconds() << "微秒" << h.total_nanoseconds() << "纳秒" << endl;

   //利用时间长度构造
   time_duration td4 = hours(1) + minutes(10) + seconds(20) +microsec(30)+ microseconds(10);
   cout << td4 << endl;


   return 0;
}
