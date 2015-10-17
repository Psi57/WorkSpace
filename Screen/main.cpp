#include "screen.h"
#include <iostream>
using namespace std;
int main (){
	screen myscreen(5,5,'X');
	myscreen.move(4,0).set('#').display(cout);
	cout << endl;
	myscreen.display(cout);
	cout << "\n";
	return 0;
}
