#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main (){
	string _temp;
	vector<string> vec;
	ifstream input("/home/wuxiangdong/WorkSpace/C++ primer/8.4-P285/test",ios::in);
	if (!input){
		cerr << "Error!Open File Fail!"<<endl;
		return -1;
	}
	while(input >> _temp){
		vec.push_back(_temp);
		cout << _temp << endl;
	}
	return 0;
}
