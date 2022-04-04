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


    // 友元函数的定义法更直观（因为有两个参数）
    friend Nums operator+(const Nums &c1, const Nums &c2);
    
    void Print( ){
        cout << _a_num << "\t" << _b_num << endl;
    }

    int get_a( ) const{
        return this->_a_num;
    }

    int get_b( ) const{
        return this->_b_num;
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

Nums operator+(const Nums &c1, const Nums &c2){
    Nums c3;
    c3._a_num = c1._a_num + c2._a_num;
    c3._b_num = c1._b_num + c2._b_num;

    return c3;
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

    // + 友元函数版
    Nums c1(10, 20);
    Nums c2(30, 40);
    Nums c3 = c1 + c2;
    c1.Print();
    c2.Print();
    c3.Print();

    return 0;
}