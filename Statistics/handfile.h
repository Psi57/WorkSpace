#include <iostream>
#include <vector>
struct math_app_time{
    double math = 0;
    unsigned times = 0;
};
void sort (std::vector<double> &vec,int size){
    //为中位数，多个size参数
    int b=0,start=0;
    double temp=0.0;
    for (int c=0;c<size;c++){
        temp =vec[start];
        b=start;
        for (int d=start+1;d<vec.size();d++){
            if (temp>vec[d]){
                b=d;
                temp = vec[d];
            }
        }
        temp = vec[start];
        vec[start] = vec[b];
        vec[b] = temp;
        start++;
    }
}
double sum (const std::vector<double> &vec){
    double _sum=0.0;
    for(auto &v : vec){
        _sum+=v;
    }
    return _sum;
}
double average (const std::vector<double> &vec){
    return sum(vec) / vec.size();
}
double weighted_average(const std::vector<double> &vec,const std::vector<double> &weigh){
    double sum=0.0,sum2=0.0;
    for(unsigned a=0;a<=vec.size();a++){
        sum +=vec[a]*weigh[a];sum2 += weigh[a];
    }
    return sum/sum2;
}
double median (const std::vector<double> &vec){
    int size = (vec.size() / 2)+1;
    std::vector<double> temp = vec;
    sort (temp,size);
    if (vec.size() % 2){
        return temp[size-1];
    }
    return (temp[size-2]+temp[size-1])/2;
}
std::vector<math_app_time> find_math_time (std::vector<double> vec){
    sort (vec,vec.size());
    std::vector<math_app_time> vec1;
    math_app_time temp;
    temp.math=vec[0];
    for(auto &v : vec){
        if(v == temp.math){
            temp.times++;
        }else{
            vec1.push_back(temp);
            temp.math = v;
            temp.times = 1;
        }
    }
    vec1.push_back(temp);
    return vec1;
}
void find_MAX_time(std::vector<math_app_time> &vec){
    unsigned maxtime=0;
    for(auto &v : vec){
        if(v.times > maxtime){
            maxtime = v.times;
            vec.clear();
            vec.push_back(v);
        }else if(v.times == maxtime){
            vec.push_back(v);
        }
    }
}
double variance(const std::vector<double> &vec){
    double _average = average(vec);
    double sum = 0.0;
    for (auto &v : vec){
        sum+=((v-_average)*(v-_average));
    }
    return sum/vec.size();
}



