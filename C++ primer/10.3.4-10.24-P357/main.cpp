#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;
void check_size(const string &s,string::size_type sz){
	if(s.size()<sz){
		cout << sz << " ";
	}
}

int main(int argc, char const *argv[]) {
	std::vector<int> v;
	int a;
	while(cin >> a){
		v.push_back(a);
	}
	string s;
	cin >> s;
	for_each(v.begin(), v.end(), bind(check_size, s,_1));

	return 0;
}
