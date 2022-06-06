/**
 * date_period类用来表示日期范围的概念，它是时间轴上一个左闭右开区间，端点是两个date对象。
 * 
 * 日期和迭代器：
 *      日期迭代器可以用++、--操作符连续访问日期，
 *      这些迭代器包括：day_iterator、week_iterator、month_iterator和year_iterator
 *  注意：
 *      它们并不符合标准迭代器的定义，没有difference_type、pointer、reference等内部类型定义，
 *      不能使用std::advance()或者+=来前进或者后退。
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

   //构造一个日期范围
   date_period  dp1(d1, d2);        //两个日期确定一个范围
   cout << dp1 << endl;             //左闭右开，不包含2000/2/1
   cout << dp1.length() << endl;    //返回这个范围的天数

   //把日期范围平移
   dp1.shift(date_duration(10)); 
   cout << dp1 << endl;             //向后移动10天

   //把日期向两边延伸
   dp1.expand(date_duration(1));    //向两边移动一天
   cout << dp1 << endl; 

   //检测某个日期是否在这个日期范围里面
   cout << dp1.contains(  date(2000,2,20)  ) << endl;


   //日期迭代器

   date  d3(2000, 1, 1);
   day_iterator  it1(d3,10);        //默认步长是1
   ++it1;                           //不会影响原日期，只是输出结果
   ++it1;
   cout <<"day_iterator   "<< *it1 << endl;


   week_iterator  it2(d3, 2);
   --it2;                           //向前移动2周
   cout << "week_iterator   " << *it2 << endl;

   month_iterator  it3(d3);
   --it3;                           //向前移动1月
   cout << "month_iterator   " << *it3 << endl;
    
   year_iterator  it4(d3, 10);
   ++it4;                           //向后移动10年
   cout << "month_iterator   " << *it4 << endl;

   return 0;
}
