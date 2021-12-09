/*
    讨论 vector、unordered_map扩容
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main( ){
    // 示例 1， 测试 vector 扩容
    vector<int> nums1;
    for ( int i = 0; i < 20; i ++ ){
        cout << "vector 现在的容量是： " <<  nums1.capacity( ) << endl;
        nums1.insert(nums1.end(), 1);
    }

    // 示例 2，测试 unordered_map 扩容
    // 注，哈希表容量是用 函数 bucket_count()
    unordered_map<int, int> nums2;
    for ( int i = 0; i < 100; i ++ ){
        cout << "哈希表现在的容量是： " << nums2.bucket_count() << endl;
        nums2[i] = 1;
    }

    return 0;
}
