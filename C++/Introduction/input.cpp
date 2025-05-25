#include<iostream>
using namespace std;
int main(){
    int age;//age check
    cout<<"Enter your age:";
    cin >> age;
    cout<<"You entered your age is:"<<age<<endl;
    if(age>=18){
        cout<<"You are allowed to drink."<<endl;
    }
    else{
        cout<<"You are not allowed to drink."<<endl;
    }

    int a,b; //sum of two numbers
    cout<<"Enter a:";
    cin>>a;
    cout<<"Enter b:";
    cin>>b;
    cout<<"The sum of a and b is :"<<(a+b);
}