#include<iostream>

using namespace std;

class Entity{
public:
    Entity( int a = 0, int b = 0 ) : _a(a), _b(b) {
        cout << "1" << endl;
    }
    Entity(  ) : _a( 0 ), _b( 0 ) {
        cout << "2" << endl;
    }

private:
    int _a, _b;
};

int main()
{
    Entity e1;
    Entity e2();

    return 0;
}