/**
 * new ��ά����
 * ��̫������ô������Ϊ�����ڴ���Ƭ ��p[i]֮�䲻�������ģ�
 * �� maybe Ҳ��Ҫ���ڴ�ص�ԭ�򣿣������ڴ���Ƭ��
*/

#include <iostream>

int main( ){

    // wrong ����һ��һ����
    // int **p = new int[2][3];

    // 3 * 5
    int **p = new int*[3];
    for( int i = 0; i < 3; i ++ ){
        p[i] = new int[5];
    }


    static int Num = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            p[i][j] = Num++;
        }
    }
    std::cout << "test:" << std::endl;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << p[i][j] << "   ";
        }
        std::cout << std::endl;
    }


   // �����ڴ�
    for( int i = 0; i < 3; i ++ ){
        delete[] p[i];
    }

    delete[] p;

    return 0;
}