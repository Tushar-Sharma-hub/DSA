// Passing class objects to fxns.
#include<iostream>
using namespace std;
class Gun{
    public:
    int ammo;
    int damage;
    int scope;
};
class player{
    private:
    class Helmet{
        public:
        int level;
        int hp;
        void setlevel(int level){
            this->level=level;
        }
        void sethealth(int hp){
            this->hp=hp;
        }
        int getLevel(){
            return level;
        }
        int getHealth(){
            return hp;
        }
    };
    int health;
    int age;
    int score;
    bool alive;
    Gun gun;
    Helmet helmet;

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
    Gun getgun(){
        return gun;
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
    void setgun(Gun gun){
        this->gun=gun;
    }
    void setHelmet(int level){
        helmet.setlevel(level);
        int hp=0;
        if(level==1) hp=25;
        else if(level==2) hp=50;
        else if(level==3) hp=100;
        else cout<<"Error,invalid level!";
        helmet.sethealth(hp);
    }
    void getHelmet(){
        cout<<helmet.getHealth()<<endl;
        cout<<helmet.getLevel();
    }
};
int main(){
    player oggy;
    player tushar;

    Gun akm;
    akm.ammo=40;
    akm.damage=35;
    akm.scope=6;

    oggy.setage(19);
    oggy.setalive(true);
    oggy.sethealth(99);
    oggy.setscore(100);
    oggy.setgun(akm);
    oggy.setHelmet(2);

    Gun awm;
    awm.ammo=7;
    awm.damage=75;
    awm.scope=8;

    tushar.setage(20);
    tushar.setalive(false);
    tushar.sethealth(89);
    tushar.setscore(70);
    tushar.setgun(awm);
    tushar.setHelmet(3);

    oggy.getHelmet();
    tushar.getHelmet();
}