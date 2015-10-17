#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	cout << "Hello,welcome to use this program!" << endl;
	while (true) {
		int _temp;
		double a,b,c;
		cout << "1.y=ax^2+bx+c 2.y=a(x+h)^2+b 3.y=a(x-b)(x-c)  which one?" << endl;
		cin >> _temp;
		switch (_temp) {
			case 1:
				cout << "a = ";
				cin >> a;
				cout << "b = ";
				cin >> b;
				cout << "c = ";
				cin >> c;//NOT FINSHED
		}
	}
	return 0;
}
