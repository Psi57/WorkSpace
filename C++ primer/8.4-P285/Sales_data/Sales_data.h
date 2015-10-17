/*
 * New By Wuxiangdong at 2015-5-14
 */
#ifndef SALES_DATA
#define SALES_DATA
#include <string>
#include <iostream>
using namespace std;
class Sales_data {
	friend std::istream &read(std::istream&,Sales_data&);
	friend std::ostream &print(std::ostream&,const Sales_data&);
	friend Sales_data add (const Sales_data&,const Sales_data&);
	public:
		Sales_data (const std::string s,unsigned n,double p) : bookNo(s),units_sold(n),revenue(p*n){};	
		Sales_data () : Sales_data("",0,0.0){}; 
		Sales_data (const std::string s) : Sales_data(s,0,0){};
		Sales_data (std::istream &is) : Sales_data(){read(is,*this);};
		std::string isbn() const {return bookNo;};
		Sales_data& combine(const Sales_data&);
		double avg_price () const;
	private:
		std::string bookNo;
		unsigned units_sold=0;
		double revenue=0.0;
};
Sales_data& Sales_data::combine (const Sales_data &rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
inline double Sales_data::avg_price() const {
	if(units_sold){
		return revenue / units_sold;
	}
	return 0;
}
std::istream &read(std::istream &is,Sales_data &item){
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
std::ostream &print(std::ostream &os,const Sales_data &item){
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}
Sales_data add (const Sales_data &lhs,const Sales_data &rhs){
	Sales_data sum = lhs;
	sum.combine (rhs);
	return sum;
}
#endif

