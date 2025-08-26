// Passing class objects to fxns.
#include<iostream>
using namespace std;
class player{
    private:
    int health;
    int age;
    int score;
    bool alive;
    public:
    int gethealth(){
        return health;
    }
    int getage(){
        return age;
    }
    int getscore(){
        return score;
    }
    bool getalive(){
        return alive;
    }
    void sethealth(int health){
        this->health=health;
    }
    void setage(int age){
        this->age= age;
    }
    void setscore(int score){
        this->score = score;
    }
    void setalive(bool alive){
        this->alive = alive;
    }
};
int addscore(player a,player b){
    return a.getscore()+b.getscore();
}
player maxscore(player a,player b){
    if(a.getscore()==b.getscore()){
        cout<<"Equal: ";
        return a;
    }
    else if(a.getscore()>b.getscore()) return a;
    else return b;
}
int main(){
    player oggy; //object creation,statically.
    player tushar;

    oggy.setage(19);
    oggy.setalive(true);
    oggy.sethealth(99);
    oggy.setscore(100);

    tushar.setage(20);
    tushar.setalive(false);
    tushar.sethealth(89);
    tushar.setscore(70);
    cout<<addscore(oggy,tushar)<<endl; //add score
    player c=maxscore(oggy,tushar); //store details of max scorer in another player.
    cout<<c.getscore(); //return details of max scorer with help of another player.
}