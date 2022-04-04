// copy construct

#include <iostream>

using namespace std;

class stu{
private:
    int _a, _b;

public:
    stu( int a, int b ) : _a(a), _b(b) {}

    // copy construct
    stu &operator() ( stu &s );

    void print( ){
        cout << _a << '\t' << _b << endl;
    }

};

stu& stu::operator() ( stu &s ){
    this->_a = s._a;
    this->_b = s._b;

    return *this;
}

int main( ){
    stu a(1,2);
    stu b(a);
    a.print();
    b.print();

    return 0;
}