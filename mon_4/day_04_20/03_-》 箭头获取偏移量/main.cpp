#include <iostream>
#include <string>

struct Vector3
{
    float x, y, z;
};


int main()
{
    /** 先构造一个 vector3类型的空对象指针，
     * 然后用该指针去调用对象的成员变量,
     * 最后用 long long& 得到变量的相对地址
     *  【注】如果使用 int 会丢失精度，编译出错
     *  -> 优先级 大于 &
    */
    long long offset_x =  (long long )&( (Vector3*)nullptr)->x;
    std::cout << offset_x << std::endl;

    long long offset_y =  (long long )&( (Vector3*)nullptr)->y;
    std::cout << offset_y << std::endl;

    long long offset_z =  (long long )&( (Vector3*)nullptr)->z;
    std::cout << offset_z << std::endl;

    return 0;
}