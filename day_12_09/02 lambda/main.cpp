/*
    lambda ʾ��
    1- ��Сʾ��
    2- sort() �������������� vertor ��������
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main( ){
    // ʾ�� 1�� use lambda simply
    int id = 0;
    // id ��������� ���ã�&����ʽ���񣬻ᱨ��
    auto f = [ &id ] ( ) {
        cout << "now id = " << id << endl;
        id++;
    };
    f();    // now id = 0
    f();    // now id = 1
    f();    // now id = 2

    // ʾ�� 2������ sort����ʽ
    vector<int> nums1 = {1,4,6,3,7,8};
    // ��ӡ��ʼ�仯��
    cout << "no1 " << endl;
    for ( auto &n1 : nums1 ){
        cout << n1 << "  ";
    }
    cout << endl;
    // ���� sort ��
    sort( nums1.begin(), nums1.end() );
    cout << "no2  " << endl;
    for ( auto &n1 : nums1 ){
        cout << n1 << "  ";
    }
    cout << endl;

    // ʹ�� lambda �����ӡ
        vector<int> nums2 = {1,4,6,3,7,8};
    // ��ӡ��ʼ�仯��
    cout << "no3 " << endl;
    for ( auto &n2 : nums2 ){
        cout << n2 << "  ";
    }
    cout << endl;
    // ���� sort ��
    sort( nums2.begin(), nums2.end(), []( int nu1, int nu2 ){
        return nu1 > nu2;    } 
    );
    cout << "no4  " << endl;
    for ( auto &n2 : nums2 ){
        cout << n2 << "  ";
    }
    cout << endl;

    return 0;
}