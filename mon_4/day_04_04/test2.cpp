// 操作符重载

#include <iostream>

using namespace std;

class Nums{
private:
    int _a_num, _b_num;

public:
    Nums( int a = 0, int b = 0 ) : _a_num(a), _b_num(b){}
    
    // += 重载
    inline Nums& operator+= ( const Nums &a);

    // + 重载
    inline Nums operator+( const Nums &a);

    void Print( ){
        cout << _a_num << "\t" << _b_num << endl;
    }
};

inline Nums& Nums::operator+= (const Nums &a){
    this->_a_num += a._a_num;
    this->_b_num += a._b_num;
    return *this;
}

inline Nums Nums::operator+ ( const Nums &a){
    Nums temp;
    temp._a_num = a._a_num + this->_a_num;
    temp._b_num = a._b_num + this->_b_num;

    cout << " operator+ :  " << temp._a_num << '\t' << temp._b_num << endl;

    return temp;
}

int main( ){
    Nums a1(1,2);
    Nums a2(3,4);
    a1.Print();
    a2.Print();

   // += 
    a1 +=a2;
    a1.Print();

    // +
    Nums b1(1, 2);
    Nums b2(3, 4);
    Nums b3 = b1 + b2;
    b1.Print();
    b2.Print();
    b3.Print();

    return 0;
}