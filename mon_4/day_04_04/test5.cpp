// ÷ÿ‘ÿ < °¢∫Ø ˝ƒ£∞Â

#include <iostream>

using namespace std;

template <typename T>
bool max_num( const T a, const T b ){
    return  (a < b) ? true : false;
}

class stu{
private:
    int _a, _b;

public:
    stu( int a = 1, int b = 2 ) : _a(a), _b(b) {}

    // operator <

    friend bool operator< ( const stu& a, const stu& b ){
        return ( a._a < b._a );
    }
};

int main( ){
    stu a1(1, 2);
    stu a2(2, 1);

    if ( max_num(a1, a2) ){
        cout << " small " << endl;
    }
    else{
        cout << " big " <<  endl;
    }

    return 0;
}