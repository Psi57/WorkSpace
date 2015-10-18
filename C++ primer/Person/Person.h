#include <string>
#include <iostream>
class person {
	friend std::istream &read(std::istream&,person&);
	friend std::ostream &print (std::ostream&,const person&);
public:
	person () = default;
	person (const std::string &Sname,const std::string &Saddress) : name(Sname),address(Saddress){};
	std::string getname () const {return name;};
	std::string getaddress () const {return address;};
private:
	std::string name,address;
};
std::istream& read(std::istream &is,person &P){
	is >> P.name >> P.address;
	return is;
}
std::ostream &print (std::ostream &os,const person &P){
	os << P.name << " "
	<< P.address;
	return os;
}
