#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main (){
	string _temp;
	vector<string> vec;
	ifstream input("/home/wuxiangdong/WorkSpace/C++ primer/8.4-P285/test",ios::in);
	if(input){
		while(getline(input,_temp)){
			vec.push_back(_temp);
			cout << _temp << endl;
		}	
	}else{
		cerr << "Error!open test failed!" << endl;
		return -1;
	}
	return 0;
}
