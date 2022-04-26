/**
 * ̽����ֵ���� �� ��ֵ����
 * ��ֵ ֧�ִ洢���е�ַ��
 * ��ֵ ����ʱֵ��û�е�ַ������ֵ�����е�ַ������ֵ����
 * 
 *  �������ֵ����ô�Ͳ��õ������Ƿ񻹻��ţ��Ƿ��������Ƿ񿽱���
 *  ��Ʒ�ǾͿ��Լ򵥵�͵������Դ�������ض����󣬻��������ط�ʹ������
 *  ��Ϊ����֪��������ʱ�ģ�������ںܳ�ʱ�䡣
*/


#include <iostream>
#include <string>

void Print( const std::string &Name ) {
    std::cout << "[lvalue]  " << Name << std::endl;
}

// ��ֵ����
void Print( const std::string &&Name ){
    std::cout << "[rvalue]  " << Name << std::endl;
}

int main( ){
    std::string First = "Gao";
    std::string Second = "june";
    std::string Name = First + Second;


    Print( First );             // lvalue
    Print( First + Second );    // rvalue
    Print( Name );              // lvalue

    return 0;
}
