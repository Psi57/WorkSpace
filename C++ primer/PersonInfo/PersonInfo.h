#include <sstream>
#include <string>
#include <vector>
#include <iostream>
class PersonInfo{
    public:
        void clear(){name="",phones.clear();}
        std::string name;
        mutable std::vector<std::string> phones;
    private:
};
std::ostream &print(std::ostream &os,PersonInfo &info,std::string space = " "){
    os << info.name;
    for(auto &a : info.phones){
        os << space << a;
    }
    return os;
}
std::ostream &print(std::ostream &os,std::vector<PersonInfo> &vec,std::string space = " ",std::string space_of_endl = "\n"){
    for(auto &info : vec){
        os << info.name;
        for(auto &a : info.phones){
            os << space << a;
        }
        os << space_of_endl;
    }
    return os;
}
std::istream &read(std::istream &is,PersonInfo &info){
    std::string line,word;
    std::istringstream recode;
    info.clear();
    while(getline(is,line)){
        recode.str(line);
        recode >> info.name;
        while(recode >> word)
            info.phones.push_back(word);
    }
    return is;
}
std::istream &read(std::istream &is,std::vector<PersonInfo> &vec){
    std::string line,word;
    PersonInfo info;
    vec.clear();
    while(getline(is,line)){
        info.clear();
        std::istringstream recode(line);
        recode >> info.name;
        while(recode >> word)
            info.phones.push_back(word);
        vec.push_back(info);
    }
    return is;
}
