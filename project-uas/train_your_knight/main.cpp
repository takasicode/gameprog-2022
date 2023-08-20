#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include<sstream>

using namespace std;

vector <string> hsl{};
vector <string>::iterator iter;
string hasil;

//Class Knight
class Knight{
public:
    //Action
    Knight(string name, int health, int strength, int defense, int energy); //Constructor: Memberi nilai awal pada identitas
    void Intro();
    void Train();
    void Sleep();
    void Status();
    void Battle();
    void History();
    int m_Energy = 0;

protected:
    string m_Name;
    string c_Name = "Computer";
    int m_Health;
    int m_Strength;
    int m_Defense;
    int c_Health = 100;
    int c_Strength = 100;
    int c_Defense = 100;

};

Knight::Knight(string name, int health,  int strength, int defense, int energy):m_Name(name), m_Health(health), m_Strength(strength), m_Defense(defense), m_Energy(energy){
    cout << "Name your knight : ";
    cin >> m_Name;
    cout << endl;
    cout << "'From the distant mountains comes a hero who has been\n hailed as the kingdom's last hope in these troubled times.\n He is " << m_Name << ", a warrior of unmatched skill and\n courage who will not rest until justice has been served\n and peace has been restored.'" << endl;
    cout << "\n'Welcome to Mordor, " << m_Name << "!'" << endl;
    cout << "'We've been waiting for you!'\n" << endl;
}

void Knight::Intro(){
    cout << "My name is: " << m_Name << endl;
    cout << "My strength level is: " << m_Strength << endl;
    cout << "My defense level is: " << m_Defense << endl;
    cout << "My energy is: " << m_Energy << endl;
}

void Knight::Train(){
    m_Strength += 10;
    m_Health += 10;
    m_Defense += 10;
    m_Energy -= 10;

    cout << "\nGain strength poin by [+15] " << endl;
    cout << "Gain defense poin by [+10] " << endl;
    cout << "Energy reduced by [-10]" << endl;
    cout << endl;
    cout << "|====== STATUS ======|" << endl;
    cout << "-> Strength  : " << m_Strength << endl;
    cout << "-> Defense   : " << m_Defense << endl;
    cout << "-> Energy    : " << m_Energy << endl;
    cout << endl;
}

void Knight::Sleep(){
    m_Energy += 100;
    cout << "I'm exhausted, I need to sleep." << endl;
    cout << "Zzzz... Zzzz... Zzzz...\n" << endl;
    cout << "Gain energy by [+50]" << endl;
}

void Knight::Status(){
    cout << "+------------------------+" << endl;
    cout << "|======== STATUS ========|" << endl;
    cout << "+------------------------+" << endl;
    cout << "-> Name      : " << m_Name << endl;
    cout << "-> Health    : " << m_Health << endl;
    cout << "-> Strength  : " << m_Strength << endl;
    cout << "-> Defense   : " << m_Defense << endl;
    cout << "-> Energy    : " << m_Energy << endl;
}

void Knight::Battle(){
    while(true){
        int m_Attack, c_Attack;
        int min = 0;
        int max = 50;
        c_Attack = c_Strength * 0.2 + (min + rand() % (( max + 1 ) - min));
        m_Attack = m_Strength * 0.2 + (min + rand() % (( max + 1 ) - min));

        string c_att, m_att;
        string m_shield, c_shield;
        string c_status, m_status;

        m_Defense -= c_Attack;
        c_att = "Computer Menyerang";
        hsl.push_back(c_att);
        c_Defense -= m_Attack;
        m_att = "Anda Menyerang";
        hsl.push_back(m_att);

        if(m_Defense < 0){
            m_shield = "Def Anda Hancur";
            hsl.push_back(m_shield);
            m_Defense = 0;
            m_Health -= c_Attack;
            if (m_Health < 0){
                m_Health = 0;
                c_status = "Musuh Menang";
                hsl.push_back(c_status);
                cout << c_status << endl;
                cout << "Anda Kalah, Silakan Latihan dan Healing untuk balas dendam" << endl;
                break;
            }
        }
        if(c_Defense < 0){
            c_shield = "Def Musuh Hancur";

            hsl.push_back(c_shield);
            c_Defense = 0;
            c_Health -= m_Attack;
            if (c_Health < 0){
                m_shield = "Def Musuh Hancur";
                hsl.push_back(m_shield);
                c_Health = 0;
                m_status = "Anda Menang";
                hsl.push_back(m_status);
                cout << m_status << endl;
                cout << "Anda Terluka Parah, Silakan Latihan dan Healing" << endl;
                c_Health = 100;
                c_Defense = 100;
                break;
            }
        }
        string c_Attack_Parse = to_string(c_Attack);

        cout << c_Name << " Menyerang dengan kekuatan: "<< c_Attack_Parse << endl;
        cout << m_Name << " Menyerang dengan kekuatan: "<< m_Attack << endl;
        cout << "Sisa Def Computer: " << c_Defense << " dan " << "Sisa Health Computer: " << c_Health << endl;
        cout << "Sisa Def Anda: " << m_Defense << " dan " << "Sisa Health Anda: " << m_Health << endl;
        cout << endl;
        // hsl.push_back(c_Name << " Menyerang dengan kekuatan: "<< c_Attack_Parse << endl)
    }
}

void Knight::History(){
    cout<< "History : " <<endl;
    cout << endl;
    for(iter = hsl.begin(); iter != hsl.end(); ++iter){
        cout<< *iter <<endl;
        cout << endl;
    }
}

//Add Gold Function
void addGold(float &plusGold){
    plusGold += 100000;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    // Variabel
    char back = 'y';
    char shop = 'y';
    int option;
    int activity_option;
    char train_repeat = 'y';
    char sleep_repeat = 'y';
    int number;
    int bomb;
    int reward;
    float gold = 100000;

    vector<string>weapon{""};
    srand(static_cast<unsigned int>(time(0)));
    vector<string>::iterator selector;

    //-------------------------------------------------------------------

    // Start
    Knight hero("", 200, 100, 50, 100);
    // Knight hero(200);

    //Main Menu
    while(back == 'y'){
        cout << "+-------------------------+" << endl;
        cout << "|=== TRAIN YOUR KNIGHT ===|" << endl;
        cout << "+-------------------------+" << endl;
        cout << "|======= MAIN MENU =======|" << endl;
        cout << "+-------------------------+" << endl;
        cout << "|  1. Activity            |" << endl;
        cout << "|  2. Battle              |" << endl;
        cout << "|  3. Play Lottery        |" << endl;
        cout << "|  4. Shop                |" << endl;
        cout << "|  5. Show Inventory      |" << endl;
        cout << "|  6. Show Status         |" << endl;
        cout << "|  7. Show History Battle |" << endl;
        cout << "|  8. Exit                |" << endl;
        cout << "+-------------------------+" << endl;

        cout << "\nChoose: ";
        cin >> option;
        cout << endl;

        if(option == 1){
            //1. Activity
            cout << "Energy: " << hero.m_Energy << endl;
            cout << "+----------------+" << endl;
            cout << "|=== ACTIVITY ===|" << endl;
            cout << "+----------------+" << endl;
            cout << "|    1. Train    |" << endl;
            cout << "|    2. Sleep    |" << endl;
            cout << "+----------------+" << endl;
            cout << "\nWhat are you gonna do? ";
            cin >> activity_option;
            cout << endl;

            //1. Train
            if(activity_option == 1){
                if(hero.m_Energy <= 0){
                    cout << "Hufftt... I need a rest." << endl;
                } else{
                    while(train_repeat = 'y'){
                        hero.Train();
                        cout << "Again? [y/n] ";
                        cin >> train_repeat;

                        if(hero.m_Energy <= 0){
                            cout << "Hufftt... I need a rest." << endl;
                            break;
                        } else if(train_repeat == 'n'){
                            break;
                        }
                    }
                }
            //2. Sleep
            } else if(activity_option == 2){
                while(sleep_repeat == 'y'){
                    hero.Sleep();
                    cout << "Again? [y/n]";
                    cin >> sleep_repeat;

                    if(sleep_repeat == 'n'){
                        break;
                    }
                }
            }

        } else if (option == 2){
            // 2. Battle
            hero.Battle();

        } else if(option == 3){
            // 1. Play Lotre
            cout << "+---+---+---+" << endl;
            cout << "| GOOD LUCK |" << endl;
            cout << "+---+---+---+" << endl;
            cout << "| 1 | 2 | 3 |" << endl;
            cout << "+---+---+---+" << endl;
            cout << "| 4 | 5 | 6 |" << endl;
            cout << "+---+---+---+" << endl;
            cout << "| 7 | 8 | 9 |" << endl;
            cout << "+---+---+---+\n" << endl;

            for(int i = 1; i <= 3; i++){
                cout << "Choose the number: ";
                cin >> number;

                bomb = rand() % 9 + 1;
                if(number == bomb){
                    cout << "BOOM! YOUR HEAD IS EXPLODE!\n" << endl;
                    break;
                } else if(i == 3){
                    //Reward
                    cout << "!!! YOU WIN !!!\n" << endl;

                    reward = rand() % 5 + 1;
                    if(reward == 1){
                        weapon.push_back("Blade of Chaos");
                        cout << "'Blade of Chaos' added to your inventory!" << endl;
                    } else if(reward == 2){
                        weapon.push_back("Lightsaber");
                        cout << "'Lightsaber' added to your inventory!" << endl;
                    } else if(reward == 3){
                        weapon.push_back("Sauron's Crown");
                        cout << "'Sauron's Crown' added to your inventory!" << endl;
                    } else{
                        addGold(gold);
                        cout << "You got 100000 golds!" << endl;
                    }
                } else{
                    cout << "NICE! There is no bomb in here! \n" << endl;
                }
            }
        } else if(option == 4){
            //4. Shop
                cout << "+------------------------------+" << endl;
                cout << "|--- WELCOME TO BROK's SHOP ---|" << endl;
                cout << "+------------------------------+" << endl;
                cout << "|       'What can I help?'     |" << endl;
                cout << "+------------------------------+" << endl;
                cout << "|         1. Weapon            |" << endl;
                cout << "|         2. Armor             |" << endl;
                cout << "|         3. Exit              |" << endl;
                cout << "+------------------------------+" << endl;
                cout << "\nChoose: ";
                cin >> option;

                //1. Weapon
                if(option == 1){
                    cout << "\nGold : " << gold << endl;
                    cout << "+------------------------------------------------------+" << endl;
                    cout << "|----------------------- WEAPON -----------------------|" << endl;
                    cout << "+------------------------------------------------------+" << endl;
                    cout << "|  1. Artorias Sword   | [+175 Damage] | [20000 Gold]  |" << endl;
                    cout << "|  2. Axe of Leviathan | [+150 Damage] | [10000 Gold]  |" << endl;
                    cout << "|  3. Blades of Chaos  | [+225 Damage] | [30000 Gold]  |" << endl;
                    cout << "|  4. Sparda's Sword   | [+300 Damage] | [50000 Gold]  |" << endl;
                    cout << "|  5. Hand of Malenia  | [+275 Damage] | [40000 Gold]  |" << endl;
                    cout << "+------------------------------------------------------+" << endl;
                    cout << "\nChoose: ";
                    cin >> option;
                    cout << endl;

                    if(option == 1){
                        if (gold >= 20000){
                            gold -= 20000;
                            cout << "Thanks for purchasing!. Here is your weapon." << endl;
                            weapon.push_back("Artorias Sword");
                            cout << "*Artorias Sword added to your inventory" << endl;
                        } else if(gold < 20000){
                            cout << "Sorry, you don't have enough money to buy this item." << endl;
                        }
                    } else if(option == 2){
                        if (gold >= 10000){
                            gold -= 10000;
                            cout << "Thanks for purchasing!. Here is your weapon." << endl;
                            weapon.push_back("Axe of Leviathan");
                            cout << "*Axe of Leviathan added to your inventory" << endl;
                        } else if(gold < 10000){
                            cout << "Sorry, you don't have enough money to buy this item." << endl;
                        }
                    } else if(option == 3){
                        if (gold >= 30000){
                            gold -= 30000;
                            cout << "Thanks for purchasing!. Here is your weapon." << endl;
                            weapon.push_back("Blades of Chaos");
                            cout << "*Blades of Chaos added to your inventory" << endl;
                        } else if(gold < 30000){
                            cout << "Sorry, you don't have enough money to buy this item." << endl;
                        }
                    } else if(option == 4 ){
                        if (gold >= 50000){
                            gold -= 50000;
                            cout << "Thanks for purchasing!. Here is your weapon." << endl;
                            weapon.push_back("Sparda's Sword");
                            cout << "*Spardas's Sword added to your inventory" << endl;
                        } else if(gold < 50000){
                            cout << "Sorry, you don't have enough money to buy this item." << endl;
                        }
                    } else if(option == 5){
                        if (gold >= 40000){
                            gold -= 40000;
                            cout << "Thanks for purchasing!. Here is your weapon." << endl;
                            weapon.push_back("Hand of Malenia");
                            cout << "*Hand of Malenia added to your inventory" << endl;
                        } else if(gold < 40000){
                            cout << "Sorry, you don't have enough money to buy this item." << endl;
                        }
                    } else{
                        cout << "The weapon is not available!" << endl;
                    }
                //2. Armor
                } else if(option == 2){
                    cout << "\nGold : " << gold << endl;
                    cout << "+------------------------------------------------------+" << endl;
                    cout << "|----------------------- ARMOR ------------------------|" << endl;
                    cout << "+------------------------------------------------------+" << endl;
                    cout << "|  1. Cleanrot Armor   | [+275 Defense] | [40000 Gold] |" << endl;
                    cout << "|  2. Godfrey Armor    | [+175 Defense] | [20000 Gold] |" << endl;
                    cout << "|  3. Crown of Sauron  | [+150 Defense] | [10000 Gold] |" << endl;
                    cout << "|  4. Elden Lord Armor | [+300 Defense] | [50000 Gold] |" << endl;
                    cout << "|  5. Radahn Armor     | [+225 Defense] | [30000 Gold] |" << endl;
                    cout << "+------------------------------------------------------+" << endl;
                    cout << "\nChoose: ";
                    cin >> option;

                    if(option == 1){
                        if (gold >= 40000){
                            gold -= 40000;
                            cout << "Thanks for purchasing!. Here is your armor." << endl;
                            weapon.push_back("Cleanrot Armor");
                            cout << "*Cleanrot Armor added to your inventory" << endl;
                        } else if(gold < 40000){
                            cout << "Sorry, you don't have enough money to buy this item." << endl;
                        }
                    } else if(option == 2){
                        if (gold >= 20000){
                            gold -= 20000;
                            cout << "Thanks for purchasing!. Here is your armor." << endl;
                            weapon.push_back("Godfrey Armor");
                            cout << "*Godfreh Armor added to your inventory" << endl;
                        } else if(gold < 20000){
                            cout << "Sorry, you don't have enough money to buy this item." << endl;
                        }
                    } else if(option == 3){
                        if (gold >= 10000){
                            gold -= 10000;
                            cout << "Thanks for purchasing!. Here is your armor." << endl;
                            weapon.push_back("Crown of Sauron");
                            cout << "*Crown of Sauron added to your inventory" << endl;
                        } else if(gold < 10000){
                            cout << "Sorry, you don't have enough money to buy this item." << endl;
                        }
                    } else if(option == 4 ){
                        if (gold >= 50000){
                            gold -= 50000;
                            cout << "Thanks for purchasing!. Here is your armor." << endl;
                            weapon.push_back("Elden Lord Armor");
                            cout << "*Elden Lord Armor added to your inventory" << endl;
                        } else if(gold < 50000){
                            cout << "Sorry, you don't have enough money to buy this item." << endl;
                        }
                    } else if(option == 5){
                        if (gold >= 30000){
                            gold -= 30000;
                            cout << "Thanks for purchasing!. Here is your armor." << endl;
                            weapon.push_back("Radahn Armor");
                            cout << "*Radahn Armor added to your inventory" << endl;
                        } else if(gold < 30000){
                            cout << "Sorry, you don't have enough money to buy this item." << endl;
                        }
                    } else{
                        cout << "The armor is not available!" << endl;
                    }
                }
        } else if(option == 5){
            //5. Show inventory
            cout << "+-------------------------+" << endl;
            cout << "|======= INVENTORY =======|" << endl;
            cout << "+-------------------------+\n" << endl;

            cout << "|-------- FINANCE --------|" << endl;
            cout << "-> Gold: " << gold << endl;

            cout << "\n|--------  ARMORY --------|" << endl;
            for(selector = weapon.begin(); selector != weapon.end(); ++selector){
                cout << "-> " << *selector << endl;
            }
        } else if(option == 6){
            //6. Show Status
            hero.Status();

        } else if(option == 7){
            //7. Show History Battle
            hero.History();

        } else if(option == 8){
            break;

        } else{
            cout << "Sorry, that option is not available" << endl;
            cout << "Select the available options ";
            cin >> option;
            cout << endl;
        }

        cout << "\nWanna do something else? [y/n]: ";
        cin >> back;
        cout << endl;
    }

    cout << "THANKS FOR PLAYING!!!\n";

    return 0;
}
