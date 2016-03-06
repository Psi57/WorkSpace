#include "Sales_data.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
    Sales_data a("K",2,3);
    Sales_data a1;
    Sales_data a2(cin);
    Sales_data a3("B");
    // 10.12 345
    std::vector<Sales_data>v{Sales_data("KSAdsasd",2,3),Sales_data("C++",3,2),Sales_data("Lua",3,2),Sales_data("sh",2,3)};

    sort(v.begin(), v.end(), compareIsbn);
    for_each(v.begin(), v.end(), [](Sales_data s){print(cout, s);cout << endl;});
    return 0;
}
