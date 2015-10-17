#ifndef screen
#define screen value
#include <string>
#include <vector>
class screen;
class window_mgr{
public:
	typedef std::vector<screen>::size_type screenindex;
	void clear (screenindex);
private:
	std::vector<screen> screens{};
};
class screen{
public:
	friend void window_mgr::clear(screenindex);
	typedef std::string::size_type pos;
	screen() = default;
	screen(pos ht,pos wd,char c) : height(ht),width(wd),contents(ht*wd,c){}
	screen(pos ht,pos wd) : height(ht),width(wd),contents(ht*wd,' '){}
	char get () const {return contents[cursor];}
	inline char get (pos h,pos w) const;
	screen &move (pos r,pos c);
	screen &set(char);
	screen &set(pos,pos,char);
	screen display (std::ostream &os){do_display (os);return *this;}
	const screen &display (std::ostream &os) const {do_display(os);return *this;}
private:
void do_display(std::ostream &os) const {os << contents;}
	pos cursor = 0;
	pos height = 0,width = 0;
	std::string contents;

};
void window_mgr::clear(screenindex index){
	screen &s = screens[index];
	s.contents = std::string (s.height*s.width,' ');
}
inline screen &screen::set(char c){
	contents[cursor]=c;
	return *this;
}
inline screen &screen::set(pos h,pos w,char c){
	contents[h*width+w]=c;
	return *this;
}
inline screen &screen::move (pos r,pos c){
	cursor = r*width+c;
	return *this;
}
char screen::get(pos h,pos w) const {
	pos c = h*width;
	return (contents[c+w]);
}
#endif
