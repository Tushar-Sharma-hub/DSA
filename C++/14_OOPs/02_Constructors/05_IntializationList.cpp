#include<iostream>
using namespace std;

class Student{
    public:
    int rollno;
    int age;
    
    Student(int r,int a) : rollno(r),age(a){ //We can intialize using :
        
    }
    void display(){
        cout<<"Roll no.: "<<rollno<<endl<<"Age: "<<age;
    }
};

int main(){
    Student tushar(25,19);
    tushar.display();
}