#include <iostream>

int main( ){
    char name1[6] = {'a', 'b', 'c', 'd', 'e', '\0'};    
    std::cout << name1 << std::endl;     //abcdef

    // char name2[6] = {'a', 'b', 'c', 'd', 'e', 'f'};    

    // std::cout << name2 << std::endl;     //abcdef?v »áÂÒ


    char name3[] = "abcderfg";      // abcderfg
    std::cout << name3 << std::endl;


    return 0;
}