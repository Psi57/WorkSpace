//Archlinux-Installtion
//Copyright © 2015 wuxiangdong

//This program is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 2 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program; if not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <vector>
#include <fstream>
#include "gramar.h"
using namespace std;
vector <variable> variables;
vector <sgin> sgins;
int main(int argc, char *argv[]){
	if(argc == 0){
		cerr << "usage: Installtion [options]" << endl
			<< endl
			<< "Options: -c Config Installtion" << endl
			<< "-f [File] Load configuration" << endl
			<< "-h  Print this help message" << endl;
	}else if (strcmp(argv[1],"-h")) {
		cerr << "usage: Installtion [options]" << endl
		<< endl
		<< "Options: -c Config Installtion" << endl
		<< "-f [File] Load configuration" << endl
		<< "-h  Print this help message" << endl;
	}else if (strcmp(argv[1],"-f")) {
		//run config
	}
	return 0;
}
