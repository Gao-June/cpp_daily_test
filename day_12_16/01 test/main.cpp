#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main( ){
    queue< pair<int, int> > nums;
    nums.push(make_pair(1,2) );
    nums.push(make_pair(3,4) );
    nums.push(make_pair(5,6) );
    nums.push(make_pair(7,8) );

    while( !nums.empty() ){
        auto num = nums.front( );
        cout << num.first << "   " << num.second << endl;
        nums.pop();
    }


    return 0;
}