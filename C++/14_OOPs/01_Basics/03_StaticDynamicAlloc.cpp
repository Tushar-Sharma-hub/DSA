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
int main(){
    player oggy; //object creation,statically.
    player tushar; //Static allocation during compile time in stack.

    player *drax=new player; //During runtime,dynamic allocation in heap.
    // player master=*drax; you make another to store pointer then use it or just use (*object) or ->.

    oggy.setage(19);
    oggy.setalive(true);
    oggy.sethealth(99);
    oggy.setscore(100);

    tushar.setage(20);
    tushar.setalive(false);
    tushar.sethealth(89);
    tushar.setscore(70);

    drax->setage(21);
    drax->setalive(true);
    drax->sethealth(79);
    drax->setscore(80);
    
    cout<<oggy.getscore()<<endl;
    cout<<tushar.getscore()<<endl;
    cout<<drax->getscore();
}