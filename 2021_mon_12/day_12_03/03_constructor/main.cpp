/*
    构造函数 可以有多种写法， 可以重载。
    但是注意，重载的前提是参数不一样
*/

#include <iostream>

using namespace std;

class complex_number{

public:
    // 构造函数
    //      推荐
    complex_number ( double r = 0, double i = 0 ) : real(r), image(i){}

    // 构造函数重载失败，等同于行-15
    //complex_number ( ) : real(0), image(0) {}

    //      不推荐
    // complex_number ( double r = 0, double i = 0 ){
    //     real = r;
    //     image = i;
    // }

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

    return 0;
}