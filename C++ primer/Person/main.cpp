#include <vector>
#include <algorithm>
#include "Person.h"
using namespace std;
int main (){
	std::vector<person> v{person("W", "sdsd"),person("X", "Unknow"),person("A", "USA")};
	sort(v.begin(), v.end(),compareName);
	for(auto &a : v){
		print(cout, a);
		cout << " ";
	}
	cout << endl;
	sort(v.begin(), v.end(),compareName);
	for(auto &a : v){
		print(cout, a);
		cout << " ";
	}
	return 0;
}
