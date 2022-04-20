#include <iostream>
#include <string>

struct Vector3
{
    float x, y, z;
};


int main()
{
    /** �ȹ���һ�� vector3���͵Ŀն���ָ�룬
     * Ȼ���ø�ָ��ȥ���ö���ĳ�Ա����,
     * ����� long long& �õ���������Ե�ַ
     *  ��ע�����ʹ�� int �ᶪʧ���ȣ��������
     *  -> ���ȼ� ���� &
    */
    long long offset_x =  (long long )&( (Vector3*)nullptr)->x;
    std::cout << offset_x << std::endl;

    long long offset_y =  (long long )&( (Vector3*)nullptr)->y;
    std::cout << offset_y << std::endl;

    long long offset_z =  (long long )&( (Vector3*)nullptr)->z;
    std::cout << offset_z << std::endl;

    return 0;
}