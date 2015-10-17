//Archlinux Installion 's gramar including file
//Copyright © 2015 Wu Xiangdong

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

#ifndef GRAMAR
#define GRAMAR
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct variable {
	string name;
	string content;
};
struct sgin {
	string name;
	int line;
};
struct file{
	ifstream file_;
	int line;
	vector<variable> variables;
	vector<sgin> sgins;
};
/**
* 取两标识之间文本
* @para
*		string1			分割前文本
*/
string getstringA(string string1,string sgin1,string sgin2){
	int a = string1.find(sgin1)+sgin1.length();
	return string1.substr(a,string1.find(sgin2,a)-a);
}
string getstringB(string string1,string sgin1,string sgin2){
	int a=0,b=0,c=0,d=0;
	while(true){
		a=b=string1.find(sgin1,a);
		while(string1[b-1]=='\\'){
			c++;b--;
		}
		a+=sgin1.length();
		if(c%2==0)
			break;
		c=0;
	}
	c=0;
	d=a;
	while(true){
		d=b=string1.find(sgin2,d);
		while(string1[b-1]=='\\') {
			c++;b--;
		}
		if(c%2==0)
			break;
		d+=sgin2.length();
		c=0;
	}
	return string1.substr(a,d-a);
}
string getstringBefore(string string1,string sgin){
	return string1.substr(0,string1.find(sgin));
}
class configfile{
	public:
		configfile (string filename){
			file.open(filename,ios::out);
		}
		void INSTALL_PACKAGES(string name){file << "pacman --noconfirm -S " << name << endl;}
		void SERVER(string name){file << "systemctl enable " << name << endl;}
		bool Doline(string line){
			string commandname = getstringBefore(line,"(");
			if (commandname == "INSTALL") {
				INSTALL_PACKAGES(getstringA(line,"(\"","\")"));
				return true;
			} else if(commandname == "SERVER"){
				SERVER(getstringA(line,"(\"","\")"));
				return true;
			} else if(commandname == "CHAROUT"){
				cout << getstringB(line,"(\"","\")") << endl;
				return true;
			} else if (commandname == "ADD") {
				file << getstringB(line,"(\"","\")") << endl;
				return true;
			} else if (commandname == "SETSGIN"){
				sgin _s1;
				_s1.name=getstringB(line, "(\"", "\")");
				_s1.line=configsfile.line;
				configsfile.sgins.push_back(_s1);
				return true;
			} else if (commandname == "GOTO"){
				configsfile.line = getlineof(configsfile.sgins, getstringB(line, "(\"", "\")"));
				return true;
			} else if (commandname == "GETINSTRING") {
				variable _v1;
				_v1.name = getstringB(line,"(\"","\")");
				cin >> _v1.content;
				configsfile.variables.push_back(_v1);
				return true;
			} else if (commandname == "SETV") {
				variable _v;
				_v.name = getstringB(line, "(\"", "\",");
				_v.content=getstringB(line, ",\"", "\")");
				configsfile.variables.push_back(_v);
			}
			return false;
		}
		//bool Dochunk(){}//Note:need to wrtie for SWITCH and so on.
		int getlineof (std::vector<sgin> v,string name){
			for(auto &a : v){
				if(a.name==name){
					return a.line;
				}
			}
			return -1;
		}
		string getvariable(vector<variable> v,string name){
			for(auto &a : v){
				if(a.name == name){
					return a.content;
				}
			}
			return "";
		}

		//bool Do(){
		//vector<string> v;
		//string a;
		//while(getline(configsfile.file_, a)){
		//v.push_back(a);
		//}

		//while(true){
		//string commname = getstringBefore(v[configsfile.line], "(");
		//if (commname == "GOTO") {
		//configsfile.line = getlineof(configsfile.sgins, getstringB(v[configsfile.line], "(\"", "\")"));
		//}
		//}
		//return true;
		//}

		//note:All of the fun "Do" need to recode!!!!!!!!!!!
	private:
		ofstream file;
		struct file configsfile;
};
#endif
