#include <iostream>
#include <string>
#include <vector>
using namespace std;
long double sum(vector<string> &_v){
    long double _t=0;
    for(auto &a : _v){
        _t+=stold(a);
    }
    return _t;
}
int main(){
    vector<string> _t {"3.1415926535897932384626433","3","4"};
    cout << sum(_t) << endl;
    return 0;
}
