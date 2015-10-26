#include <iostream>
#include <vector>
using namespace std;

void swap(int &a,int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void list(int v[],int m,int n) {
	static int count = 0;
	if (m == n){
		count++;
		cout << "第" << count << "个排列:";
		for (int i = 0; i != n; i++) cout << v[i];
		cout << endl;
	}else{
		for (int i = m; i < n; i++) {
			swap(v[m],v[i]);
			list(v, m+1, n);
			swap(v[m], v[i]);
		}
	}
}

int main(int argc, char const *argv[]) {
	int i;
	cin >> i;
	int a[i-1];
	for (int v = 0; v < i; v++) {
		a[v] = v+1;
	}
	list(a, 0, i);
	return 0;
}
