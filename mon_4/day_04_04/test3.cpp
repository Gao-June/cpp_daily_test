// const ����
/*
    ������ const �ĳ�Ա���������ܶ����ݽ����޸�
    ������ const �� class�����ܷ��ʷ� const ��Ա����
*/

#include <iostream>

using namespace std;

class stu{
private:
    int _a, _b;

public:
    stu( int a = 0, int b = 0 ) : _a(a), _b(b) {}

    void print_a( ){
        cout << "print_a()" << endl;
        _a = 1;
        _b = 2;
    }

    void print_b( ) const{
        cout << "print_b()" << endl;
    }


};

int main( ){
    stu s(1, 2);
    s.print_a();
    s.print_b();

    stu const b(3, 4);
    //b.print_a();    // err
    b.print_b();
    return 0;
}