/**
 * �÷º�����lambda��set�����Զ�������
 * 
 * �º�����
 *  1 - �º������Ǻ��������Ǹ��ࣻ
 *  2 - �º���������()�������ʹ�����Ķ���������������ӵ���(�������ʽ�������ڵ��ú���)��
 * 
 * ʵ�֣�
 *  ���Ȱ��ս̲���ķº���д��Ȼ���滻�� lambda���ԡ�
 *  �е��Ѷȣ����ܵİٶȹ���
 */

#include <iostream>
#include <string>
#include <set>

class Student{
public:
    Student( std::string name, int age ) : _name(name), _age(age){}

public:
    std::string _name;
    int _age;
};

// �º���
class StuFunctor{
public:
    // p.s. ����error: static assertion failed: comparison object must be invocable as const
    // ���ú���Ϊ const����
    bool operator() (const Student& l, const Student& r) const{
        return (l._age > r._age);   // ���� �ɴ�С
    }
};


int main( ){
    //std::set< Student, StuFunctor > set1;      // Ҳд�Ϸº��������ݷº�����������

    // ������������º���Ϊ lambda ����
    // �����Լ���ˮƽ��ʱҲ��֪������ôŪ��
    // ���������ֻ���
    auto cmp = []( const Student& l, const Student& r ) {return (l._age >= r._age);};
    // ���� set ����ʽ��Ҫָ�� lambda���ͣ� �������Ǳ���ʹ�� decltype������Ϊһ��lambda����������͡�
    // ע�⣬��Ҳ����� lambda������� set1�Ĺ��캯��������set1����ñ����������׼���default���캯����
    // ������C++���Թ���lambdaû�� default���캯����
    std::set< Student, decltype(cmp)> set1(cmp);

    set1.insert( Student("����", 32) );
    set1.insert( Student("����", 44) );
    set1.insert( Student("����", 21) );
    set1.insert( Student("�԰�", 65) );

    for( auto it = set1.begin(); it != set1.end(); it ++ ){
        std::cout << (*it)._name << "  " << (*it)._age << std::endl;
    }

    return 0;
}