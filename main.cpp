#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class player {
public:
    string name;
    string playerclass;
    string race;
    string alignmentlaw;
    string alignmentmore;
    string weapon;
    string pronoun;
    int hitpoints;
    int kills;
    bool alive;
};

class monster {
public:
    string name;
    int hitpoints;
    int damage;
    bool alive;
};

int map[7][7];
int currentPosition = 11;
int lastPosition = 11;
bool play = true;
player partyoptions[16];
player party[4];
monster weakmonster[16];
monster mediummonster[12];
monster strongmonster[5];
monster boss; //he's special so he gets his own variable <3
string playerclassl[9] = { "Bard", "Cleric", "Druid", "Fighter", "Paladin", "Ranger", "Rogue", "Warlock", "Wizard" };
string bosses[9] = { "???", "Nalzok", "Minion of Huhetotl", "Ixoth", "Lord Surtur", "Scorpius", "Master Assassin", "The Dark One", "The Dark One" };
string racel[9] = { "Dragonborn", "Dwarf", "Elf", "Gnome", "Half-Elf", "Halfling", "Half-Orc", "Human", "Tiefling" };
string alignmentlawl[4] = { "Lawful", "Neutral", "Chaotic", "True" };
string alignmentmorel[3] = { "Good", "Neutral", "Evil" };
string weaponl[7] = { "Bow", "Club", "Dagger", "Handaxe", "Javelin", "Longsword", "Spear" };

void createParty() {
    srand (time(NULL));
    int pick, randompick, randompick2;
    stringstream yeet;
    string foo;
    char confirm = 'n';
    bool picked[16] = { false };
    
    partyoptions[0].name = "Sarquinal";
    partyoptions[0].playerclass = "Bard";
    partyoptions[0].race = "Simic Hybrid";
    partyoptions[0].alignmentlaw = "Chaotic";
    partyoptions[0].alignmentmore = "Good";
    partyoptions[0].weapon = "Snake";
    partyoptions[0].pronoun = "he";
    
    partyoptions[1].name = "Zumris";
    partyoptions[1].playerclass = "Bard";
    partyoptions[1].race = "Firbolg";
    partyoptions[1].alignmentlaw = "Chaotic";
    partyoptions[1].alignmentmore = "Evil";
    partyoptions[1].weapon = "Hatchet";
    partyoptions[1].pronoun = "he";
    
    partyoptions[2].name = "Nofte";
    partyoptions[2].playerclass = "Bard";
    partyoptions[2].race = "Kobold";
    partyoptions[2].alignmentlaw = "Lawful";
    partyoptions[2].alignmentmore = "Neutral";
    partyoptions[2].weapon = "Dagger";
    partyoptions[2].pronoun = "he";
    
    partyoptions[3].name = "Nikk";
    partyoptions[3].playerclass = "Cleric";
    partyoptions[3].race = "Aarakocra";
    partyoptions[3].alignmentlaw = "True";
    partyoptions[3].alignmentmore = "Neutral";
    partyoptions[3].weapon = "Spear";
    partyoptions[3].pronoun = "he";
    
    partyoptions[4].name = "Halzyek The Forsaken";
    partyoptions[4].playerclass = "Cleric";
    partyoptions[4].race = "Orc";
    partyoptions[4].alignmentlaw = "Neutral";
    partyoptions[4].alignmentmore = "Good";
    partyoptions[4].weapon = "Short Sword";
    partyoptions[4].pronoun = "she";
    
    partyoptions[5].name = "Darak Toughhide";
    partyoptions[5].playerclass = "Druid";
    partyoptions[5].race = "Minotaur";
    partyoptions[5].alignmentlaw = "Chaotic";
    partyoptions[5].alignmentmore = "Evil";
    partyoptions[5].weapon = "Javelin";
    partyoptions[5].pronoun = "he";
    
    partyoptions[6].name = "Darmalis";
    partyoptions[6].playerclass = "Fighter";
    partyoptions[6].race = "Half-Elf";
    partyoptions[6].alignmentlaw = "Neutral";
    partyoptions[6].alignmentmore = "Evil";
    partyoptions[6].weapon = "Longsword";
    partyoptions[6].pronoun = "they";
    
    partyoptions[7].name = "Gretru Hretru";
    partyoptions[7].playerclass = "Fighter";
    partyoptions[7].race = "Bugbear";
    partyoptions[7].alignmentlaw = "Lawful";
    partyoptions[7].alignmentmore = "Neutral";
    partyoptions[7].weapon = "Claws";
    partyoptions[7].pronoun = "she";
    
    partyoptions[8].name = "Niwyn";
    partyoptions[8].playerclass = "Paladin";
    partyoptions[8].race = "Gnome";
    partyoptions[8].alignmentlaw = "Chaotic";
    partyoptions[8].alignmentmore = "Good";
    partyoptions[8].weapon = "Axe";
    partyoptions[8].pronoun = "she";
    
    partyoptions[9].name = "Hana";
    partyoptions[9].playerclass = "Paladin";
    partyoptions[9].race = "Human";
    partyoptions[9].alignmentlaw = "Lawful";
    partyoptions[9].alignmentmore = "Good";
    partyoptions[9].weapon = "Longsword";
    partyoptions[9].pronoun = "she";
    
    partyoptions[10].name = "Khalli";
    partyoptions[10].playerclass = "Ranger";
    partyoptions[10].race = "Aarakocra";
    partyoptions[10].alignmentlaw = "True";
    partyoptions[10].alignmentmore = "Neutral";
    partyoptions[10].weapon = "Bow";
    partyoptions[10].pronoun = "she";
    
    partyoptions[11].name = "Venres Mehlollath";
    partyoptions[11].playerclass = "Ranger";
    partyoptions[11].race = "Triton";
    partyoptions[11].alignmentlaw = "Lawful";
    partyoptions[11].alignmentmore = "Evil";
    partyoptions[11].weapon = "Longsword";
    partyoptions[11].pronoun = "she";
    
    partyoptions[12].name = "Timber";
    partyoptions[12].playerclass = "Rogue";
    partyoptions[12].race = "Tabaxi";
    partyoptions[12].alignmentlaw = "Chaotic";
    partyoptions[12].alignmentmore = "Neutral";
    partyoptions[12].weapon = "Longsword";
    partyoptions[12].pronoun = "he";
    
    partyoptions[13].name = "Razga";
    partyoptions[13].playerclass = "Warlock";
    partyoptions[13].race = "Goblin";
    partyoptions[13].alignmentlaw = "Lawful";
    partyoptions[13].alignmentmore = "Good";
    partyoptions[13].weapon = "Staff";
    partyoptions[13].pronoun = "he";
    
    partyoptions[14].name = "Clay";
    partyoptions[14].playerclass = "Wizard";
    partyoptions[14].race = "Earth Genasi";
    partyoptions[14].alignmentlaw = "Neutral";
    partyoptions[14].alignmentmore = "Good";
    partyoptions[14].weapon = "Spellbook";
    partyoptions[14].pronoun = "he";
    
    partyoptions[15].name = "Dawso";
    partyoptions[15].playerclass = "Wizard";
    partyoptions[15].race = "Tortle";
    partyoptions[15].alignmentlaw = "Chaotic";
    partyoptions[15].alignmentmore = "Neutral";
    partyoptions[15].weapon = "Staff";
    partyoptions[15].pronoun = "they";
    
    cout << "Who are you? ";
    cin >> party[0].name;
    
    cout << "What is your preferred pronoun? ";
    cin >> party[0].pronoun;
    
    cout << "What class player are you?" << endl << "1) Bard\n2) Cleric\n3) Druid\n4) Fighter\n5) Paladin\n6) Ranger\n7) Rogue\n8) Warlock\n9) Wizard\n10) Random" << endl;
    cin >> pick;
    if (pick == 10) {
        while (confirm != 'y' && confirm != 'Y') {
            randompick = rand() % 9;
            cout << "A " << playerclassl[randompick] << "? (Y/N) ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                pick = randompick + 1;
            }
        }
    }
    party[0].playerclass = playerclassl[pick - 1];
    boss.name = bosses[pick - 1];
    confirm = 'n';
    
    cout << "What race are you?" << endl << "1) Dragonborn\n2) Dwarf\n3) Elf\n4) Gnome\n5) Half-Elf\n6) Halfling\n7) Half-Orc\n8) Human\n9) Tiefling\n10) Random" << endl;
    cin >> pick;
    if (pick == 10) {
        while (confirm != 'y' && confirm != 'Y') {
            randompick = rand() % 9;
            cout << "A " << racel[randompick] << "? (Y/N) ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                pick = randompick + 1;
            }
        }
    }
    party[0].race = racel[pick - 1];
    confirm = 'n';
    
    cout << "What do you wield?" << endl << "1) Bow\n2) Club\n3) Dagger\n4) Handaxe\n5) Javelin\n6) Longsword\n7) Spear\n8) Random" << endl;
    cin >> pick;
    if (pick == 8) {
        while (confirm != 'y' && confirm != 'Y') {
            randompick = rand() % 8;
            cout << "A " << weaponl[randompick] << "? (Y/N) ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                pick = randompick + 1;
            }
        }
    }
    party[0].weapon = weaponl[pick - 1];
    confirm = 'n';
    
    cout << "What's your alignment?" << endl << "1) Lawful Good\t\t2) Neutral Good\t\t3) Chaotic Good\n4) Lawful Neutral\t5) True Neutral\t\t6) Chaotic Neutral\n7) Lawful Evil\t\t8) Neutral Evil\t\t9) Chaotic Evil\n10) Random" << endl;
    cin >> pick;
    if (pick == 10) {
        while (confirm != 'y' && confirm != 'Y') {
            randompick2 = rand() % 3;
            randompick = rand() % 3;
            if (randompick == 1 && randompick2 == 1) cout << alignmentlawl[3] << " " << alignmentmorel[randompick2] << "? (Y/N) ";
            else cout << alignmentlawl[randompick] << " " << alignmentmorel[randompick2] << "? (Y/N) ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                switch (randompick2) {
                    case 0:
                        pick = randompick + 1;
                        break;
                    case 1:
                        pick = randompick + 4;
                        break;
                    case 2:
                        pick = randompick + 7;
                        break;
                    default:
                        break;
                }
            }
        }
    }
    switch (pick) {
        case 1:
            party[0].alignmentlaw = alignmentlawl[0];
            party[0].alignmentmore = alignmentmorel[0];
            break;
        case 2:
            party[0].alignmentlaw = alignmentlawl[1];
            party[0].alignmentmore = alignmentmorel[0];
            break;
        case 3:
            party[0].alignmentlaw = alignmentlawl[2];
            party[0].alignmentmore = alignmentmorel[0];
            break;
        case 4:
            party[0].alignmentlaw = alignmentlawl[0];
            party[0].alignmentmore = alignmentmorel[1];
            break;
        case 5:
            party[0].alignmentlaw = alignmentlawl[3];
            party[0].alignmentmore = alignmentmorel[1];
            break;
        case 6:
            party[0].alignmentlaw = alignmentlawl[2];
            party[0].alignmentmore = alignmentmorel[1];
            break;
        case 7:
            party[0].alignmentlaw = alignmentlawl[0];
            party[0].alignmentmore = alignmentmorel[2];
            break;
        case 8:
            party[0].alignmentlaw = alignmentlawl[1];
            party[0].alignmentmore = alignmentmorel[2];
            break;
        case 9:
            party[0].alignmentlaw = alignmentlawl[2];
            party[0].alignmentmore = alignmentmorel[2];
            break;
        default:
            break;
    }
    
    for (int i = 0; i < 16; i++) {
        cout << endl << i+1 << ")\tName: " << partyoptions[i].name << endl;
        cout << "\tClass: " << partyoptions[i].playerclass << endl;
        cout << "\tRace: " << partyoptions[i].race << endl;
        cout << "\tAlignment: " << partyoptions[i].alignmentlaw << " " << partyoptions[i].alignmentmore << endl;
        cout << "\tWeapon: " << partyoptions[i].weapon << endl;
    }
    
    cout << "Choose your party! (Scroll up to see options)" << endl;
    int count = 0;
    while (count < 3) {
        cin >> foo;
        yeet << foo;
        yeet >> pick;
        yeet.str("");
        if (picked[pick-1]) cout << "You already picked them." << endl;
        else {
            party[count+1] = partyoptions[pick-1];
            picked[pick-1] = true;
            count++;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        party[i].alive = true;
        party[i].hitpoints = 50; //might change later depending on how hard it is to win
        party[i].kills = 0;
    }
}

void createMap() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            map[i][j] = 10*(i+1)+j+1;
        }
    }
}

void createMonsters() {
    weakmonster[0].name = "goblin";
    weakmonster[0].hitpoints = 10;
    weakmonster[0].damage = 2;
    
    weakmonster[1].name = "crawling hand";
    weakmonster[1].hitpoints = 5;
    weakmonster[1].damage = 1;
    
    weakmonster[2].name = "small skeleton";
    weakmonster[2].hitpoints = 12;
    weakmonster[2].damage = 3;
    
    weakmonster[3].name = "cranium rat";
    weakmonster[3].hitpoints = 2;
    weakmonster[3].damage = 1;
    
    weakmonster[4].name = "dire rat";
    weakmonster[4].hitpoints = 4;
    weakmonster[4].damage = 1;
    
    weakmonster[5].name = "shrieker";
    weakmonster[5].hitpoints = 5;
    weakmonster[5].damage = 0;
    
    weakmonster[6].name = "jackel";
    weakmonster[6].hitpoints = 15;
    weakmonster[6].damage = 3;
    
    weakmonster[7].name = "floating eye";
    weakmonster[7].hitpoints = 6;
    weakmonster[7].damage = 1;
    
    weakmonster[8].name = "manes";
    weakmonster[8].hitpoints = 4;
    weakmonster[8].damage = 3;
    
    weakmonster[9].name = "spider";
    weakmonster[9].hitpoints = 3;
    weakmonster[9].damage = 2;
    
    weakmonster[10].name = "bat";
    weakmonster[10].hitpoints = 5;
    weakmonster[10].damage = 3;
    
    weakmonster[11].name = "stalker";
    weakmonster[11].hitpoints = 12;
    weakmonster[11].damage = 0;
    
    weakmonster[12].name = "lichen";
    weakmonster[12].hitpoints = 5;
    weakmonster[12].damage = 1;
    
    weakmonster[13].name = "snake";
    weakmonster[13].hitpoints = 6;
    weakmonster[13].damage = 3;
    
    weakmonster[14].name = "lizard";
    weakmonster[14].hitpoints = 4;
    weakmonster[14].damage = 1;
    
    weakmonster[15].name = "fox";
    weakmonster[15].hitpoints = 15;
    weakmonster[15].damage = 5;
    
    mediummonster[0].name = "rothe";
    mediummonster[0].hitpoints = 20;
    mediummonster[0].damage = 12;
    
    mediummonster[1].name = "rabid rat";
    mediummonster[1].hitpoints = 10;
    mediummonster[1].damage = 8;
    
    mediummonster[2].name = "giant spider";
    mediummonster[2].hitpoints = 15;
    mediummonster[2].damage = 5;
    
    mediummonster[3].name = "dust vortex";
    mediummonster[3].hitpoints = 10;
    mediummonster[3].damage = 8;
    
    mediummonster[4].name = "giant bat";
    mediummonster[4].hitpoints = 12;
    mediummonster[4].damage = 5;
    
    mediummonster[5].name = "giant";
    mediummonster[5].hitpoints = 24;
    mediummonster[5].damage = 10;
    
    mediummonster[6].name = "lich";
    mediummonster[6].hitpoints = 24;
    mediummonster[6].damage = 10;
    
    mediummonster[7].name = "mummy";
    mediummonster[7].hitpoints = 18;
    mediummonster[7].damage = 8;
    
    mediummonster[8].name = "ooze";
    mediummonster[8].hitpoints = 20;
    mediummonster[8].damage = 3;
    
    mediummonster[9].name = "giant snake";
    mediummonster[9].hitpoints = 16;
    mediummonster[9].damage = 5;
    
    mediummonster[10].name = "owlbear";
    mediummonster[10].hitpoints = 24;
    mediummonster[10].damage = 6;
    
    mediummonster[11].name = "zombie";
    mediummonster[11].hitpoints = 18;
    mediummonster[11].damage = 5;
    
    strongmonster[0].name = "dragon";
    strongmonster[0].hitpoints = 50;
    strongmonster[0].damage = 20;
    
    strongmonster[1].name = "baby dragon";
    strongmonster[1].hitpoints = 30;
    strongmonster[1].damage = 15;
    
    strongmonster[2].name = "gelatinous cube";
    strongmonster[2].hitpoints = 50;
    strongmonster[2].damage = 25;
    
    strongmonster[3].name = "troll";
    strongmonster[3].hitpoints = 40;
    strongmonster[3].damage = 20;
    
    strongmonster[4].name = "vampire";
    strongmonster[4].hitpoints = 35;
    strongmonster[4].damage = 15;
    
    for (int i = 0; i < 16; i++) {
        weakmonster[i].alive = true;
    }
    for (int i = 0; i < 12; i++) {
        mediummonster[i].alive = true;
    }
    for (int i = 0; i < 5; i++) {
        strongmonster[i].alive = true;
    }
    
    boss.hitpoints = 100;
    boss.damage = 30;
    boss.alive = true;
}

void combat(char type, int select) {
    srand(time(NULL));
    int target;
    bool hit = false;
    switch (type) {
        case 'w':
            while (weakmonster[select].alive && (party[0].alive || party[1].alive || party[2].alive || party[3].alive)) {
                for (int i = 0; i < 4; i++) {
                    if (party[i].alive && weakmonster[select].alive) {
                        cout << party[i].name << " hits the " << weakmonster[select].name << "!" << endl;
                        weakmonster[select].hitpoints -= party[i].kills;
                    }
                    if (weakmonster[select].hitpoints < 1) {
                        cout << "The " << weakmonster[select].name << " has been killed!" << endl;
                        weakmonster[select].alive = false;
                    }
                }
                if (weakmonster[select].alive) {
                    while (!hit) {
                        target = rand() % 4;
                        if (party[target].alive) {
                            hit = true;
                            cout << "The " << weakmonster[select].name << " hits " << party[target].name << "!" << endl;
                            party[target].hitpoints -= weakmonster[select].damage;
                            if (party[target].hitpoints < 1) {
                                cout << party[target].name << " has been killed!" << endl;
                                party[target].alive = false;
                            }
                        }
                    }
                }
                for (int i = 0; i < 4; i++) {
                    if (party[i].alive) party[i].hitpoints++;
                }
            }
            break;
        case 'm':
            while (mediummonster[select].alive && (party[0].alive || party[1].alive || party[2].alive || party[3].alive)) {
                for (int i = 0; i < 4; i++) {
                    if (party[i].alive && mediummonster[select].alive) {
                        cout << party[i].name << " hits the " << mediummonster[select].name << "!" << endl;
                        mediummonster[select].hitpoints -= party[i].kills;
                    }
                    if (mediummonster[select].hitpoints < 1) {
                        cout << "The " << mediummonster[select].name << " has been killed!" << endl;
                        mediummonster[select].alive = false;
                    }
                }
                if (mediummonster[select].alive) {
                    while (!hit) {
                        target = rand() % 4;
                        if (party[target].alive) {
                            hit = true;
                            cout << "The " << mediummonster[select].name << " hits " << party[target].name << "!" << endl;
                            party[target].hitpoints -= mediummonster[select].damage;
                            if (party[target].hitpoints < 1) {
                                cout << party[target].name << " has been killed!" << endl;
                                party[target].alive = false;
                            }
                        }
                    }
                }
                for (int i = 0; i < 4; i++) {
                    if (party[i].alive) party[i].hitpoints++;
                }
            }
            break;
        case 's':
            while (strongmonster[select].alive && (party[0].alive || party[1].alive || party[2].alive || party[3].alive)) {
                for (int i = 0; i < 4; i++) {
                    if (party[i].alive && strongmonster[select].alive) {
                        cout << party[i].name << " hits the " << strongmonster[select].name << "!" << endl;
                        strongmonster[select].hitpoints -= party[i].kills;
                    }
                    if (strongmonster[select].hitpoints < 1) {
                        cout << "The " << strongmonster[select].name << " has been killed!" << endl;
                        strongmonster[select].alive = false;
                    }
                }
                if (strongmonster[select].alive) {
                    while (!hit) {
                        target = rand() % 4;
                        if (party[target].alive) {
                            hit = true;
                            cout << "The " << strongmonster[select].name << " hits " << party[target].name << "!" << endl;
                            party[target].hitpoints -= strongmonster[select].damage;
                            if (party[target].hitpoints < 1) {
                                cout << party[target].name << " has been killed!" << endl;
                                party[target].alive = false;
                            }
                        }
                    }
                }
                for (int i = 0; i < 4; i++) {
                    if (party[i].alive) party[i].hitpoints++;
                }
            }
            break;
        default:
            break;
    }
    for (int i = 0; i < 4; i++) {
        if (party[i].alive) party[i].kills++;
    }
}

void bossFight() {
    srand(time(NULL));
    int target;
    bool hit = false;
    while (boss.alive && (party[0].alive || party[1].alive || party[2].alive || party[3].alive)) {
        for (int i = 0; i < 4; i++) {
            if (party[i].alive && boss.alive) {
                cout << party[i].name << " hits " << boss.name << "!" << endl;
                boss.hitpoints -= party[i].kills;
            }
            if (boss.hitpoints < 1) {
                cout << boss.name << " has been killed!" << endl;
                boss.alive = false;
            }
        }
        if (boss.alive) {
            while (!hit) {
                target = rand() % 4;
                if (party[target].alive) {
                    hit = true;
                    cout << boss.name << " hits " << party[target].name << "!" << endl;
                    party[target].hitpoints -= boss.damage;
                    if (party[target].hitpoints < 1) {
                        cout << party[target].name << " has been killed!" << endl;
                        party[target].alive = false;
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            if (party[i].alive) party[i].hitpoints++;
        }
    }
    play = false;
}


/*
 * HERE HE IS
 * THE MAIN BOI
 * GOD HE'S BIG
 * AND COMPLICATED
 */

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    stringstream scree;
    string foo;
    int direction, temp, dieroll;
    createParty();
    createMap();
    cout << "Your Party" << endl;
    for (int i = 0; i < 4; i++) {
        cout << endl << "Name: " << party[i].name << " (" << party[i].pronoun << ")" << endl;
        cout << "Class: " << party[i].playerclass << endl;
        cout << "Race: " << party[i].race << endl;
        cout << "Alignment: " << party[i].alignmentlaw << " " << party[i].alignmentmore << endl;
        cout << "Weapon: " << party[i].weapon << endl;
    }
    
    while (play) {
        switch (currentPosition / 10) {
            case 1:
                switch (currentPosition % 10) {
                    case 1:
                        cout << "You and your party stand before a dense forest. There's a few small gaps through which you can enter. Which one do you choose?" << endl << "1) Left\n2) Center\n3) Right" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                currentPosition += 1;
                                break;
                            case 2:
                                currentPosition += 11;
                                break;
                            case 3:
                                currentPosition += 10;
                                break;
                            default:
                                cout << "Try again, loser" << endl;
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 2:
                        dieroll = rand() % 16;
                        cout << "You enter a clearing with a " << weakmonster[dieroll].name << "!" << endl;
                        combat('w', dieroll);
                        cout << "There's ";
                        if (lastPosition == 11) cout << "3 paths in front of you. Which one do you choose?" << endl << "1) Left\n2) Center\n3) Right" << endl;
                        else cout << "2 paths in front of you. Which one do you choose?" << endl << "1) Left\n2) Right\n3) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 11) currentPosition += 1;
                                else if (lastPosition == 21) currentPosition += 1;
                                else if (lastPosition == 22) currentPosition += 9;
                                else currentPosition += 10;
                                break;
                            case 2:
                                if (lastPosition == 11) currentPosition += 10;
                                else if (lastPosition == 21) currentPosition += 10;
                                else if (lastPosition == 22) currentPosition += 1;
                                else currentPosition += 9;
                                break;
                            case 3:
                                if (lastPosition == 11) currentPosition += 9;
                                else currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 3:
                        cout << "There's nothing here, but there are 3 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Center\n3) Right\n4) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 12) currentPosition += 1;
                                else if (lastPosition == 22) currentPosition -= 1;
                                else if (lastPosition == 14) currentPosition += 11;
                                else currentPosition += 9;
                                break;
                            case 2:
                                if (lastPosition == 12) currentPosition += 11;
                                else if (lastPosition == 22) currentPosition += 1;
                                else if (lastPosition == 14) currentPosition += 9;
                                else currentPosition -= 1;
                                break;
                            case 3:
                                if (lastPosition == 12) currentPosition += 9;
                                else if (lastPosition == 22) currentPosition += 11;
                                else if (lastPosition == 14) currentPosition -= 1;
                                else currentPosition += 1;
                                break;
                            case 4:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 4:
                        cout << "You feel a wrenching sensation." << endl;
                        dieroll = rand() % 4;
                        temp = currentPosition;
                        switch (dieroll) {
                            case 0:
                                currentPosition -= 1;
                                break;
                            case 1:
                                currentPosition += 1;
                                break;
                            case 2:
                                currentPosition += 10;
                                break;
                            case 3:
                                currentPosition += 11;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 5:
                        cout << "There's nothing here, but there are 4 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Center\n3) Right Center\n4) Right\n5) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 14) currentPosition += 1;
                                else if (lastPosition == 24) currentPosition -= 1;
                                else if (lastPosition == 25) currentPosition += 9;
                                else if (lastPosition == 26) currentPosition += 10;
                                else currentPosition += 11;
                                break;
                            case 2:
                                if (lastPosition == 14) currentPosition += 11;
                                else if (lastPosition == 24) currentPosition += 1;
                                else if (lastPosition == 25) currentPosition -= 1;
                                else if (lastPosition == 26) currentPosition += 9;
                                else currentPosition += 10;
                                break;
                            case 3:
                                if (lastPosition == 14) currentPosition += 10;
                                else if (lastPosition == 24) currentPosition += 11;
                                else if (lastPosition == 25) currentPosition += 1;
                                else if (lastPosition == 26) currentPosition -= 1;
                                else currentPosition += 9;
                                break;
                            case 4:
                                if (lastPosition == 14) currentPosition += 9;
                                else if (lastPosition == 24) currentPosition += 10;
                                else if (lastPosition == 25) currentPosition += 11;
                                else if (lastPosition == 26) currentPosition += 1;
                                else currentPosition += -1;
                                break;
                            case 5:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 6:
                        cout << "You enter a clearing with a lich!" << endl;
                        combat('m', 6);
                        
                        cout << "There are 4 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Center\n3) Right Center\n4) Right\n5) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 15) currentPosition += 1;
                                else if (lastPosition == 25) currentPosition -= 1;
                                else if (lastPosition == 26) currentPosition += 9;
                                else if (lastPosition == 27) currentPosition += 10;
                                else currentPosition += 11;
                                break;
                            case 2:
                                if (lastPosition == 15) currentPosition += 11;
                                else if (lastPosition == 25) currentPosition += 1;
                                else if (lastPosition == 26) currentPosition -= 1;
                                else if (lastPosition == 27) currentPosition += 9;
                                else currentPosition += 10;
                                break;
                            case 3:
                                if (lastPosition == 15) currentPosition += 10;
                                else if (lastPosition == 25) currentPosition += 11;
                                else if (lastPosition == 26) currentPosition += 1;
                                else if (lastPosition == 27) currentPosition -= 1;
                                else currentPosition += 9;
                                break;
                            case 4:
                                if (lastPosition == 15) currentPosition += 9;
                                else if (lastPosition == 25) currentPosition += 10;
                                else if (lastPosition == 26) currentPosition += 11;
                                else if (lastPosition == 27) currentPosition += 1;
                                else currentPosition -= 1;
                                break;
                            case 5:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 7:
                        cout << "You enter a clearing with a giant spider!" << endl;
                        combat('m', 2);
                        
                        cout << "There are 2 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Right\n3) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 15) currentPosition += 10;
                                else if (lastPosition == 25) currentPosition -= 1;
                                else currentPosition += 9;
                                break;
                            case 2:
                                if (lastPosition == 15) currentPosition += 9;
                                else if (lastPosition == 25) currentPosition += 10;
                                else currentPosition -= 1;
                                break;
                            case 3:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    default:
                        cout << "Ah heck. You've exited the map. Goodbye." << endl;
                        play = false;
                        break;
                }
                break;
            case 2:
                switch (currentPosition % 10) {
                    case 1:
                        dieroll = rand() % 16;
                        cout << "You enter a clearing with a " << weakmonster[dieroll].name << "!" << endl;
                        combat('w', dieroll);
                        cout << "There's ";
                        if (lastPosition == 11) cout << "3 paths in front of you. Which one do you choose?" << endl << "1) Left\n2) Center\n3) Right" << endl;
                        else cout << "2 paths in front of you. Which one do you choose?" << endl << "1) Left\n2) Right\n3) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 11) currentPosition -= 9;
                                else if (lastPosition == 12) currentPosition += 1;
                                else if (lastPosition == 22) currentPosition += 10;
                                else currentPosition -= 9;
                                break;
                            case 2:
                                if (lastPosition == 11) currentPosition += 1;
                                else if (lastPosition == 12) currentPosition += 10;
                                else if (lastPosition == 22) currentPosition -= 9;
                                else currentPosition += 1;
                                break;
                            case 3:
                                if (lastPosition == 11) currentPosition += 10;
                                else currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 2:
                        dieroll = rand() % 16;
                        cout << "You enter a clearing with a " << weakmonster[dieroll].name << "!" << endl;
                        combat('w', dieroll);
                        cout << "There's ";
                        if (lastPosition == 11) cout << "5 paths in front of you. Which one do you choose?" << endl << "1) Left\n2) Left Center\n3) Center\n4) Right Center\n5) Right" << endl;
                        else cout << "4 paths in front of you. Which one do you choose?" << endl << "1) Left\n2) Left Center\n3) Right Center\n4) Right\n5) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 11) currentPosition -= 10;
                                else if (lastPosition == 12) currentPosition -= 9;
                                else if (lastPosition == 13) currentPosition += 11;
                                else if (lastPosition == 33) currentPosition += 9;
                                else if (lastPosition == 31) currentPosition -= 1;
                                else currentPosition -= 10;
                                break;
                            case 2:
                                if (lastPosition == 11) currentPosition -= 9;
                                else if (lastPosition == 12) currentPosition += 11;
                                else if (lastPosition == 13) currentPosition += 9;
                                else if (lastPosition == 33) currentPosition -= 1;
                                else if (lastPosition == 31) currentPosition -= 10;
                                else currentPosition -= 9;
                                break;
                            case 3:
                                if (lastPosition == 11) currentPosition += 11;
                                else if (lastPosition == 12) currentPosition += 9;
                                else if (lastPosition == 13) currentPosition -= 1;
                                else if (lastPosition == 33) currentPosition -= 10;
                                else if (lastPosition == 31) currentPosition -= 9;
                                else currentPosition += 11;
                                break;
                            case 4:
                                if (lastPosition == 11) currentPosition += 9;
                                else if (lastPosition == 12) currentPosition -= 1;
                                else if (lastPosition == 13) currentPosition -= 10;
                                else if (lastPosition == 33) currentPosition -= 9;
                                else if (lastPosition == 31) currentPosition += 11;
                                else currentPosition += 9;
                                break;
                            case 5:
                                if (lastPosition == 11) currentPosition -= 1;
                                else currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 3:
                        cout << "You've clipped into a tree. You and your entire party die" << endl;
                        play = false;
                        break;
                    case 4:
                        cout << "You enter a clearing with a jackel!" << endl;
                        combat('w', 6);
                        
                        cout << "There are 6 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Left Center\n3) Left Center\n4) Right Center\n5) Right Right Center\n6) Right\n7) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 13) currentPosition -= 10;
                                else if (lastPosition == 14) currentPosition -= 9;
                                else if (lastPosition == 15) currentPosition += 1;
                                else if (lastPosition == 25) currentPosition += 11;
                                else if (lastPosition == 35) currentPosition += 10;
                                else if (lastPosition == 34) currentPosition += 9;
                                else currentPosition -= 11;
                                break;
                            case 2:
                                if (lastPosition == 13) currentPosition -= 9;
                                else if (lastPosition == 14) currentPosition += 1;
                                else if (lastPosition == 15) currentPosition += 11;
                                else if (lastPosition == 25) currentPosition += 10;
                                else if (lastPosition == 35) currentPosition += 9;
                                else if (lastPosition == 34) currentPosition -= 11;
                                else currentPosition -= 10;
                                break;
                            case 3:
                                if (lastPosition == 13) currentPosition += 1;
                                else if (lastPosition == 14) currentPosition += 11;
                                else if (lastPosition == 15) currentPosition += 10;
                                else if (lastPosition == 25) currentPosition += 9;
                                else if (lastPosition == 35) currentPosition -= 11;
                                else if (lastPosition == 34) currentPosition -= 10;
                                else currentPosition -= 9;
                                break;
                            case 4:
                                if (lastPosition == 13) currentPosition += 11;
                                else if (lastPosition == 14) currentPosition += 10;
                                else if (lastPosition == 15) currentPosition += 9;
                                else if (lastPosition == 25) currentPosition -= 11;
                                else if (lastPosition == 35) currentPosition -= 10;
                                else if (lastPosition == 34) currentPosition -= 9;
                                else currentPosition += 1;
                                break;
                            case 5:
                                if (lastPosition == 13) currentPosition += 10;
                                else if (lastPosition == 14) currentPosition += 9;
                                else if (lastPosition == 15) currentPosition -= 11;
                                else if (lastPosition == 25) currentPosition -= 10;
                                else if (lastPosition == 35) currentPosition -= 9;
                                else if (lastPosition == 34) currentPosition += 1;
                                else currentPosition += 11;
                                break;
                            case 6:
                                if (lastPosition == 13) currentPosition += 9;
                                else if (lastPosition == 14) currentPosition -= 11;
                                else if (lastPosition == 15) currentPosition -= 10;
                                else if (lastPosition == 25) currentPosition -= 9;
                                else if (lastPosition == 35) currentPosition += 1;
                                else if (lastPosition == 34) currentPosition += 11;
                                else currentPosition += 10;
                                break;
                            case 7:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 5:
                        cout << "You step into a clearing covered in bones. They crack under your feet." << endl;
                        dieroll = rand() % 5;
                        if (dieroll < 3) {
                            dieroll = rand() % 12;
                            cout << "A " << mediummonster[dieroll].name << " emerges from the woods!" << endl;
                            combat('m', dieroll);
                        }
                        else cout << "Luckily no monsters seem to be nearby." << endl;
                        cout << "There are 6 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Left Center\n3) Left Center\n4) Right Center\n5) Right Right Center\n6) Right\n7) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 26) currentPosition += 10;
                                else if (lastPosition == 16) currentPosition += 1;
                                else if (lastPosition == 15) currentPosition -= 9;
                                else if (lastPosition == 14) currentPosition -= 10;
                                else if (lastPosition == 24) currentPosition -= 11;
                                else if (lastPosition == 34) currentPosition -= 1;
                                else currentPosition += 9;
                                break;
                            case 2:
                                if (lastPosition == 26) currentPosition += 9;
                                else if (lastPosition == 16) currentPosition += 10;
                                else if (lastPosition == 15) currentPosition += 1;
                                else if (lastPosition == 14) currentPosition -= 9;
                                else if (lastPosition == 24) currentPosition -= 10;
                                else if (lastPosition == 34) currentPosition -= 11;
                                else currentPosition -= 1;
                                break;
                            case 3:
                                if (lastPosition == 26) currentPosition -= 1;
                                else if (lastPosition == 16) currentPosition += 9;
                                else if (lastPosition == 15) currentPosition += 10;
                                else if (lastPosition == 14) currentPosition += 1;
                                else if (lastPosition == 24) currentPosition -= 9;
                                else if (lastPosition == 34) currentPosition -= 10;
                                else currentPosition -= 11;
                                break;
                            case 4:
                                if (lastPosition == 26) currentPosition -= 11;
                                else if (lastPosition == 16) currentPosition -= 1;
                                else if (lastPosition == 15) currentPosition += 9;
                                else if (lastPosition == 14) currentPosition += 10;
                                else if (lastPosition == 24) currentPosition += 1;
                                else if (lastPosition == 34) currentPosition -= 9;
                                else currentPosition -= 10;
                                break;
                            case 5:
                                if (lastPosition == 26) currentPosition -= 10;
                                else if (lastPosition == 16) currentPosition -= 11;
                                else if (lastPosition == 15) currentPosition -= 1;
                                else if (lastPosition == 14) currentPosition += 9;
                                else if (lastPosition == 24) currentPosition += 10;
                                else if (lastPosition == 34) currentPosition += 1;
                                else currentPosition -= 9;
                                break;
                            case 6:
                                if (lastPosition == 26) currentPosition -= 9;
                                else if (lastPosition == 16) currentPosition -= 10;
                                else if (lastPosition == 15) currentPosition -= 11;
                                else if (lastPosition == 14) currentPosition -= 1;
                                else if (lastPosition == 24) currentPosition += 9;
                                else if (lastPosition == 34) currentPosition += 10;
                                else currentPosition += 1;
                                break;
                            case 7:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 6:
                        cout << "You enter a clearing with a giant snake!" << endl;
                        combat('m', 9);
                        
                        cout << "There are 6 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Left Center\n3) Left Center\n4) Right Center\n5) Right Right Center\n6) Right\n7) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 35) currentPosition -= 1;
                                else if (lastPosition == 25) currentPosition -= 11;
                                else if (lastPosition == 15) currentPosition -= 10;
                                else if (lastPosition == 16) currentPosition -= 9;
                                else if (lastPosition == 17) currentPosition += 1;
                                else if (lastPosition == 27) currentPosition += 11;
                                else currentPosition += 9;
                                break;
                            case 2:
                                if (lastPosition == 35) currentPosition -= 11;
                                else if (lastPosition == 25) currentPosition -= 10;
                                else if (lastPosition == 15) currentPosition -= 9;
                                else if (lastPosition == 16) currentPosition += 1;
                                else if (lastPosition == 17) currentPosition += 11;
                                else if (lastPosition == 27) currentPosition += 9;
                                else currentPosition -= 1;
                                break;
                            case 3:
                                if (lastPosition == 35) currentPosition -= 10;
                                else if (lastPosition == 25) currentPosition -= 9;
                                else if (lastPosition == 15) currentPosition += 1;
                                else if (lastPosition == 16) currentPosition += 11;
                                else if (lastPosition == 17) currentPosition += 9;
                                else if (lastPosition == 27) currentPosition -= 1;
                                else currentPosition -= 11;
                                break;
                            case 4:
                                if (lastPosition == 35) currentPosition -= 9;
                                else if (lastPosition == 25) currentPosition += 1;
                                else if (lastPosition == 15) currentPosition += 11;
                                else if (lastPosition == 16) currentPosition += 9;
                                else if (lastPosition == 17) currentPosition -= 1;
                                else if (lastPosition == 27) currentPosition -= 11;
                                else currentPosition -= 10;
                                break;
                            case 5:
                                if (lastPosition == 35) currentPosition += 1;
                                else if (lastPosition == 25) currentPosition += 11;
                                else if (lastPosition == 15) currentPosition += 9;
                                else if (lastPosition == 16) currentPosition -= 1;
                                else if (lastPosition == 17) currentPosition -= 11;
                                else if (lastPosition == 27) currentPosition -= 10;
                                else currentPosition -= 9;
                                break;
                            case 6:
                                if (lastPosition == 35) currentPosition += 11;
                                else if (lastPosition == 25) currentPosition += 9;
                                else if (lastPosition == 15) currentPosition -= 1;
                                else if (lastPosition == 16) currentPosition -= 11;
                                else if (lastPosition == 17) currentPosition -= 10;
                                else if (lastPosition == 27) currentPosition -= 9;
                                else currentPosition += 1;
                                break;
                            case 7:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 7:
                        cout << "There's nothing here, but there are 3 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Center\n3) Right\n4) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 16) currentPosition -= 10;
                                else if (lastPosition == 17) currentPosition += 10;
                                else if (lastPosition == 26) currentPosition -= 11;
                                else currentPosition -= 1;
                                break;
                            case 2:
                                if (lastPosition == 16) currentPosition += 10;
                                else if (lastPosition == 17) currentPosition -= 1;
                                else if (lastPosition == 26) currentPosition -= 10;
                                else currentPosition -= 11;
                                break;
                            case 3:
                                if (lastPosition == 16) currentPosition -= 1;
                                else if (lastPosition == 17) currentPosition -= 11;
                                else if (lastPosition == 26) currentPosition += 10;
                                else currentPosition -= 10;
                                break;
                            case 4:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    default:
                        cout << "Ah heck. You've exited the map. Goodbye." << endl;
                        play = false;
                        break;
                }
                break;
            case 3:
                switch (currentPosition % 10) {
                    case 1:
                        cout << "You enter a clearing with a lichen!" << endl;
                        combat('w', 12);
                        
                        cout << "There are 3 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Center\n3) Right\n4) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 21) currentPosition -= 9;
                                else if (lastPosition == 22) currentPosition += 11;
                                else if (lastPosition == 42) currentPosition += 10;
                                else currentPosition -= 10;
                                break;
                            case 2:
                                if (lastPosition == 21) currentPosition += 11;
                                else if (lastPosition == 22) currentPosition += 10;
                                else if (lastPosition == 42) currentPosition -= 10;
                                else currentPosition -= 9;
                                break;
                            case 3:
                                if (lastPosition == 21) currentPosition += 10;
                                else if (lastPosition == 22) currentPosition -= 10;
                                else if (lastPosition == 42) currentPosition -= 9;
                                else currentPosition += 11;
                                break;
                            case 4:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 2:
                        cout << "You've clipped into a tree. You and your entire party die" << endl;
                        play = false;
                        break;
                    case 3:
                        cout << "You enter a clearing with a dire rat!" << endl;
                        combat('w', 4);
                        
                        cout << "There are 5 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Center\n3) Center\n4) Right Center\n5) Right\n6) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 22) currentPosition -= 9;
                                else if (lastPosition == 24) currentPosition += 1;
                                else if (lastPosition == 34) currentPosition += 11;
                                else if (lastPosition == 43) currentPosition += 9;
                                else if (lastPosition == 42) currentPosition -= 11;
                                break;
                            case 2:
                                if (lastPosition == 22) currentPosition += 1;
                                else if (lastPosition == 24) currentPosition += 11;
                                else if (lastPosition == 34) currentPosition += 10;
                                else if (lastPosition == 43) currentPosition -= 11;
                                else if (lastPosition == 42) currentPosition -= 9;
                                break;
                            case 3:
                                if (lastPosition == 22) currentPosition += 11;
                                else if (lastPosition == 24) currentPosition += 10;
                                else if (lastPosition == 34) currentPosition += 9;
                                else if (lastPosition == 43) currentPosition -= 9;
                                else if (lastPosition == 42) currentPosition += 1;
                                break;
                            case 4:
                                if (lastPosition == 22) currentPosition += 10;
                                else if (lastPosition == 24) currentPosition += 9;
                                else if (lastPosition == 34) currentPosition -= 11;
                                else if (lastPosition == 43) currentPosition += 1;
                                else if (lastPosition == 42) currentPosition += 11;
                                break;
                            case 5:
                                if (lastPosition == 22) currentPosition += 9;
                                else if (lastPosition == 24) currentPosition -= 11;
                                else if (lastPosition == 34) currentPosition -= 9;
                                else if (lastPosition == 43) currentPosition += 11;
                                else if (lastPosition == 42) currentPosition += 10;
                                break;
                            case 6:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 4:
                        cout << "You enter a clearing with a giant!" << endl;
                        combat('m', 5);
                        
                        cout << "There are 6 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Left Center\n3) Left Center\n4) Right Center\n5) Right Right Center\n6) Right\n7) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 24) currentPosition -= 9;
                                else if (lastPosition == 25) currentPosition += 1;
                                else if (lastPosition == 35) currentPosition += 11;
                                else if (lastPosition == 45) currentPosition += 10;
                                else if (lastPosition == 43) currentPosition -= 1;
                                else currentPosition -= 10;
                                break;
                            case 2:
                                if (lastPosition == 24) currentPosition += 1;
                                else if (lastPosition == 25) currentPosition += 11;
                                else if (lastPosition == 35) currentPosition += 10;
                                else if (lastPosition == 45) currentPosition += 9;
                                else if (lastPosition == 43) currentPosition -= 10;
                                else currentPosition -= 9;
                                break;
                            case 3:
                                if (lastPosition == 24) currentPosition += 11;
                                else if (lastPosition == 25) currentPosition += 10;
                                else if (lastPosition == 35) currentPosition += 9;
                                else if (lastPosition == 45) currentPosition -= 1;
                                else if (lastPosition == 43) currentPosition -= 9;
                                else currentPosition += 1;
                                break;
                            case 4:
                                if (lastPosition == 24) currentPosition += 10;
                                else if (lastPosition == 25) currentPosition += 9;
                                else if (lastPosition == 35) currentPosition -= 1;
                                else if (lastPosition == 45) currentPosition -= 10;
                                else if (lastPosition == 43) currentPosition += 1;
                                else currentPosition += 11;
                                break;
                            case 5:
                                if (lastPosition == 24) currentPosition += 9;
                                else if (lastPosition == 25) currentPosition -= 1;
                                else if (lastPosition == 35) currentPosition -= 10;
                                else if (lastPosition == 45) currentPosition -= 9;
                                else if (lastPosition == 43) currentPosition += 11;
                                else currentPosition += 10;
                                break;
                            case 6:
                                if (lastPosition == 24) currentPosition -= 1;
                                else if (lastPosition == 25) currentPosition -= 10;
                                else if (lastPosition == 35) currentPosition -= 9;
                                else if (lastPosition == 45) currentPosition += 1;
                                else if (lastPosition == 43) currentPosition += 10;
                                else currentPosition += 9;
                                break;
                            case 7:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 5:
                        cout << "You enter a clearing with a vampire!" << endl;
                        combat('s', 4);
                        
                        cout << "There are 6 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Left Center\n3) Left Center\n4) Right Center\n5) Right Right Center\n6) Right\n7) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 26) currentPosition += 11;
                                else if (lastPosition == 25) currentPosition -= 9;
                                else if (lastPosition == 24) currentPosition -= 10;
                                else if (lastPosition == 34) currentPosition -= 11;
                                else if (lastPosition == 45) currentPosition += 9;
                                else currentPosition += 10;
                                break;
                            case 2:
                                if (lastPosition == 26) currentPosition += 10;
                                else if (lastPosition == 25) currentPosition += 11;
                                else if (lastPosition == 24) currentPosition -= 9;
                                else if (lastPosition == 34) currentPosition -= 10;
                                else if (lastPosition == 45) currentPosition -= 1;
                                else currentPosition += 9;
                                break;
                            case 3:
                                if (lastPosition == 26) currentPosition += 9;
                                else if (lastPosition == 25) currentPosition += 10;
                                else if (lastPosition == 24) currentPosition += 11;
                                else if (lastPosition == 34) currentPosition -= 9;
                                else if (lastPosition == 45) currentPosition -= 11;
                                else currentPosition -= 1;
                                break;
                            case 4:
                                if (lastPosition == 26) currentPosition -= 1;
                                else if (lastPosition == 25) currentPosition += 9;
                                else if (lastPosition == 24) currentPosition += 10;
                                else if (lastPosition == 34) currentPosition += 11;
                                else if (lastPosition == 45) currentPosition -= 10;
                                else currentPosition -= 11;
                                break;
                            case 5:
                                if (lastPosition == 26) currentPosition -= 11;
                                else if (lastPosition == 25) currentPosition -= 1;
                                else if (lastPosition == 24) currentPosition += 9;
                                else if (lastPosition == 34) currentPosition += 10;
                                else if (lastPosition == 45) currentPosition -= 9;
                                else currentPosition -= 10;
                                break;
                            case 6:
                                if (lastPosition == 26) currentPosition -= 10;
                                else if (lastPosition == 25) currentPosition -= 11;
                                else if (lastPosition == 24) currentPosition -= 1;
                                else if (lastPosition == 34) currentPosition += 9;
                                else if (lastPosition == 45) currentPosition += 11;
                                else currentPosition -= 9;
                                break;
                            case 7:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 6:
                        cout << "You've clipped into a tree. You and your entire party die" << endl;
                        play = false;
                        break;
                    case 7:
                        cout << "You enter a clearing with a zombie!" << endl;
                        combat('m', 11);
                        
                        cout << "There are 3 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Center\n3) Right\n4) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 26) currentPosition -= 10;
                                else if (lastPosition == 27) currentPosition += 10;
                                else if (lastPosition == 47) currentPosition += 9;
                                else currentPosition -= 11;
                                break;
                            case 2:
                                if (lastPosition == 26) currentPosition += 10;
                                else if (lastPosition == 27) currentPosition += 9;
                                else if (lastPosition == 47) currentPosition -= 11;
                                else currentPosition -= 10;
                                break;
                            case 3:
                                if (lastPosition == 26) currentPosition += 9;
                                else if (lastPosition == 27) currentPosition -= 11;
                                else if (lastPosition == 47) currentPosition -= 10;
                                else currentPosition += 10;
                                break;
                            case 4:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    default:
                        cout << "Ah heck. You've exited the map. Goodbye." << endl;
                        play = false;
                        break;
                }
                break;
            case 4:
                switch (currentPosition % 10) {
                    case 1:
                        cout << "You enter a clearing with a snake!" << endl;
                        combat('w', 13);
                        
                        cout << "There are 2 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Right\n3) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 31) currentPosition += 1;
                                else if (lastPosition == 42) currentPosition += 11;
                                else currentPosition -= 10;
                                break;
                            case 2:
                                if (lastPosition == 31) currentPosition += 11;
                                else if (lastPosition == 42) currentPosition -= 10;
                                else currentPosition += 1;
                                break;
                            case 3:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 2:
                        cout << "There's nothing here, but there are 5 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Center\n3) Center\n4) Right Center\n5) Right\n6) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 31) currentPosition -= 9;
                                else if (lastPosition == 33) currentPosition += 1;
                                else if (lastPosition == 41) currentPosition -= 11;
                                else if (lastPosition == 43) currentPosition += 11;
                                else if (lastPosition == 52) currentPosition -= 1;
                                else currentPosition += 10;
                                break;
                            case 2:
                                if (lastPosition == 31) currentPosition += 1;
                                else if (lastPosition == 33) currentPosition += 11;
                                else if (lastPosition == 41) currentPosition -= 9;
                                else if (lastPosition == 43) currentPosition += 10;
                                else if (lastPosition == 52) currentPosition -= 11;
                                else currentPosition -= 1;
                                break;
                            case 3:
                                if (lastPosition == 31) currentPosition += 11;
                                else if (lastPosition == 33) currentPosition += 10;
                                else if (lastPosition == 41) currentPosition += 1;
                                else if (lastPosition == 43) currentPosition -= 1;
                                else if (lastPosition == 52) currentPosition -= 9;
                                else currentPosition -= 11;
                                break;
                            case 4:
                                if (lastPosition == 31) currentPosition += 10;
                                else if (lastPosition == 33) currentPosition -= 1;
                                else if (lastPosition == 41) currentPosition += 11;
                                else if (lastPosition == 43) currentPosition -= 11;
                                else if (lastPosition == 52) currentPosition += 1;
                                else currentPosition -= 9;
                                break;
                            case 5:
                                if (lastPosition == 31) currentPosition -= 1;
                                else if (lastPosition == 33) currentPosition -= 11;
                                else if (lastPosition == 41) currentPosition += 10;
                                else if (lastPosition == 43) currentPosition -= 9;
                                else if (lastPosition == 52) currentPosition += 11;
                                else currentPosition += 1;
                                break;
                            case 6:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 3:
                        cout << "You enter a clearing with nothing in it except for a statue of a gargoyle. Its glittering black eyes stare into yours, as if it's alive inside. There are 5 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Left Center\n3) Left Center\n4) Right Center\n5) Right Right Center\n6) Right\n7) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 33) currentPosition -= 9;
                                else if (lastPosition == 34) currentPosition += 1;
                                else if (lastPosition == 42) currentPosition -= 10;
                                else if (lastPosition == 52) currentPosition -= 1;
                                else if (lastPosition == 53) currentPosition += 9;
                                else currentPosition += 10;
                                break;
                            case 2:
                                if (lastPosition == 33) currentPosition += 1;
                                else if (lastPosition == 34) currentPosition += 11;
                                else if (lastPosition == 42) currentPosition -= 9;
                                else if (lastPosition == 52) currentPosition -= 10;
                                else if (lastPosition == 53) currentPosition -= 1;
                                else currentPosition += 9;
                                break;
                            case 3:
                                if (lastPosition == 33) currentPosition += 11;
                                else if (lastPosition == 34) currentPosition += 10;
                                else if (lastPosition == 42) currentPosition += 1;
                                else if (lastPosition == 52) currentPosition -= 9;
                                else if (lastPosition == 53) currentPosition -= 10;
                                else currentPosition -= 1;
                                break;
                            case 4:
                                if (lastPosition == 33) currentPosition += 10;
                                else if (lastPosition == 34) currentPosition += 9;
                                else if (lastPosition == 42) currentPosition += 11;
                                else if (lastPosition == 52) currentPosition += 1;
                                else if (lastPosition == 53) currentPosition -= 9;
                                else currentPosition -= 10;
                                break;
                            case 5:
                                if (lastPosition == 33) currentPosition += 9;
                                else if (lastPosition == 34) currentPosition -= 1;
                                else if (lastPosition == 42) currentPosition += 10;
                                else if (lastPosition == 52) currentPosition += 11;
                                else if (lastPosition == 53) currentPosition += 1;
                                else currentPosition -= 9;
                                break;
                            case 6:
                                if (lastPosition == 33) currentPosition -= 1;
                                else if (lastPosition == 34) currentPosition -= 10;
                                else if (lastPosition == 42) currentPosition += 9;
                                else if (lastPosition == 52) currentPosition += 10;
                                else if (lastPosition == 53) currentPosition += 11;
                                else currentPosition += 1;
                                break;
                            case 7:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 4:
                        cout << "As you enter the clearing, you see a dark shadowy figure emerge. It is " << boss.name << "!" << endl;
                        bossFight();
                        break;
                    case 5:
                        cout << "There's nothing here, but there are 5 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Center\n3) Center\n4) Right Center\n5) Right\n6) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 34) currentPosition -= 10;
                                else if (lastPosition == 35) currentPosition += 1;
                                else if (lastPosition == 46) currentPosition += 11;
                                else if (lastPosition == 54) currentPosition -= 1;
                                else currentPosition += 9;
                                break;
                            case 2:
                                if (lastPosition == 34) currentPosition += 1;
                                else if (lastPosition == 35) currentPosition += 11;
                                else if (lastPosition == 46) currentPosition += 9;
                                else if (lastPosition == 54) currentPosition -= 11;
                                else currentPosition -= 1;
                                break;
                            case 3:
                                if (lastPosition == 34) currentPosition += 11;
                                else if (lastPosition == 35) currentPosition += 9;
                                else if (lastPosition == 46) currentPosition -= 1;
                                else if (lastPosition == 54) currentPosition -= 10;
                                else currentPosition -= 11;
                                break;
                            case 4:
                                if (lastPosition == 34) currentPosition += 9;
                                else if (lastPosition == 35) currentPosition -= 1;
                                else if (lastPosition == 46) currentPosition -= 11;
                                else if (lastPosition == 54) currentPosition += 1;
                                else currentPosition -= 10;
                                break;
                            case 5:
                                if (lastPosition == 34) currentPosition -= 1;
                                else if (lastPosition == 35) currentPosition -= 11;
                                else if (lastPosition == 46) currentPosition -= 10;
                                else if (lastPosition == 54) currentPosition += 11;
                                else currentPosition += 1;
                                break;
                            case 6:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 6:
                        cout << "You enter a clearing with a lizard!" << endl;
                        combat('w', 14);
                        
                        cout << "There are 5 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Center\n3) Center\n4) Right Center\n5) Right\n6) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 35) currentPosition -= 9;
                                else if (lastPosition == 45) currentPosition -= 11;
                                else if (lastPosition == 56) currentPosition -= 1;
                                else if (lastPosition == 57) currentPosition += 10;
                                else if (lastPosition == 47) currentPosition += 11;
                                else currentPosition += 1;
                                break;
                            case 2:
                                if (lastPosition == 35) currentPosition += 1;
                                else if (lastPosition == 45) currentPosition -= 9;
                                else if (lastPosition == 56) currentPosition -= 11;
                                else if (lastPosition == 57) currentPosition -= 1;
                                else if (lastPosition == 47) currentPosition += 10;
                                else currentPosition += 11;
                                break;
                            case 3:
                                if (lastPosition == 35) currentPosition += 11;
                                else if (lastPosition == 45) currentPosition += 1;
                                else if (lastPosition == 56) currentPosition -= 9;
                                else if (lastPosition == 57) currentPosition -= 11;
                                else if (lastPosition == 47) currentPosition -= 1;
                                else currentPosition += 10;
                                break;
                            case 4:
                                if (lastPosition == 35) currentPosition += 10;
                                else if (lastPosition == 45) currentPosition += 11;
                                else if (lastPosition == 56) currentPosition += 1;
                                else if (lastPosition == 57) currentPosition -= 9;
                                else if (lastPosition == 47) currentPosition -= 11;
                                else currentPosition -= 1;
                                break;
                            case 5:
                                if (lastPosition == 35) currentPosition -= 1;
                                else if (lastPosition == 45) currentPosition += 10;
                                else if (lastPosition == 56) currentPosition += 11;
                                else if (lastPosition == 57) currentPosition += 1;
                                else if (lastPosition == 47) currentPosition -= 9;
                                else currentPosition -= 11;
                                break;
                            case 6:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 7:
                        cout << "You enter the clearing and come face to face with a manes!" << endl;
                        combat('w', 8);
                        
                        cout << "There are 3 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Center\n3) Right\n4) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 37) currentPosition += 10;
                                else if (lastPosition == 46) currentPosition -= 10;
                                else if (lastPosition == 56) currentPosition -= 1;
                                else currentPosition += 9;
                                break;
                            case 2:
                                if (lastPosition == 37) currentPosition += 9;
                                else if (lastPosition == 46) currentPosition += 10;
                                else if (lastPosition == 56) currentPosition -= 10;
                                else currentPosition -= 1;
                                break;
                            case 3:
                                if (lastPosition == 37) currentPosition -= 1;
                                else if (lastPosition == 46) currentPosition += 9;
                                else if (lastPosition == 56) currentPosition += 10;
                                else currentPosition -= 10;
                                break;
                            case 4:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    default:
                        cout << "Ah heck. You've exited the map. Goodbye." << endl;
                        play = false;
                        break;
                }
                break;
            case 5:
                switch (currentPosition % 10) {
                    case 1:
                        cout << "You've clipped into a tree. You and your entire party die" << endl;
                        play = false;
                        break;
                    case 2:
                        cout << "You enter a clearing with an ooze!" << endl;
                        combat('m', 8);
                        
                        cout << "There are 6 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Left Center\n3) Left Center\n4) Right Center\n5) Right Right Center\n6) Right\n7) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 41) currentPosition -= 10;
                                else if (lastPosition == 42) currentPosition -= 9;
                                else if (lastPosition == 43) currentPosition += 1;
                                else if (lastPosition == 53) currentPosition += 11;
                                else if (lastPosition == 63) currentPosition += 10;
                                else if (lastPosition == 62) currentPosition += 9;
                                else currentPosition -= 11;
                                break;
                            case 2:
                                if (lastPosition == 41) currentPosition -= 9;
                                else if (lastPosition == 42) currentPosition += 1;
                                else if (lastPosition == 43) currentPosition += 11;
                                else if (lastPosition == 53) currentPosition += 10;
                                else if (lastPosition == 63) currentPosition += 9;
                                else if (lastPosition == 62) currentPosition -= 11;
                                else currentPosition -= 10;
                                break;
                            case 3:
                                if (lastPosition == 41) currentPosition += 1;
                                else if (lastPosition == 42) currentPosition += 11;
                                else if (lastPosition == 43) currentPosition += 10;
                                else if (lastPosition == 53) currentPosition += 9;
                                else if (lastPosition == 63) currentPosition -= 11;
                                else if (lastPosition == 62) currentPosition -= 10;
                                else currentPosition -= 9;
                                break;
                            case 4:
                                if (lastPosition == 41) currentPosition += 11;
                                else if (lastPosition == 42) currentPosition += 10;
                                else if (lastPosition == 43) currentPosition += 9;
                                else if (lastPosition == 53) currentPosition -= 11;
                                else if (lastPosition == 63) currentPosition -= 10;
                                else if (lastPosition == 62) currentPosition -= 9;
                                else currentPosition += 1;
                                break;
                            case 5:
                                if (lastPosition == 41) currentPosition += 10;
                                else if (lastPosition == 42) currentPosition += 9;
                                else if (lastPosition == 43) currentPosition -= 11;
                                else if (lastPosition == 53) currentPosition -= 10;
                                else if (lastPosition == 63) currentPosition -= 9;
                                else if (lastPosition == 62) currentPosition += 1;
                                else currentPosition += 11;
                                break;
                            case 6:
                                if (lastPosition == 41) currentPosition += 9;
                                else if (lastPosition == 42) currentPosition -= 11;
                                else if (lastPosition == 43) currentPosition -= 10;
                                else if (lastPosition == 53) currentPosition -= 9;
                                else if (lastPosition == 63) currentPosition += 1;
                                else if (lastPosition == 62) currentPosition += 11;
                                else currentPosition += 10;
                                break;
                            case 7:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 3:
                        cout << "You feel a wrenching sensation." << endl;
                        dieroll = rand() % 8;
                        temp = currentPosition;
                        switch (dieroll) {
                            case 0:
                                currentPosition -= 11;
                                break;
                            case 1:
                                currentPosition -= 10;
                                break;
                            case 2:
                                currentPosition -= 9;
                                break;
                            case 3:
                                currentPosition -= 1;
                                break;
                            case 4:
                                currentPosition += 1;
                                break;
                            case 5:
                                currentPosition += 9;
                                break;
                            case 6:
                                currentPosition += 10;
                                break;
                            case 7:
                                currentPosition += 11;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 4:
                        cout << "You enter a clearing with a rothe!" << endl;
                        combat('m', 0);
                        
                        cout << "There are 5 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Center\n3) Center\n4) Right Center\n5) Right\n6) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 64) currentPosition += 9;
                                else if (lastPosition == 63) currentPosition -= 1;
                                else if (lastPosition == 53) currentPosition -= 11;
                                else if (lastPosition == 43) currentPosition -= 10;
                                else currentPosition += 10;
                                break;
                            case 2:
                                if (lastPosition == 64) currentPosition -= 1;
                                else if (lastPosition == 63) currentPosition -= 11;
                                else if (lastPosition == 53) currentPosition -= 10;
                                else if (lastPosition == 43) currentPosition -= 9;
                                else currentPosition += 9;
                                break;
                            case 3:
                                if (lastPosition == 64) currentPosition -= 11;
                                else if (lastPosition == 63) currentPosition -= 10;
                                else if (lastPosition == 53) currentPosition -= 9;
                                else if (lastPosition == 43) currentPosition += 10;
                                else currentPosition -= 1;
                                break;
                            case 4:
                                if (lastPosition == 64) currentPosition -= 10;
                                else if (lastPosition == 63) currentPosition -= 9;
                                else if (lastPosition == 53) currentPosition += 10;
                                else if (lastPosition == 43) currentPosition += 9;
                                else currentPosition -= 11;
                                break;
                            case 5:
                                if (lastPosition == 64) currentPosition -= 9;
                                else if (lastPosition == 63) currentPosition += 10;
                                else if (lastPosition == 53) currentPosition += 9;
                                else if (lastPosition == 43) currentPosition -= 1;
                                else currentPosition -= 10;
                                break;
                            case 6:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 5:
                        //water hazard
                        cout << "You find yourself trapped in a surprisingly deep lake. You can't swim with all that armor on!" << endl;
                        play = false;
                        break;
                    case 6:
                        cout << "You enter a clearing with a mummy!" << endl;
                        combat('m', 7);
                        
                        cout << "There are 4 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Center\n3) Right Center\n4) Right\n5) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 45) currentPosition -= 10;
                                else if (lastPosition == 46) currentPosition -= 9;
                                else if (lastPosition == 47) currentPosition += 1;
                                else if (lastPosition == 57) currentPosition += 11;
                                else currentPosition -= 11;
                                break;
                            case 2:
                                if (lastPosition == 45) currentPosition -= 9;
                                else if (lastPosition == 46) currentPosition += 1;
                                else if (lastPosition == 47) currentPosition += 11;
                                else if (lastPosition == 57) currentPosition -= 11;
                                else currentPosition -= 10;
                                break;
                            case 3:
                                if (lastPosition == 45) currentPosition += 1;
                                else if (lastPosition == 46) currentPosition += 11;
                                else if (lastPosition == 47) currentPosition -= 11;
                                else if (lastPosition == 57) currentPosition -= 10;
                                else currentPosition -= 9;
                                break;
                            case 4:
                                if (lastPosition == 45) currentPosition += 11;
                                else if (lastPosition == 46) currentPosition -= 11;
                                else if (lastPosition == 47) currentPosition -= 10;
                                else if (lastPosition == 57) currentPosition -= 9;
                                else currentPosition += 1;
                                break;
                            case 5:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 7:
                        cout << "You enter the clearing and come face to face with an owlbear!" << endl;
                        combat('m', 10);
                        
                        cout << "There are 3 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Center\n3) Right\n4) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 47) currentPosition += 10;
                                else if (lastPosition == 46) currentPosition -= 10;
                                else if (lastPosition == 56) currentPosition -= 11;
                                else currentPosition -= 1;
                                break;
                            case 2:
                                if (lastPosition == 47) currentPosition -= 1;
                                else if (lastPosition == 46) currentPosition += 10;
                                else if (lastPosition == 56) currentPosition -= 10;
                                else currentPosition -= 11;
                                break;
                            case 3:
                                if (lastPosition == 47) currentPosition -= 11;
                                else if (lastPosition == 46) currentPosition -= 1;
                                else if (lastPosition == 56) currentPosition += 10;
                                else currentPosition -= 10;
                                break;
                            case 4:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    default:
                        cout << "Ah heck. You've exited the map. Goodbye." << endl;
                        play = false;
                        break;
                }
                break;
            case 6:
                switch (currentPosition % 10) {
                    case 1:
                        cout << "You've fallen into a pit!" << endl;
                        cin >> foo;
                        cin >> foo;
                        cin >> foo;
                        cout << "You've clawed your way out of the pit. There are 2 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Right\n3) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 52) currentPosition += 1;
                                else if (lastPosition == 62) currentPosition += 11;
                                else currentPosition -= 9;
                                break;
                            case 2:
                                if (lastPosition == 52) currentPosition += 11;
                                else if (lastPosition == 62) currentPosition -= 9;
                                else currentPosition += 1;
                                break;
                            case 3:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 2:
                        cout << "There's nothing here, but there are 5 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Center\n3) Center\n4) Right Center\n5) Right\n6) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 52) currentPosition -= 9;
                                else if (lastPosition == 53) currentPosition += 1;
                                else if (lastPosition == 61) currentPosition -= 10;
                                else if (lastPosition == 63) currentPosition += 11;
                                else if (lastPosition == 72) currentPosition -= 1;
                                else currentPosition += 10;
                                break;
                            case 2:
                                if (lastPosition == 52) currentPosition += 1;
                                else if (lastPosition == 53) currentPosition += 11;
                                else if (lastPosition == 61) currentPosition -= 9;
                                else if (lastPosition == 63) currentPosition += 10;
                                else if (lastPosition == 72) currentPosition -= 10;
                                else currentPosition -= 1;
                                break;
                            case 3:
                                if (lastPosition == 52) currentPosition += 11;
                                else if (lastPosition == 53) currentPosition += 10;
                                else if (lastPosition == 61) currentPosition += 1;
                                else if (lastPosition == 63) currentPosition -= 1;
                                else if (lastPosition == 72) currentPosition -= 9;
                                else currentPosition -= 10;
                                break;
                            case 4:
                                if (lastPosition == 52) currentPosition += 10;
                                else if (lastPosition == 53) currentPosition -= 1;
                                else if (lastPosition == 61) currentPosition += 11;
                                else if (lastPosition == 63) currentPosition -= 10;
                                else if (lastPosition == 72) currentPosition += 1;
                                else currentPosition -= 9;
                                break;
                            case 5:
                                if (lastPosition == 52) currentPosition -= 1;
                                else if (lastPosition == 53) currentPosition -= 10;
                                else if (lastPosition == 61) currentPosition += 10;
                                else if (lastPosition == 63) currentPosition -= 9;
                                else if (lastPosition == 72) currentPosition += 11;
                                else currentPosition += 1;
                                break;
                            case 6:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 3:
                        cout << "There's a lot of paths out of this empty clearing, but luckily there's a large compass set in the ground. You came from the ";
                        switch (lastPosition) {
                            case 52:
                                cout << "northwest";
                                break;
                            case 53:
                                cout << "north";
                                break;
                            case 54:
                                cout << "northeast";
                                break;
                            case 62:
                                cout << "west";
                                break;
                            case 64:
                                cout << "east";
                                break;
                            case 72:
                                cout << "southwest";
                                break;
                            case 73:
                                cout << "south";
                                break;
                            case 74:
                                cout << "southeast";
                                break;
                            default:
                                cout << "oof";
                                break;
                        }
                        cout << " side of the compass. Which direction do you want to go?" << endl << "1) Northwest\n2) North\n3) Northeast\n4) West\n5) East\n6) Southwest\n7) South\n8) Southeast" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                currentPosition -= 11;
                                break;
                            case 2:
                                currentPosition -= 10;
                                break;
                            case 3:
                                currentPosition -= 9;
                                break;
                            case 4:
                                currentPosition -= 1;
                                break;
                            case 5:
                                currentPosition += 1;
                                break;
                            case 6:
                                currentPosition += 9;
                                break;
                            case 7:
                                currentPosition += 10;
                                break;
                            case 8:
                                currentPosition += 11;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 4:
                        cout << "As you step into the clearing, you feel something shift under your feet. Suddenly there's fire all around you!" << endl;
                        for (int i = 0; i < 4; i++) {
                            if (party[i].alive) {
                                party[i].hitpoints -= 5;
                                if (party[i].hitpoints < 1) {
                                    party[i].alive = false;
                                    cout << party[i].name << " dies!" << endl;
                                }
                            }
                        }
                        
                        cout << "There are 5 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Center\n3) Center\n4) Right Center\n5) Right\n6) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 54) currentPosition += 11;
                                else if (lastPosition == 53) currentPosition -= 10;
                                else if (lastPosition == 63) currentPosition -= 11;
                                else if (lastPosition == 73) currentPosition -= 1;
                                else if (lastPosition == 74) currentPosition += 9;
                                else currentPosition += 10;
                                break;
                            case 2:
                                if (lastPosition == 54) currentPosition += 10;
                                else if (lastPosition == 53) currentPosition += 11;
                                else if (lastPosition == 63) currentPosition -= 10;
                                else if (lastPosition == 73) currentPosition -= 11;
                                else if (lastPosition == 74) currentPosition -= 1;
                                else currentPosition += 9;
                                break;
                            case 3:
                                if (lastPosition == 54) currentPosition += 9;
                                else if (lastPosition == 53) currentPosition += 10;
                                else if (lastPosition == 63) currentPosition += 11;
                                else if (lastPosition == 73) currentPosition -= 10;
                                else if (lastPosition == 74) currentPosition -= 11;
                                else currentPosition -= 1;
                                break;
                            case 4:
                                if (lastPosition == 54) currentPosition -= 1;
                                else if (lastPosition == 53) currentPosition += 9;
                                else if (lastPosition == 63) currentPosition += 10;
                                else if (lastPosition == 73) currentPosition += 11;
                                else if (lastPosition == 74) currentPosition -= 10;
                                else currentPosition -= 11;
                                break;
                            case 5:
                                if (lastPosition == 54) currentPosition -= 11;
                                else if (lastPosition == 53) currentPosition -= 1;
                                else if (lastPosition == 63) currentPosition += 9;
                                else if (lastPosition == 73) currentPosition += 10;
                                else if (lastPosition == 74) currentPosition += 11;
                                else currentPosition -= 10;
                                break;
                            case 6:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 5:
                        //water hazard
                        cout << "You find yourself trapped in a surprisingly deep lake. You can't swim with all that armor on!" << endl;
                        play = false;
                        break;
                    case 6:
                        //water hazard
                        cout << "You find yourself trapped in a surprisingly deep lake. You can't swim with all that armor on!" << endl;
                        play = false;
                        break;
                    case 7:
                        cout << "There's nothing here, and it's quiet. Almost a little too quiet. There are 2 paths in front of you. What do you want to do?" << endl << "1) Check for monsters\n2) Go Left\n3) Go Right\n4) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        if (direction == 1) {
                            dieroll = rand() % 10 + 1;
                            if (dieroll == 10) {
                                cout << "You see a gelatinous cube to your ";
                                if (lastPosition == 56) cout << "right." << endl;
                                else if (lastPosition == 57) cout << "left." << endl;
                                else cout << "six." << endl;
                            }
                            else cout << "You don't find anything weird." << endl;
                            cout << "Where do you want to go?" << endl << "1) Left\n2) Right\n3) Go Back" << endl;
                            cin >> foo;
                            scree << foo;
                            scree >> direction;
                            direction++;
                            scree.str(string());
                        }
                        switch (direction) {
                            case 2:
                                if (lastPosition == 56) currentPosition -= 10;
                                else if (lastPosition == 57) currentPosition += 10;
                                else currentPosition -= 11;
                                break;
                            case 3:
                                if (lastPosition == 56) currentPosition += 10;
                                else if (lastPosition == 57) currentPosition -= 11;
                                else currentPosition -= 10;
                                break;
                            case 4:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    default:
                        cout << "Ah heck. You've exited the map. Goodbye." << endl;
                        play = false;
                        break;
                }
                break;
            case 7:
                switch (currentPosition % 10) {
                    case 1:
                        cout << "You've clipped into a tree. You and your entire party die" << endl;
                        play = false;
                        break;
                    case 2:
                        cout << "You enter the clearing and come face to face with a dragon!" << endl;
                        combat('s', 0);
                        
                        cout << "There are 3 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Center\n3) Right\n4) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 61) currentPosition -= 10;
                                else if (lastPosition == 62) currentPosition -= 9;
                                else if (lastPosition == 63) currentPosition += 1;
                                else currentPosition -= 11;
                                break;
                            case 2:
                                if (lastPosition == 61) currentPosition -= 9;
                                else if (lastPosition == 62) currentPosition += 1;
                                else if (lastPosition == 63) currentPosition -= 11;
                                else currentPosition -= 10;
                                break;
                            case 3:
                                if (lastPosition == 61) currentPosition += 1;
                                else if (lastPosition == 62) currentPosition -= 11;
                                else if (lastPosition == 63) currentPosition -= 10;
                                else currentPosition -= 9;
                                break;
                            case 4:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 3:
                        cout << "You enter a clearing. You hear whispering, almost like wind, but it sounds like voices. You look around, but there's no one there. You realize the whispering is coming from the trees themselves. They seem harmless or at least rooted firmly in the ground. There are 4 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Left Center\n3) Right Center\n4) Right\n5) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 72) currentPosition -= 11;
                                else if (lastPosition == 62) currentPosition -= 10;
                                else if (lastPosition == 63) currentPosition -= 9;
                                else if (lastPosition == 64) currentPosition += 1;
                                else currentPosition -= 1;
                                break;
                            case 2:
                                if (lastPosition == 72) currentPosition -= 10;
                                else if (lastPosition == 62) currentPosition -= 9;
                                else if (lastPosition == 62) currentPosition += 1;
                                else if (lastPosition == 64) currentPosition -= 1;
                                else currentPosition -= 11;
                                break;
                            case 3:
                                if (lastPosition == 72) currentPosition -= 9;
                                else if (lastPosition == 62) currentPosition += 1;
                                else if (lastPosition == 62) currentPosition -= 1;
                                else if (lastPosition == 64) currentPosition -= 11;
                                else currentPosition -= 10;
                                break;
                            case 4:
                                if (lastPosition == 72) currentPosition += 1;
                                else if (lastPosition == 62) currentPosition -= 1;
                                else if (lastPosition == 62) currentPosition -= 11;
                                else if (lastPosition == 64) currentPosition -= 10;
                                else currentPosition -= 9;
                                break;
                            case 5:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 4:
                        cout << "You enter the clearing and come face to face with a baby dragon!" << endl;
                        combat('s', 1);
                        
                        cout << "There are 3 paths in front of you. Which do you choose?" << endl << "1) Left\n2) Center\n3) Right\n4) Go Back" << endl;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 73) currentPosition -= 11;
                                else if (lastPosition == 63) currentPosition -= 10;
                                else if (lastPosition == 64) currentPosition += 1;
                                else currentPosition -= 1;
                                break;
                            case 2:
                                if (lastPosition == 73) currentPosition -= 10;
                                else if (lastPosition == 63) currentPosition += 1;
                                else if (lastPosition == 64) currentPosition -= 1;
                                else currentPosition -= 11;
                                break;
                            case 3:
                                if (lastPosition == 73) currentPosition += 1;
                                else if (lastPosition == 63) currentPosition -= 1;
                                else if (lastPosition == 64) currentPosition -= 11;
                                else currentPosition -= 10;
                                break;
                            case 4:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 5:
                        cout << "There's a small spring here. You take the opportunity to take a drink, and feel your strength increase a little. The spring dries up. There is 1 path in front of you. Which do you choose?" << endl << "1) Forward\n2) Go Back" << endl;
                        party[0].kills += 5;
                        cin >> foo;
                        scree << foo;
                        scree >> direction;
                        scree.str(string());
                        temp = currentPosition;
                        switch (direction) {
                            case 1:
                                if (lastPosition == 64) currentPosition -= 1;
                                else currentPosition -= 11;
                                break;
                            case 2:
                                currentPosition = lastPosition;
                                break;
                            default:
                                break;
                        }
                        lastPosition = temp;
                        break;
                    case 6:
                        cout << "You've clipped into a tree. You and your entire party die" << endl;
                        play = false;
                        break;
                    case 7:
                        cout << "You come across a gelatinous cube!" << endl;
                        combat('s', 2);
                        
                        cout << "There's only one way out of here, and it's the way you came in" << endl;
                        temp = currentPosition;
                        currentPosition -= 10;
                        lastPosition = temp;
                        break;
                    default:
                        cout << "Ah heck. You've exited the map. Goodbye." << endl;
                        play = false;
                        break;
                }
                break;
            default:
                cout << "Ah heck. You've exited the map. Goodbye." << endl;
                play = false;
                break;
        }
        for (int i = 0; i < 4; i++) {
            if (party[i].alive) party[i].hitpoints++;
        }
    }
    
    return 0;
}
