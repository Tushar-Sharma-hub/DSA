#include<iostream>
using namespace std;
class Cricketer{
    public:
    string name;
    int runs;
    float avg;
    Cricketer(string n,int r,float a): name(n),runs(r),avg(a){}
};
int main(){
    Cricketer c1("Virat Kohli",25000,55.2);
    // Cricketer c2("Rohit Sharma",30000,47.8);
    Cricketer* p1=&c1;
    cout<<(*p1).runs<<endl;
    cout<<c1.avg<<endl;
    (*p1).avg=77.5;
    cout<<c1.avg<<endl;
}