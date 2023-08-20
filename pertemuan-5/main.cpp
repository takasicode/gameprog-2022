#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    int acak, pilih;
    srand(time(NULL));
    awal:
        acak = rand()%3;
        cout <<"===============================================" << endl;
        cout <<"------------------- Suit Game -----------------";
        cout <<"===============================================" << endl;
        cout <<"\nPilih" << endl;
        cout <<"[1]. Gunting\n";
        cout <<"[2]. Batu\n";
        cout <<"[3]. Kertas\n";
        cout << "Masukkan pilihan Anda : ";
        cin >> pilih;
        cout << endl;

        if (pilih == 1){
            cout << "Pilihan Kamu: Batu\n";
            if(acak == 0){
               cout<<"Pilihan Komputer: Batu\n";
               cout<<"\nSERI ";
            }
            else if(acak == 1){
               cout<<"Pilihan Komputer: Kertas\n";
               cout<<"\nKAMU KALAH ";
            }
            else if(acak == 2){
                cout<<"Pilihan Komputer: Gunting\n";
                cout<<"\nKAMU MENANG ";
            }
        }


        return 0;
}
