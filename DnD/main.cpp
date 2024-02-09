#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Character {
private:
    string name;
    string race;
    string characterClass;
    string background;
    string alignment;
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int hitPoints;
    int speed;
    int initiative;

public:
    Character() {
        name = "";
        race = "";
        characterClass = "";
        strength = 0;
        dexterity = 0;
        constitution = 0;
        intelligence = 0;
        wisdom = 0;
        charisma = 0;
    }
    void setName(string n){
        name = n;
    }
    void setRace(string r){
        race = r;
    }
    void setClass(string c){
        characterClass = c;
    }
    void setStrength(int s){
        strength = s;
    }
    void setDexterity(int d){
        dexterity = d;
    }
    void setConstitution(int c){
        constitution = c;
    }
    void setIntelligence(int i){
        intelligence = i;
    }
    void setWisdom(int w){
        wisdom = w;
    }
    void setCharisma(int c){
        charisma = c;
    }
    void setHitPoints(int h){
        hitPoints = h;
    }
    void setInitiative(int i){
        initiative = i;
    }
};

int main(){
    cout << "Welcome to the Dungeons and Dragons Character Sheet" << endl;
}
