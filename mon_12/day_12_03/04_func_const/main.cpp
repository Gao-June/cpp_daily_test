/*
    func const
*/

#include <iostream>

using namespace std;

class complex{

public:
    // 构造函数
    complex ( double r = 0, double i = 0 ) : real(r), image(i){}

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
     complex c(8.123, 24.3252);
    
    // 调用函数获取数据
    cout << "real: " << c.get_real() << endl;
    cout << "image: " << c.get_image() << endl;

    return 0;
}