/**
tokenizer��
    ��һ��ר�����ڷִ� ��token�����ַ����������Է���İ�һ���ַ����ֽ�����ɸ����ʣ�
    ���� string_algo��spilt��ǿ��
��Ҫ����ͷ�ļ�#include<boost/tokenizer.hpp>��
 */

#include<iostream>
using namespace std;   

#include<boost/typeof/typeof.hpp>
#include<boost/tokenizer.hpp>
using namespace  boost;

int main()
{ 
   cout << "--------char_delimiters_separator�ִ�--------" << endl;
   //string str = "My Name  is  Mr  Huang!";
   string str = "My!Name,is.Mr?Huang";
   tokenizer<>   tok(str);//ʹ��Ĭ�ϲ��������ÿո���߱����ŷִ� 
   for (BOOST_AUTO(it, tok.begin()); it != tok.end(); ++it)
   {
   	cout << *it << endl;
   }

   //��ʾchar_separator�ִʶ���
   cout << "--------char_separator�ִ�--------" << endl;
   string  str2 = "My<Name>is<Mr<<Huang!";
   char_separator<char>  sep(">"/*�ָ�����������*/ , "<"/*�ָ���������*/,
   	keep_empty_tokens/*�Ƿ��������ķִʽ��*/);
   tokenizer<char_separator<char>> tok2(str2, sep);
   for (BOOST_AUTO(it, tok2.begin()); it != tok2.end(); ++it)
   {
   	cout << *it << endl;
   }

   //��ʾescaped_list_separator
   cout << "--------escaped_list_separator�ִ�--------" << endl;
   escaped_list_separator<char>  sep3;//Ĭ���ԣ��ŷִ�
   string  str3 = "My,Name,Is,Mr,\\\"Huang!\\\"";
   tokenizer<escaped_list_separator<char> >  tok3(str3, sep3);
   for (BOOST_AUTO(it, tok3.begin()); it != tok3.end(); ++it)
   {
   	cout << *it << endl;
   }


   //offset_separator�ִ�
   cout << "--------offset_separator�ִ�--------" << endl;
   
   //int  arr[3] = {2,3,4};
   //string  str4 = "22333444455555";
   //offset_separator   sep4(arr, arr + 3, false/*ƫ�������������ִ�*/);
   
   int  arr[3] = { 2,3,10 };
   string  str4 = "223334444";
   offset_separator   sep4(arr, arr + 3, false, false/*�Ƿ񷵻طִʲ���Ĳ���*/);

   tokenizer<offset_separator> tok4(str4, sep4);
   for (BOOST_AUTO(it, tok4.begin()); it != tok4.end(); ++it)
   {
   	cout << *it << endl;
   }
   
   getchar();
   return 0;
}
