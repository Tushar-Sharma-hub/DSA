//Stair Path
//Either one or two steps.
#include<iostream>
using namespace std;

int choices(int s){
    if(s==2) return 2;
    if(s==1) return 1;
    return choices(s-1)+choices(s-2);
}

int main(){
    int stairs;
    cout<<"Enter number of stairs:";
    cin>>stairs;
    cout<<choices(stairs);
    return 0;
}