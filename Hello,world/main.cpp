#include <iostream>
#include <vector>
#include <string>
#define _s1 "Thanks for all!"
#define _s2 "I love it!"
using namespace std;
bool printscreen (string s);
class P{
public:
	int foo (int a,int b){return a+b;}
	string foo1 (){return "Hello,vim!";}
	string foo2 (){return "Hello,Clang!";}
	string foo3 (){return "Hello,All the plugins!";}
	string foo4 (){return "Coming soon....";}
	string foo5(){return "Hello,btter vim!";}
	string foo6(){return "Hello,btter atom";}
};
int main (){
	vector<string> s3 = {"HELLO!","Thanks!"};
	P s;
	printscreen("Hello,functions!");
	cout << "Hello,Wolrd!"<< endl;
	cout << "Hello,C++"<<endl;
	cout << s.foo1()<< endl << s.foo2() << endl << s.foo3() << endl;
	cout << _s1 <<endl << _s2 << endl;
	cout << s3[0] << s3[1] << endl;
	cout << s.foo4()<<endl;
	cout << s.foo5()<<endl;
	std::cout << s.foo6() << std::endl;
	return 0;
}
bool printscreen (string s){cout << s << endl;return true;}
