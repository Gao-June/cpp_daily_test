#include <iostream>

using namespace std;

class Entity{
public:
    Entity( ){
        cout << " 构造函数" << endl;
    }

    ~Entity( ){
        cout << "析构函数" << endl;
    }

};

void func(  ){
    Entity a;
}

int main( ){
    cout << "开始" << endl;
    func();
    cout << "结束" << endl;

    return 0;
}