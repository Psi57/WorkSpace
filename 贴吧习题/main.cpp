#include <iostream>
int _atoi (const char *s){
	int result = 0,i = 0;
	bool minus = false;
	while(true){
		if(s[i]=='-') minus = !minus; else if(s[i]!= '+') break;
		i++;
	}
	while(s[i] != '\0'){
		if (s[i]< '9' &&s[i]>'0'){
			result+=s[i]-'0';
		}else break;
		result *= 10;
		i++;
	}
	result /= 10;
	if(minus){
		return result*-1;
	}
	return result;
}
int main (){
	std::cout << _atoi("--+11") << std::endl;
	std::cout << atoi("-12") << std::endl;
	std::cout << _atoi("--+11")-_atoi("-12") << std::endl;
	return 0;
}
