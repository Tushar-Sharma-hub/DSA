#include<iostream>
using namespace std;
class Bike{
    public:
    int tyresize;
    int enginesize;
    Bike(int ts,int es): tyresize(ts),enginesize(es){}
    Bike(int ts): tyresize(ts){}
    Bike(): tyresize(12),enginesize(15){}
    void display(){
        cout<<"Tyre Size: "<<tyresize<<", Engine Size: "<<enginesize<<endl;
    }
    void displayts(){
        cout<<"Tyre Size: "<<tyresize<<endl;
    }
};
int main(){
    Bike royalenfield(10,12);
    Bike bajaj(13);
    Bike splender;
    royalenfield.display();
    bajaj.displayts();
    splender.display();
}