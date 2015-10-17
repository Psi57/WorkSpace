#include "handfile.h"
#include <vector>
#include <iostream>
using namespace std;
int main(){
	double _temp,_temp2;
	vector<double> _vec;
	vector<double> _weigh;
	while(true){
		if(cin >> _temp){
			if(cin >> _temp2){
				_vec.push_back(_temp);
				_weigh.push_back(_temp2);
				}else{
					cerr << "Error:weigh mush be a math!";
					break;
				}
		}else{
			if(_vec.size()==0){
				break;
			}
			if(_vec.size()!=_weigh.size()){
				cerr << "Error:The number of mathes mush be the same as that of weighes!";
				break;
			}
			cout << "加权平均数:"<< weighted_average(_vec,_weigh)<<endl;
			cin.clear();
			cin.ignore();
			_vec.clear();
			_weigh.clear();
		}
	}
	return 0;
}
