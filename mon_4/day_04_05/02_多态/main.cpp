// ��ϰһ�¶�̬
/*
    дһ����̬���û���ָ��ָ��������;

    1- ������ָ�������������� ����ʱ������ֱ�ӵ��ã�
    2-  ����������Լ��� ����ʱ����Ҫ���� ��������� ::
    3- ע�⣬���������õĺ���ֻ���ǣ��Լ��ڻ�����ġ���������д���麯����������Ĵ��麯�������������ͨ�����޷����á�
*/

#include <iostream>
#include <string>

using namespace std;

class Animal{
private:
    string _name;

public:
    Animal( string name = "" ) : _name(name) {}

    void speak( ){
        cout << "???" << endl;
    }
    void get_name( ){
        cout << "..." << endl;
    }

    virtual void speak_virtual( ){
        cout << "������麯��" << endl;
    }
};

class Dog : public Animal{
private:
    string _d_name;

public:
    Dog( string name = "" ) : _d_name( name ) {}

    void speak( ){
        cout << "wang wang wang" << endl;
    }

    void get_name( ){
        cout << _d_name << endl;
    }

    virtual void speak_virtual( ){
        cout << "dog ��������麯��" << endl;
    }
};

class Cat : public Animal{
private:
    string _c_name;

public:
    Cat( string name = "" ) : _c_name( name ) {}

    void speak( ){
        cout << "miao miao miao" << endl;
    }

    void get_name( ){
        cout << _c_name << endl;
    }

    virtual void speak_virtual( ){
        cout << "cat ��������麯��" << endl;
    }
};

int main( ){
    cout << "No.1" << endl;
    Dog d("dddd");
    d.speak();              // ������ ����ĺ��� speak()
    d.get_name();           // ������ ����ĺ��� get_name()
    d.Animal::speak();      // ���� ����ĺ��� speak()
    d.Animal::get_name();   // ���� ����ĺ��� get_name()

    cout << "No.2" << endl;
    Cat c("cccc");
    c.speak();          // ������ ����ĺ��� speak()
    c.get_name();           // ������ ����ĺ��� get_name()
    c.Animal::speak();  // ���� ����ĺ��� speak()
    c.Animal::get_name();  // ���� ����ĺ��� get_name()


// ��ʼ���� ��̬
// ����ָ��ָ��������
// ���Կ��� ������ָ�� ָ�� ����������ʱ�� ��Ҫ����������ĺ���ֻ��ͨ�� �麯�����У� 
//    ��ȻĬ�����е��� ���� �ĺ��������磺 speak()��get_name()
    cout << "No.3" << endl;
    Animal *a = &d;         // ָ���� class Dog
    a->speak();             // ���е��� ���� class �ĺ��� speak()
    a->get_name();          // ���е��� ���� class �ĺ��� get_name()
    a->Animal::speak();     // ���е��� ���� class �ĺ��� speak()   ��ͬ����� speak()�������
    a->speak_virtual();     // ���е��� ������ �ĺ��� speak_virtual()
    a->Animal::speak_virtual();     // ���е��� ���� �ĺ��� speak_virtual()

    return 0;
}
