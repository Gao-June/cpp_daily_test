#ifndef _COMPLEX_
#define _COMPLEX_

#include <iostream>
using namespace std;

class complex;


class complex{
public:
    // 默认构造函数
    complex ( double r = 0, double i = 0 ) : re( r ), im( i ) { }

    // 重载操作符
    complex& operator += ( const complex& );
    complex operator -= ( const complex& );
    complex& operator *= ( const complex& );

    // 输出成员变量：
    double get_real_complex( ) const {
        return re;
    }
    double get_image_complex( ) const {
        return im;
    }

private:
    double re, im;
};


inline complex&  complex::operator += ( const complex& r){
    this->re += r.re;
    this->im += r.im;

    return *this;
}

inline complex complex::operator -= ( const complex& r ){
    this->re -= r.re;
    this->im -= r.im;

    return *this;
}

inline complex& complex::operator *= ( const complex& r ){
    double real_complex = this->re * r.re - this->im * r.im;
    double im_complex = this->re * r.im + this->im * r.re;

    this->re = real_complex;
    this->im = im_complex;

    return *this;
}

#endif

