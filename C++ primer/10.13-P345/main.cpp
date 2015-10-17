#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Morethanfive (string &s){return s.size() > 5;}
int main(int argc, char const *argv[]) {
	vector<string> v1{"23123","2323","23","112321","1234567"};
	auto a = partition(v1.begin(), v1.end(), Morethanfive);
	auto b = v1.begin();
	for (auto &s : v1){
		cout << s << " ";
	}
	cout << endl;
	for (auto &s : v1) {
		if(b == a) break;
		cout << s << " ";
		b++;
	}
	return 0;
}
