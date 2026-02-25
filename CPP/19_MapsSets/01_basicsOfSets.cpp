#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s; //only stores unique element.
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.erase(2);
    //for each loop
    for(int ele : s){
        cout<<ele<<" ";
    }
    int target=3;
    if(s.find(target)==s.end()) cout<<"Not Found";
    else cout<<"Found";
}