#include <iostream>
using namespace std;
int main (){
	int a,b;
	Begining:
	cout << "a=";
	cin >> a;
	cout  << "b=";
	cin >> b;
	cout << a+b << endl;
	goto Begining;
	cout << "Erorr!" << endl;
	return 0;
}
