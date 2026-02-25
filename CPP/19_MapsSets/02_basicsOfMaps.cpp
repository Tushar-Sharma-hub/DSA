#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> m;

    pair<string,int> p1("abc",1);
    m.insert(p1);

    m.insert({"def",2});

    m["ghi"]=3;

    m["abc"]=10; //update value of key "abc"

    m.erase("def");
    //for each loop
    for(pair<string,int> p : m){ //we will use auto in next line
        cout<<p.first<<" "<<p.second<<endl;
    }
    for(auto p : m){ //we can also use auto& to avoid copying of pair
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<m["abc"]<<endl; //10
    cout<<m["def"]<<endl; //0, creates a new key "def
    for(pair<string,int> p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
}