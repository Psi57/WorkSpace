#include "handfile.h"
#include <iostream>
#include <vector>
using namespace std;
int main (){
	double _temp;
	vector<double> _vec;
	vector<math_app_time> _apptime;
	while(true){
		if (cin >> _temp){
			_vec.push_back(_temp);
		}else{
			if(_vec.size()==0){
				break;
			}
			cout << "平均数:" << average(_vec) << " 中位数:" << median(_vec);
			_apptime = find_math_time (_vec);
			find_MAX_time(_apptime);
			for(auto &_v : _apptime){
				cout << " 众数:" << _v.math <<" 次数"<<_v.times;
			}
			cout << " 方差:" << variance(_vec) << endl;
			cin.clear();
			cin.ignore();
			_vec.clear();
		}
	}
	return 0;
}
