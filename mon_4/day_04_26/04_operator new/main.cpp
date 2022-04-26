#include <iostream>
#include <string>


void* operator new( size_t Size ){
    std::cout << "Allocate String" << Size << "  bytes\n";
    return malloc( Size );
}


int main( ){
    std::string *Name1 =  new std::string("abcdefghijklmnopqrstuvwxyz") ;
    std::cout << Name1 << std::endl;

    return 0;
}
