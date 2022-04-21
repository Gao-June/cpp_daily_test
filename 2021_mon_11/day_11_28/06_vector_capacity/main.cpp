
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> temp;
    temp.push_back(1);
     temp.push_back(2);
      temp.push_back(3);
    for ( int i = 1; i <= 100; i ++){
        cout << temp.capacity() << endl;
        temp.emplace_back(i);
    }



    return 0;
}