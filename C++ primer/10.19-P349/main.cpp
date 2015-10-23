#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void biggies(std::vector<string> &words,vector<string>::size_type sz) {
	auto beginning = stable_partition(words.begin(), words.end(), [sz](const string &s1){return s1.size() < sz;});
	for_each(beginning, words.end(), [](const string &s1){cout << s1 << " ";});
}
int main(int argc, char const *argv[]) {
	std::vector<string> v{"ss","12345678","abcdef","sss","ssssss"};
	biggies(v, 4);
	return 0;
}
