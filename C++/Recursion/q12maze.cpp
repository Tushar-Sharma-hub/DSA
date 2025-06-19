//Maze path - number of choices to reach final destination from one point to another in a matrix maze.
//You can only go rightways or downwards.
#include<iostream>
using namespace std;

int maze(int sr,int sc,int er,int ec){ //sr-staring row,er-ending row
    if(sr>er || sc>ec) return 0;
    if(sr==er && sc==ec) return 1;
    int rightways=maze(sr,sc+1,er,ec);
    int downways=maze(sr+1,sc,er,ec);
    return rightways+downways;
}

void printpath(int sr,int sc,int er,int ec,string s){
    if(sr>er || sc>ec) return;
    if(sr==er && sc==ec){
        cout<<s<<endl;
        return;
    }
    printpath(sr,sc+1,er,ec,s+'R');
    printpath(sr+1,sc,er,ec,s+'D');
}

int main(){
    printpath(0,0,2,2,"");
    return 0;
}