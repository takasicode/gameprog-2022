#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int acak = 0;
    srand(static_cast<unsigned int>(time(0)));
    acak = (rand() % 8) + 3;
    cout << "Hasil acak: " << acak << endl;
    return 0;
}
