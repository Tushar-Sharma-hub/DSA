//vectors is nothing but dynamic arrays.vector double itself if it is filled fully known as capacity.(capacity=size then double.)
#include<iostream>
using namespace std;
int main(){
    vector<int> v; //Syntax . NO NEED TO MENTION SIZE.
    v.push_back(6); //0 to 1. 1 element.
    cout<<v.capacity()<<endl; //1
    v.push_back(7); //1 to 2 . 2 element.
    cout<<v.capacity()<<endl;//2
    v.push_back(8);//2 to 4 as 2 is filled. 3 element
    cout<<v.capacity()<<endl;//4
    v.push_back(9);//4 to 4 as not full filled. 4 element
    cout<<v.capacity()<<endl;//4
    v.push_back(10);//4 to 8 as full filled.5 element
    cout<<v.capacity()<<endl;//8
    cout<<"Size:"<<v.size()<<endl; //size will just print current size of the vector.

    //to print elements in vector
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    v.pop_back();//it will pop last element and change the size but the capacity will remain same.
    return 0;
}