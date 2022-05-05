/**
 * for_each �� C++11 ���������
 * ������ͷ�ļ� <algorithm> ��
 * 
 * ��ʽ��
 *  template< class InputIt, class UnaryFunction >
 *  UnaryFunction for_each( InputIt first, InputIt last, UnaryFunction f );
 * ˵����
 *  1) ��˳�򽫸����ĺ�������fӦ����ȡ������ range �е�ÿ���������Ľ��[first, last)��
 *  2) �������ĺ�������fӦ����ȡ�����÷�Χ��ÿ���������Ľ��[first, last)����һ����˳�򣩡�
 * ��ע��  ��� for_each������Ҫ��� lambda/�º��� ʹ�õ�Ŷ��
 *        ��ʹ���ۼӵ�ʱ��Ҫ�Զ��� operator()
 * ���ԣ�
 *  д����������Կ���
 */

#include <iostream>
#include <algorithm>
#include <vector>

struct Sum_nums
{
    void operator()(int& n) { num += n; }

    int num = 0;
};

int main( ){
    std::vector<int> nums{1, 4, 23, 98, 234, 87, 12};

    std::cout << "����:" << std::endl;
    auto Print = [ ]( const int& num ){ std::cout << num << "  "; };
    for_each( nums.begin(), nums.end(), Print );

    std::cout << "\n�Լӣ�" << std::endl;
    auto Sum_add = [ ]( int& num){ num ++; };
    for_each( nums.begin(), nums.end(), Sum_add );
    for_each( nums.begin(), nums.end(), Print );

    // ����Ϊ for_each ������ Sum_nums operator()
    std::cout << "\n�ۼӣ�" << std::endl;
    Sum_nums s = for_each( nums.begin(), nums.end(), Sum_nums() );
    std::cout << s.num << std::endl;

    return 0;
}