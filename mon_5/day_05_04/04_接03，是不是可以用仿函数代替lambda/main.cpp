/**
 * �� 03 ���� lambda�滻�� �º�����������̽�����Ƿ����� �º������� lambda
 * 
 * ���ԣ�
 *  дһ�� sort() ��������
 * ���ۣ�
 *  �ǿ��Եģ���������º���Ҫ��һ��() ʵ����
 */

#include <iostream>
#include <algorithm>
#include <vector>

// д�º���
class Cmp{
public:
    bool operator()( const int& a, const int& b ) const{
        return a >= b;
    }
};

int main( ){
    std::vector<int> nums{1, 7, 20, 9, 23, 98, 23};

    // ���������޲���
    sort( nums.begin(), nums.end() );
    for( auto& num : nums ){
        std::cout << num << "  ";
    }
    std::cout << std::endl;

    // �Զ�������
    sort( nums.begin(), nums.end(), Cmp() );
    for( auto& num : nums ){
        std::cout << num << "  ";
    }
    std::cout << std::endl;

    // д lambda
    sort( nums.begin(), nums.end(), [](const int& a, const int&b){return a <= b;}  
        );
    for( auto& num : nums ){
        std::cout << num << "  ";
    }
    std::cout << std::endl;

    return 0;
}
