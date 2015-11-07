#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
	std::vector<string> v1 {"123456789","1234567","123456","1234"};
	// cout << count_if(v1.begin(), v1.end(), [](string i){return i.size() > 6;}) << endl;
	cout << count_if(v1.begin(), v1.end(), [](string i) -> bool {if(i.size() > 6){return true;}return false;}) << endl;
	return 0;
}
