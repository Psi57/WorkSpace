#include <iostream>
#include <vector>
using namespace std;
bool rearrange (vector<unsigned> &vec){
	unsigned _temp = vec[0];
	int size = vec.size();
	for (auto &a : vec) {
		if(a > _temp){
			for(int c = size - 1; size >=1; --c){
				for (int i = c-1; i >= 0; --i) {
					if(vec[i] < vec[c]){
						swap(vec[i],vec[c]);
						return true;
					}
				}
				return false;
				return true;
			}
		}
		_temp = a;
	}
	for(int d = 0;d < size/2;d++){
		swap(vec[d],vec[size-1-d]);
		return true;
	}
	return false;
}
int main(){
	unsigned _temp;
	std::vector<unsigned> v;
	while(cin >> _temp){
		v.push_back(_temp);
	}
	cin.clear();
	if(rearrange(v)){
		for(auto &a : v){
			cout << a << " ";
		}
	}else cerr << "ERROR!" << endl;
	return 0;
}
