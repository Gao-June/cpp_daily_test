/*
    final:��ϣ��ĳ���౻�̳У��Լ����������ļ̳��ߣ�����ϣ��ĳ���麯������д��
    override:��ָ�������������麯������д����ģ����֣�������������С�Ĵ���ˣ��������������ͨ���������˰�ȫ��飩��
*/

#include <iostream>

using namespace std;

class Base{ 
    virtual void f( ) final{
        cout << "Base final" << endl;
    }

};

class Derived : public Base{

    // ���� �޷���д��final������ "Base::f" (������ ��������:11)
    // void f( ){
    //     cout << "Derived func( )" << endl;
    // }
};

int main( ){


    return 0;
}