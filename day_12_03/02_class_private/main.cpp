/*
    cpp 的 class 尽量将数据设为 private，不让外界看到；
    如果需要访问的话，可以再写函数 去访问数据。
*/

#include <iostream>

using namespace std;

class complex_number{

public:
    // 构造函数
    complex_number ( double r = 0, double i = 0 ) : real(r), image(i){}

    double get_real( ) const{
        return real;
    }
    double get_image( ) const{
        return image;
    }

private:
    double real, image;
};

int main(){
    complex_number c;
    
    // 调用函数获取数据
    cout << "real: " << c.get_real() << endl;
    cout << "image: " << c.get_image() << endl;

    // 直接获取数据
    // 报错： 'double complex_number::real' is private within this context
    // cout << "real: " << c.real << endl;
    // cout << "image: " << c.image << endl;

    return 0;
}