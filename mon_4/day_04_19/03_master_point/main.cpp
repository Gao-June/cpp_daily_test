#include <iostream>
#include <memory>
#include <string>

int main()
{
// shared_ptr
    int a = 10;
    std::shared_ptr<int> Ptr1 = std::make_shared<int>(a);
    std::cout << *Ptr1 << std::endl;

    std::string Str1("hello world");
    auto Ptr2 =std::make_shared<std::string>(Str1);
    std::cout << *Ptr2 << std::endl;

// unique_ptr
    int b = 20;
    std::unique_ptr<int> Ptr3 = std::make_unique<int>(b);
    std::cout << *Ptr3 << std::endl;

    int c = 30;
    
// ���Զ�� unique_ptrָ��ͬһ��Ŀ��
// ���ǲ���ͬһ�� unique_ptr ָ��ͬĿ��
    // auto Ptr5 = Ptr3;    //wrong �޷���ֵ
    std::unique_ptr<int> Ptr6 = std::make_unique<int>(c);
    std::cout << *Ptr6 << std::endl;
    // aPtr6 = Ptr3;    //wrong �޷���ֵ

    std::string Str2("yes sir!");
    auto Ptr4 =std::make_unique<std::string>(Str2);
    std::cout << *Ptr4<< std::endl;

    return 0;
}