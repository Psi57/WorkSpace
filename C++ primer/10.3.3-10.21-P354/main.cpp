#include <iostream>

int main(int argc, char const *argv[]) {
	int i;
	std::cin >> i;
	auto f = [&i]() -> bool {if(i == 0) return false;--i;return true;};
	while(f()){
		std::cout << i << " ";
	}
	return 0;
}
