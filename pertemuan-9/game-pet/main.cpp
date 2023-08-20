#include <iostream>

using namespace std;

class Pet{
public :
    Pet(string nama, int energi, int fun); // konstruktor
    void Bicara();
    void Makan(int makanan);
    void Bermain(int lvlfun);
private :
    string m_Nama = "";
    int m_Energi = 0;
    int m_Fun = 0;
};

void Pet::Bicara(){
    cout << "Halo, nama saya adalah " << m_Nama << endl;
    cout << "Energi saya masih " << m_Energi << endl;
    cout << "Tingkat fun saya adalah " << m_Fun << endl;
}

void Pet::Makan(int makanan){
    cout << "Nyam!!" << endl;
    m_Energi = m_Energi + makanan;
}

void Pet::Bermain(int lvlfun){
    cout << "Horeeee !!" << endl;
    m_Fun = m_Fun + lvlfun;
}

Pet::Pet(string nama, int energi, int fun):
    m_Nama(nama), m_Energi(energi), m_Fun(fun){
        cout << "NEW PET HAS BORN" << endl;
        cout << "Nama: " << nama << endl;
        cout << "Energi: " << energi << endl;
        cout << "Fun: " << fun << endl;
     }

int main()
{
    Pet pet1("Moci", 4, 1);
    Pet pet2("Dogy", 2, 1);
    Pet pet3("Kitty", 1, 4);

    pet1.Makan(5);
    pet1.Bicara();

    pet2.Bermain(2);
    pet2.Bicara();
    return 0;
}

















// variabel biasa
// string nama;

// variabel
// string nama = "";
