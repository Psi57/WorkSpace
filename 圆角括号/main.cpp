#include <iostream>
#include <string>
using namespace std;
bool check (string s){
	bool in_string = false;
	int brackets = 0;
	for (auto &a : s){
		if(a == '\"'){
			in_string = !in_string;
		}else if(!in_string){
			if (a == '(') {
				brackets+=1;
			} else if(a == ')'){
				brackets-=1;
			}
		}
		if(brackets < 0){
			return false;
		}
	}
	return brackets == 0;
}

int main(){
	string s;
	while(true){
		getline(cin,s);
		cout << check(s) << endl;
	}
	return 0;
}
