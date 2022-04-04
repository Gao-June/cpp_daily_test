/*
    ���� vector��unordered_map����
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main( ){
    // ʾ�� 1�� ���� vector ����
    vector<int> nums1;
    for ( int i = 0; i < 20; i ++ ){
        cout << "vector ���ڵ������ǣ� " <<  nums1.capacity( ) << endl;
        nums1.insert(nums1.end(), 1);
    }

    // ʾ�� 2������ unordered_map ����
    // ע����ϣ���������� ���� bucket_count()
    unordered_map<int, int> nums2;
    for ( int i = 0; i < 100; i ++ ){
        cout << "��ϣ�����ڵ������ǣ� " << nums2.bucket_count() << endl;
        nums2[i] = 1;
    }

    return 0;
}
