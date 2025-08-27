// Create a class "cricketer" that contains name of cricketer, his age, number of test matches 
// that he has played and the average runs that he has scored in each test match.
// Create an array of data type "cricketer" to hold records of 20 such cricketers and then write a program to read these records
#include<iostream>
using namespace std;

class Cricketer{
    private:
    string name;
    int age;
    int noOfTest;
    double avgRuns;
    public:
    void setData(string name,int age,int noOfTest,double avgRuns){
        this->name=name;
        this->age=age;
        this->noOfTest=noOfTest;
        this->avgRuns=avgRuns;
    }
    void display(){
        cout<<"Name: "<<name<<" Age: "<<age<<" Number of Test: "<<noOfTest<<" Average Runs: "<<avgRuns;
    }
};
int main(){
    Cricketer player[20];
    player[0].setData("Tushar",19,200,54.3);
    player[0].display();
}