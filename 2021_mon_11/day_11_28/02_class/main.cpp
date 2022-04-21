/*
    默认构造函数、 this->
*/

#include <iostream>

using namespace std;


class A{
public:
    int Sum( );
    A( int a = 100, int b = 200 ):a_val(a) , b_val(b){
    }
private:
    int a_val, b_val;
};

int A::Sum( ){
    return this->a_val + this->b_val;
}

int main(){
    A temp(1,4);
    cout << temp.Sum() << endl;

    return 0;
}