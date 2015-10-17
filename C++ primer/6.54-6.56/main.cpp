#include <vector>
#include <iostream>
using namespace std;
int f (int,int);
int jia (int a,int b){return a+b;}
int jiang (int a,int b){return a-b;}
int cheng (int a,int b){return a*b;}
int chu (int a,int b){if (b!=0){return a/b;}return 0;}
vector<int (*) (int,int)> V;
int main (int,char**){
	V.push_back(jia);V.push_back(jiang);V.push_back(cheng);V.push_back(chu);
	cout << V[0](1,1) << endl << V[1](1,1) << endl << V[2](1,1) << endl << V[3](1,1) << endl;
	return 0;
}
