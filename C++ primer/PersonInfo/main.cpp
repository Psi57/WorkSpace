#include <fstream>
#include "PersonInfo.h"
#include <iostream>
using namespace std;
int main(int argc,char *argv[]){
	if(argc < 2){
		cerr << "Error!parameter is not enough!";
		return -1;
	}
	vector<PersonInfo> vec;
	ifstream input (argv[1],ios::in);
	if(!input){
		cerr << "Error!Failed to open file:" << argv[1];
		return -1;
	}
	read(input,vec);
	print(cout,vec);
	return 0;
}
