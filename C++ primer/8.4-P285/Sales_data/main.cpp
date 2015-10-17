#include "Sales_data.h"
#include <fstream>
using namespace std;
int main(int argc,char *argv[]){
	ifstream input (argv[1],ios::in);	
	ofstream output (argv[2],ios::app);
	if(argc < 3){
		cerr << "参数错误" << endl;
		return -1;
	}
	if (!(input&&output)){
		cerr << "Failed to open file ";
		return -1;
	}
	Sales_data total;
	if (read(input,total)){
		Sales_data trans;
		while(read(input,trans)){
			if(total.isbn()==trans.isbn()){
				total.combine(trans);
			}else{
				print(output,total) << endl;
				total=trans;
			}
		}
		print(output,total) << endl;
	}else{
		cerr << "No data?" << endl;
	}
	return 0;
}
