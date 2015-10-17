#include <string>
#include <iostream>
using namespace std;
string repleace (string s,string oldVal,string newVal) {
	string::iterator i = s.begin();
	while(i != s.end()){
		cout << string(i,i+oldVal.length()) <<endl;
		if(string(i,i+oldVal.length())==oldVal){
			i = s.replace(i,i+oldVal.length(),newVal);
		}else
			++i;
	}
	return s;
}
int main (){
	cout << repleace("I think tho it is fun,we stl have to save them","tho","though") << endl;
	return 0;
}
