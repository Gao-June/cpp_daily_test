#ifndef _COMPLEX_
#define _COMPLEX_

#include <iostream>
using namespace std;

class complex;


class complex{
public:
    // 榛樿鏋勯�犲嚱鏁?
    complex ( double r = 0, double i = 0 ) : re( r ), im( i ) { }

    // 閲嶈浇鎿嶄綔绗?
    // 前面加不加 & 都可以
    complex& operator += ( const complex& );
    complex operator -= ( const complex& );
    complex operator *= ( const complex& );

    // 杈撳嚭鎴愬憳鍙橀噺锛? 
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

inline complex complex::operator *= ( const complex& r ){
    double real_complex = this->re * r.re - this->im * r.im;
    double im_complex = this->re * r.im + this->im * r.re;

    this->re = real_complex;
    this->im = im_complex;

    return *this;
}

#endif

