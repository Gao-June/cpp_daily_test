/**
 * new 二维数组
 * 不太建议这么做，因为会有内存碎片 （p[i]之间不是连续的）
 * 这 maybe 也是要用内存池的原因？（避免内存碎片）
*/

#include <iostream>

int main( ){

    // wrong 必须一步一步来
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


   // 回收内存
    for( int i = 0; i < 3; i ++ ){
        delete[] p[i];
    }

    delete[] p;

    return 0;
}