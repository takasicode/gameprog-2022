#include <iostream>
#include <string>

using namespace std;

int main(){
    string nama_item = "";
    float stat = 0;
    char lagi = 'y';

    string item_sebelumnya = "";
    float stat_sebelumnya;

    bool item_pertama = true;

    string item_terhebat;
    string item_terlemah;

    float stat_terhebat;
    float stat_terlemah;

    while(lagi=='y'){
        cout << "Masukkan Nama Item : ";
        cin >> nama_item;
        cout << "Masukkan Stat : ";
        cin >> stat;
        cout << "Item yang baru Anda masukkan : " << nama_item << endl;
        cout << "Stat item baru : " << stat << endl;
        if (item_pertama == true){
            item_sebelumnya = "Tidak Ada";
            stat_sebelumnya = 0;

            stat_terhebat = stat;
            item_terhebat = nama_item;

            stat_terlemah = stat;
            item_terlemah = nama_item;
        } else  {
            if (stat >= stat_terhebat){
                stat_terhebat = stat;
                item_terhebat = nama_item;
            } else {
                if (stat <= stat_terlemah){
                    stat_terlemah = stat;
                    item_terlemah = nama_item;
                }
            }
        }
        cout << "Item sebelumnya : "<< item_sebelumnya << endl;
        cout << "Stat sebelumnya : "<< stat_sebelumnya << endl;

        item_sebelumnya = nama_item;
        stat_sebelumnya = stat;

        cout << "Item terhebat adalah " << item_terhebat << endl;
        cout << "Item terlemah adalah " << item_terlemah << endl;
        item_pertama = false;

        cout << "Input lagi ? (y/n) " << std::endl;
        cin >> lagi;
    }
    cout << "Selesai";
    return 0;
}
