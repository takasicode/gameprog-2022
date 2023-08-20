#include <iostream>

using namespace std;

void attack(int &att_damage){
    cout << "Jumlah_damage : " << attack damage << endl;
}

void upgrade(int &upg_damage){
    cout << "Jumlah_damage : " << Upgrade damage << endl;
}

int main(){
    char lagi = 'y';
    int pilihan = 1;
    int damage = 1;

    while (lagi == 'y'){
        cout << "\nPilih aksi : " << endl;
        cout << "1. Attack" << endl;
        cout << "2. Upgrade" << endl;
        cout << "Pilihan Anda (1/2) = ";
        cin >> pilihan;
        if(pilihan==1){
            // attack
            cout << "Jumlah Damage : " << damage << endl;
        }else if(pilihan==2){
            // upgrade
            damage = damage + 2;
        }
        cout << "\nPilih lagi (y/n)";
        cin >> lagi;
    }

    return 0;
}
