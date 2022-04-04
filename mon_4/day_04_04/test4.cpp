// copy construct

#include <iostream>

using namespace std;

class stu{
private:
    int _a, _b;

public:
    stu( int a, int b ) : _a(a), _b(b) {}

    // copy constructor 第一种
    stu &operator() ( stu &s ){
        this->_a = s._a;
        this->_b = s._b;
        return *this;
    }

    // copy constructor 第二种
    stu( const stu &s ) : _a( s._a ), _b( s._b ) {}


    void print( ){
        cout << _a << '\t' << _b << endl;
    }

};


int main( ){
    stu a(1,2);
    stu b(a);
    a.print();
    b.print();

    return 0;
}