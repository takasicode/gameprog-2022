#include <iostream>

using namespace std;

// class pet
class Pet{
public:
    Pet(string nama, int energi, int fun); // konstruktor pet
    virtual void Bicara();
    void Makan();
    void Bermain();
protected:
    string m_Nama = "";
    int m_Energi = 0;
    int m_Fun = 0;
};

// definisi class Pet
Pet::Pet(string nama, int energi, int fun):m_Nama(nama), m_Energi(energi), m_Fun(fun){
    cout << "NEW PET" << endl;
}
void Pet::Bicara(){
    cout << "Halo!" << endl;
    cout << "NAMA : " << m_Nama << endl;
    cout << "ENERGI : " << m_Energi << endl;
    cout << "FUN : " << m_Fun << endl;
}
void Pet::Makan(){
    cout << "Nyamm!" << endl;
}
void Pet::Bermain(){
    cout << "Asikk!" << endl;
}

// class LandPet turunan dari class pet
class LandPet: public Pet{
public:
    LandPet(string nama, int energi, int fun, int earthskill); // konstruktor LandPet
    void Jalan();
    void Bicara()override;
private:
    int m_EarthSkill = 0;
};

LandPet::LandPet(string nama, int energi, int fun, int earthskill):Pet(nama, energi, fun), m_EarthSkill(earthskill){}
void LandPet::Bicara(){
    cout << "LAND PAT" << endl;
    cout << "NAMA : " << m_Nama << endl;
    cout << "ENERGI : " << m_Energi << endl;
    cout << "FUN : " << m_Fun << endl;
    cout << "SKIL : " << m_EarthSkill << endl;
}

void LandPet::Jalan(){
    cout << "Saya Jalan" << endl;
}

// class FlyingPet turunan dari class pet
class FlyingPet: public Pet{
public:
    FlyingPet(string nama, int energi, int fun, int flyingskill); // konstruktor FlyingPet
    void Fly();
    void Bicara()override;

private:
    int m_FlySkill = 0;
};

FlyingPet::FlyingPet(string nama, int energi, int fun, int flyskill):Pet(nama, energi, fun), m_FlySkill(flyskill) {}
void FlyingPet::Bicara(){
    cout << "FLY" << endl;
    cout << "NAMA : " << m_Nama << endl;
    cout << "ENERGI : " << m_Energi << endl;
    cout << "FUN : " << m_Fun << endl;
    cout << "TERBANG : " << m_FlySkill << endl;
}

void FlyingPet::Fly(){
    cout << "Saya Terbang" << endl;
}

int main()
{
    Pet pet1("Haruka", 10, 5);
    pet1.Bicara();
    pet1.Makan();
    pet1.Bermain();
    cout << "=============================" << endl;
    LandPet landpet1("Johan", 12, 6, 8);
    landpet1.Bicara();
    landpet1.Makan();
    landpet1.Bermain();
    landpet1.Jalan();
    cout << "=============================" << endl;
    FlyingPet flyingpet1 ("Late", 10, 5, 15);
    flyingpet1.Bicara();
    flyingpet1.Makan();
    flyingpet1.Bermain();
    flyingpet1.Fly();
    return 0;
}
