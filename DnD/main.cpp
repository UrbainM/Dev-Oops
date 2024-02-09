#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    int armorClass;
    vector<string> validRaces = {"Human", "Elf", "Dwarf", "Tiefling", "Gnome", "Dragonborn", "Half-Elf", "Half-Orc"};
    vector<string> validClasses = {"Barbarian", "Bard", "Cleric", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard", "Artificer","Blood Hunter"};
    vector<string> knownSkills;

public:
    Character() {
        name = "";
        race = "";
        characterClass = "";
        background = "";
        alignment = "";
        strength = 0;
        dexterity = 0;
        constitution = 0;
        intelligence = 0;
        wisdom = 0;
        charisma = 0;
        speed = 0;
        initiative = 0;
        armorClass = 0;
    }
    //mutators
    void setName(string n){
        name = n;
    }
    void setRace(string r){
        race = r;
    }
    void setClass(string c){
        characterClass = c;
    }
    void setBackground( string b){
        background = b;
    }
    void setAlignment(string a){
        alignment = a;
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
    void setArmorClass(int ac){
        armorClass = ac;
    }
    void addSkill(string s){
        knownSkills.push_back(s);
    }
    //accessors
    string getName() const {
        return name;
    }
    string getRace() const {
        return race;
    }
    string getClass() const {
        return characterClass;
    }
    string getBackground() const {
        return background;
    }
    string getAlignment() const {
        return alignment;
    }
    int getStrength() const {
        return strength;
    }
    int getDexterity() const {
        return dexterity;
    }
    int getConstitution() const {
        return constitution;
    }
    int getWisdom() const {
        return wisdom;
    }
    int getCharisma() const {
        return charisma;
    }
    bool isValidRace(string r) const {
        return find(validRaces.begin(), validRaces.end(), r) != validRaces.end();
    }
    int getHitPoints() const {
        return hitPoints;
    }
    int getArmorClass() const {
        return armorClass;
    }
    vector<string> getknownSkills() const {
        return knownSkills;
    }
};


int main(){
    Character character;
    string name, race, characterClass, background;
    int strength, constitution, intelligence, wisdom, charisma;
    cout << "Welcome to the Dungeons and Dragons Character Sheet"    << endl;
    cout << "Please enter your character's name: ";
    getline(cin, name);
    character.setName(name);

    bool ValidRace = false;
    while (!ValidRace) {
        cout << "Please enter character race: ";
        getline(cin, race);
        if (character.isValidRace(race)) {
            ValidRace = true;
            character.setRace(race);
        } else {
            cout << "Invalid race. ";
        }
    }
    cout << "Enter character class: ";
    getline(cin, characterClass);
    character.setClass(characterClass);

    cout << "Enter a character background: ";
    getline(cin, background);
    character.setBackground(background);


    return 0;
}
