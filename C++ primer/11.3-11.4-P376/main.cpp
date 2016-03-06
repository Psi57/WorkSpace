#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
    std::map<string, size_t> word_count;
    set<string> exclude = {".",",",";","\'","\""};
    string word;
    while (cin >> word) {
        transform(word.begin(),word.end(),word.begin(),::tolower);
        if(exclude.find(word) == exclude.end()) ++word_count[word];
    }
    for(auto &w : word_count){
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
    return 0;
}
