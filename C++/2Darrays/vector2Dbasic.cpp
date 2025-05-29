// Advantage of vector over array:
// 1.We can increase number of rows.
// 2.Variable columns(means each row can have different columns.)
//In 2D vectors we pushback and popback vectors.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> v; //vector inside a vector make 2d matric/array.
    
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(3);

    vector<int> v2;
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);

    vector<int> v3;
    v3.push_back(8);
    v3.push_back(9);
    v3.push_back(10);
    v3.push_back(11);
    v3.push_back(12);
    v3.push_back(13);

    v.push_back(v1); //{{0,1,3},{4,5,6,7},{8,9,10,11,12,13}}
    v.push_back(v2);
    v.push_back(v3);

    cout<<v.size()<<endl;
    cout<<v[0].size()<<endl;
    cout<<v[1].size()<<endl;
    cout<<v[2].size();
}