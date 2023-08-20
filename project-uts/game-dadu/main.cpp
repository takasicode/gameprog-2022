#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

    vector <string> hsl{};
    vector <string>::iterator iter;
    string hasil;

void result(int player, int bot)
{
    cout<<"\nAnda : "<<player<<endl;
    cout<<"Komputer : "<<bot<<"\n"<<endl;

    // ketika Player lebih besar dari bot maka Player Menang
    if(player > bot)
    {
        hasil = "Anda Menang";
        cout<<"==================="<<endl;
        cout<<"==> "<<hasil<<" <=="<<endl;
        cout<<"==================="<<endl;
        hsl.push_back(hasil);
    }

    // ketika player lebih kecil dari bot maka Player Kalah
    else if(player < bot)
    {
        hasil = "Anda Kalah";
        cout<<"=================="<< endl;
        cout<<"==> "<<hasil<<" <=="<< endl;
        cout<<"=================="<< endl;
        hsl.push_back(hasil);
    }

    // ketika tidak lebih dan tidak kurang maka Seri
    else
    {
        hasil = "Seri";
        cout<<"============"<<endl;
        cout<<"==> "<<hasil<<" <=="<<endl;
        cout<<"============"<<endl;
        hsl.push_back(hasil);
    }
}

int main()
{
    int pil, player, bot;
    string hasil;

    // perulangan
    string lagi;
    do
    {
        system("cls"); // clear screen: untuk membersihkan layar yang ada di atas
        cout<<"\n============================="<<endl;
        cout<<" Selamat datang di GAME DADU "<<endl;
        cout<<"============================="<<endl;
        cout<<"1. Lempar Dadu"<<endl;
        cout<<"2. Game Selesai"<<endl;
        cout<<"Pilihan Anda <1/2> : ";

        cin >> pil;

        // ketika pilihan angka 1 maka otomatis akan menampilkan semua
        if (pil == 1)
        {
            // mendapatkan angka random Player dan Bot
            // % = untuk merandom angka 0 sampai kurang dari 6. jika random yang didapat 0 maka akan  bernilai 1
            player = (rand() % 6) +1;
            bot = (rand() % 6) +1;

            result(player, bot);

            cout<< "\nBermain Lagi <y/n> : ";
            cin>>lagi;
        }

        // ketika pilihan angka 2 maka game akan selesai
        else if (pil >= 2)
        {
          lagi = "n";
        }

        // ketika pilihan bukan angka 1 dan 2 maka Pilihan Salah
        else
        {
          cout<< "Pilihan Salah" <<endl;
        }
    }

    while (lagi == "y");
    system("cls");

    cout<< "\nJumlah Lemparan : "<<hsl.size()<<"\n"<<endl;
    cout<< "History : " <<endl;
    for(iter = hsl.begin(); iter != hsl.end(); ++iter)
    {
        cout<< *iter <<endl;
    }

    cout<<"\n===================="<<endl;
    cout<<"==> Game Selesai <=="<<endl;
    cout<<"===================="<<endl;
    return 0;
}
