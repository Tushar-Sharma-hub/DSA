//String stream is used to pick up words word by word in a sentence.

//Q.Given a sentence, split every single word of the sentence and print in a new line.
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    string str="Coding is fun.";
    stringstream ss(str);
    string temp;
    while(ss>>temp){ 
        cout<<temp<<endl;
    }
    return 0;
}