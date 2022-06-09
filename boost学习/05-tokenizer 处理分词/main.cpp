/**
tokenizer库
    是一个专门用于分词 （token）的字符串处理库可以方便的把一个字符串分解成若干个单词，
    它比 string_algo的spilt更强大
需要包含头文件#include<boost/tokenizer.hpp>。
 */

#include<iostream>
using namespace std;   

#include<boost/typeof/typeof.hpp>
#include<boost/tokenizer.hpp>
using namespace  boost;

int main()
{ 
   cout << "--------char_delimiters_separator分词--------" << endl;
   //string str = "My Name  is  Mr  Huang!";
   string str = "My!Name,is.Mr?Huang";
   tokenizer<>   tok(str);//使用默认参数，采用空格或者标点符号分词 
   for (BOOST_AUTO(it, tok.begin()); it != tok.end(); ++it)
   {
   	cout << *it << endl;
   }

   //演示char_separator分词对象
   cout << "--------char_separator分词--------" << endl;
   string  str2 = "My<Name>is<Mr<<Huang!";
   char_separator<char>  sep(">"/*分隔符，不保留*/ , "<"/*分隔符，保留*/,
   	keep_empty_tokens/*是否保留“”的分词结果*/);
   tokenizer<char_separator<char>> tok2(str2, sep);
   for (BOOST_AUTO(it, tok2.begin()); it != tok2.end(); ++it)
   {
   	cout << *it << endl;
   }

   //演示escaped_list_separator
   cout << "--------escaped_list_separator分词--------" << endl;
   escaped_list_separator<char>  sep3;//默认以，号分词
   string  str3 = "My,Name,Is,Mr,\\\"Huang!\\\"";
   tokenizer<escaped_list_separator<char> >  tok3(str3, sep3);
   for (BOOST_AUTO(it, tok3.begin()); it != tok3.end(); ++it)
   {
   	cout << *it << endl;
   }


   //offset_separator分词
   cout << "--------offset_separator分词--------" << endl;
   
   //int  arr[3] = {2,3,4};
   //string  str4 = "22333444455555";
   //offset_separator   sep4(arr, arr + 3, false/*偏移量用完后继续分词*/);
   
   int  arr[3] = { 2,3,10 };
   string  str4 = "223334444";
   offset_separator   sep4(arr, arr + 3, false, false/*是否返回分词不足的部分*/);

   tokenizer<offset_separator> tok4(str4, sep4);
   for (BOOST_AUTO(it, tok4.begin()); it != tok4.end(); ++it)
   {
   	cout << *it << endl;
   }
   
   getchar();
   return 0;
}
