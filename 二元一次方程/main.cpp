#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[]) {
	double a,b,c;
	cout << "Welcome to use this program" << endl;
	while(true){
		cout << "ax^2+bx+c=0" << endl;
		cout << "a = ";
		cin >> a;
		if(a==0){
			cerr << "a can't be 0!!!" << endl;
			continue;
		}
		cout << "b = ";
		cin >> b;
		cout << "c = ";
		cin >> c;
		double yita = b*b-4*a*c;
		if(yita >= 0){
			double yitaS = sqrt(yita);
			cout << "Δ = " << yita << endl;
			cout << "x1 = " << (-b+yitaS)/(2*a)<<endl;
			cout << "x2 = " << (-b-yitaS)/(2*a)<<endl;
		}else
		cerr << "Δ < 0!" << endl;
		return 0;
	}
}
