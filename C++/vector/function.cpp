//Vectors are passed by value. Each time you pass,new vector is created.(to make it in same we can use &).
#include<iostream>
using namespace std;

void change(vector<int> a){ //pass by value.
    a[0]=100;
    cout<<"Changed: ";
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void change2(vector<int>& a){ //pass by reference.
    a[0]=100;
    cout<<"Changed 2: ";
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(9);
    v.push_back(8);
    v.push_back(0);
    v.push_back(3);
    cout<<"Original: ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    change(v);
    cout<<"Original didn't changed (as vector is pass by value): ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    change2(v);
    cout<<"Original changed (as vector is pass by reference through &): ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}