#include <iostream>

using namespace std;

class Entity{
public:
    Entity( ){
        cout << " ���캯��" << endl;
    }

    ~Entity( ){
        cout << "��������" << endl;
    }

};

void func(  ){
    Entity a;
}

int main( ){
    cout << "��ʼ" << endl;
    func();
    cout << "����" << endl;

    return 0;
}