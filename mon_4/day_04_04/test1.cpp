// ��̬��Ա����
/* Ϊʲô��Ҫ��̬��Ա������
    1 - ��̬��Ա���������룬�������ظ��ԣ�����class���Թ���һ������
    2 - ����Ҫ���ʾ�̬��Ա������ʱ����һ�ַ������� ʵ���� class��
        Ȼ��ͨ���������ʣ������������ܴ����ڴ���ģ����Ǿ����ˡ���̬��Ա������
        �������� ʵ���� class ���ʾ�̬��Ա������
*/
#include <iostream>

using namespace std;

class Something
{
private:
    static int s_value;

public:
    static int getValue(){ 
        return s_value; } // static member function
};

    int Something::s_value{ 1 }; // initializer


int main()
{
    cout << Something::getValue() << '\n';

    return 0;
}