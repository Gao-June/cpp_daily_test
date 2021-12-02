#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s = "hello";

    auto i = sizeof(s);
    cout << i << endl;
    
    return 0;
}