#include <iostream>
#include "complex.h"

using namespace std;

void prinT( complex &c ){
    cout << " ( " <<  c.get_real_complex() << " , " 
    << c.get_image_complex() << " )" << endl;
}

int main(){
    complex c1(1, 2);
    complex c2(3, 4);

    // 打印元素 ok
    prinT(c1);

    // 检查重载操作符
    c1 *= c2;
    prinT(c1);


    return 0;
}