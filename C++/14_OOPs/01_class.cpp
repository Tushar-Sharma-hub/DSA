#include<iostream>
#include<string>
using namespace std;

class Player {
    private:
    string name;
    int score;
    int health;
    
    public:
    //setter
    void setname(string s){
        name=s;
    }
    void setscore(int n){
        score=n;
    }
    void sethealth(int n){
        health=n;
    }
    //getter
    void showname(){
        cout<<"Name: "<<name<<endl;
    }
    void showscore(){
        cout<<"Score: "<<score<<endl;
    }
    void showhealth(){
        cout<<"Health: "<<health<<endl;
    }
};

int main() {
    Player p1;

    p1.setname("Tushar Sharma");
    p1.sethealth(99);
    p1.setscore(100);

    cout << "Player Details:" << endl;
    p1.showhealth();
    p1.showname();
    p1.showscore();

    return 0;
}
