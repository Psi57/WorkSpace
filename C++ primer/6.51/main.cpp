#include <iostream>
using namespace std;
void f (){cout << "void"<<endl;}
void f (int){cout << "int"<<endl;}
void f (int,int){cout << "int,int"<<endl;}
void f (double,double=3.14){cout << "double,double"<<endl;}
int main (){
	//call to f(2.56,42) is ambiguous
	f(42);
	f(42,0);
	f(2.56,3.14);
	return 0;
}
