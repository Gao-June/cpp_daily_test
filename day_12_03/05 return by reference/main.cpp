/*
    func const
*/

#include <iostream>

using namespace std;

class complex{
private:
    double real, image;

public:
    // 构造函数
    complex ( double r = 0, double i = 0 ) : real(r), image(i){}

    double get_real( ) const{
        return real;
    }
    double get_image( ) const{
        return image;
    }

    // inline complex & _doapl  ( complex *ths, const complex &r ){
    //     ths->real  += r.real;
    //     ths->image +=r.image;

    //     return *ths;
    // }

    complex& operator += ( const complex &r ){
        // 这里的 this指针是 complex * 型的
        // 但是返回值要是 complex，所以 return *this

        this->real  += r.real;
        this->image +=r.image;

        return *this;
    }
};

int main(){
    complex c1(2,1);
    complex c2(6);

    c2 += c1;       // c2 real:7, image: 1
    
    // 调用函数获取数据
    cout << "real: " << c2.get_real() << endl;
    cout << "image: " << c2.get_image() << endl;

    return 0;
}