#include <iostream>
#include <vector>

using namespace std;


// 判断数 num 是否为质数
bool fun_charge( int num ){
    if(num == 1)
        return false;
    for(int i=2; i*i<=num; i++)
        if(num % i==0)
            return false;
    return true;
} 

int fun_find_ans( vector<int> nums ){


    if ( nums.size() == 2 ){
        return nums[1];
    }

    int len = nums.size();
    int len_end = len;

    while( len_end > 2 ){
        // for ( int i = 0; i < len_end; i ++ ){
        //     cout << nums[i] << "  ";
        // }
        // cout << endl;


        vector<int> ans;

        for ( int i = 0; i < len_end; i ++ ){
            if ( fun_charge( i + 1 ) ){
                ans.push_back( nums[i] );
            }
        }
        nums = ans;
        len_end = ans.size();
    }
  
    return nums[1];
}


int main( ){
    //vector<int> nums{1,2,3,4};
    vector<int> nums{3,1,1,4,5,6};

    cout << fun_find_ans( nums ) << endl; 

    // for( int i = 1; i <= 4; i ++ ){
    //     if( fun_charge(i) )
    //         cout << "yes" << "  ";
    //     else{
    //         cout << "no" << "  ";
    //     }
    // }
    

    return 0;
}


