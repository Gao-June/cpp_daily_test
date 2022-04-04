// lambda ≈≈–Ú

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Season{
  string name{};
  double averageTemperature;
};

int main( ){

    // vector<Season> seasons;
    // seasons.push_back({ "Spring", 285.0 });
    // seasons.push_back({ "Summer", 296.0 });
    // seasons.push_back({ "Fall", 288.0   });
    // seasons.push_back({ "Winter", 263.0 });
    vector<Season> seasons{ { "Spring", 285.0 },{ "Summer", 296.0 }, { "Fall", 288.0   },{ "Winter", 263.0 }};


    for (const auto& season : seasons){
        std::cout << season.name << '\t' << season.averageTemperature << '\n';
    }

    sort( seasons.begin(), seasons.end(),  
            []( const auto &a, const auto &b ){
                return a.averageTemperature <= b.averageTemperature;
            }
        );  

    cout << "changed: " << endl;
    for (const auto& season : seasons){
        std::cout << season.name << '\t' << season.averageTemperature << '\n';
    }

    return 0;
}