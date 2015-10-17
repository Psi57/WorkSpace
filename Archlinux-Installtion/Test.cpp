#include "gramar.h"
#include <iostream>
using namespace std;
int main(){
	configfile test("/home/wuxiangdong/WorkSpace/Archlinux-Installtion/TEST.sh");
	cout << getstringA("\"1234567890\"","\"","\"") << endl
		<<"\"\\\"1234567890\\\"\"" << endl
		<< getstringA("\"\\\"1234567890\\\"\"","\"","\"")<<endl
		<< getstringB("\"\\\"1234567890\\\"\"","\"","\"")<<endl
		<<getstringBefore("ssssssssssssssssssssss()","(") << endl;
	test.Doline("INSTALL(\"filefox\")");
	test.Doline("SERVER(\"NetWorkManager\")");
	test.Doline("CHAROUT(\"It works!\")");
	test.Doline("ADD(\"pacman -Ss linux\")");
	test.Doline("SETV(\"STRING\",\"HHHHHH\")");

	return 0;
}
