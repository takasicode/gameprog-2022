#include <iostream>

using namespace std;

// begin class musuh
class Musuh{
public:
    Musuh(int damage, int defense); // konstruktor
    void Serang();
    virtual void Status();
protected:
    int m_Damage = 0;
    int m_Defense = 0;
};

Musuh::Musuh(int damage, int defense) : m_Damage(damage), m_Defense(defense){
    cout << "Ada Musuh baru !" << endl;
}

void Musuh::Serang(){
    cout << "Musuh menyerang ! Kena Damage " << m_Damage << endl;
}

void Musuh::Status(){
    cout << "Saya Musuh biasa." << endl;
    cout << "Damage = " << m_Damage << endl;
    cout << "Defense = " << m_Defense << endl;
}
// end class musuh

// begin class boss
class Boss:public Musuh{
public:
    Boss(string nama, int damage, int defense); // konstruktor: damage dan defense turunan dari class musuh
    void SpecialAtk();
    void Status() override;
private:
    string m_Nama = "";
};

Boss::Boss(string nama, int damage, int defense) : m_Nama(nama), Musuh(damage, defense){}

void Boss::SpecialAtk(){
    cout << "Special Attack !! Kena Damage " << m_Damage + 10 <<endl;
}

void Boss::Status(){
    cout << "Saya adalah Boss." << endl;
    cout << "Nama = " << m_Nama << endl;
    cout << "Damage = " << m_Damage << endl;
    cout << "Defense = " << m_Defense << endl;
}
// end class boss

int main()
{
    Musuh musuh1(5, 2);
    musuh1.Serang();
    musuh1.Status();

    Boss boss1("Bowser", 50, 30);
    boss1.Serang();
    boss1.SpecialAtk();
    boss1.Status();
    return 0;
}

// UML
// =================
// Musuh
// -m_Damage
// -m_Defense
// +Serang()
// +Status()

// PANAH KEATAS

// UML
// =================
// Bpss
// -m_Nama
// +SpecialAtk()
