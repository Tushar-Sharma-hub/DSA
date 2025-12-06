//In 2D array when we pass it to function we have to mention the size of it but it is not necessary in vector.
#include<iostream>
using namespace std;
int main(){
    vector<vector<int>> v(5); //it makes vector with 5 vectors in it.(means 5 rows)
    vector<vector<int>> v1(5,vector<int>(4));//it makes vector with 5 vector in it(5 rows) with each vector have size of 4(means 4 columns).
    vector<vector<int>> v2(5,vector<int>(4,2));//same as v1 just intializes all with 2.
    cout<<v1.size(); //number of rows.
    cout<<endl<<v1[0].size();//number of columns.
}