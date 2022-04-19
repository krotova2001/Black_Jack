// Игра Блэк - Джек, два игрока без участия компьютера.

#include <iostream>
using namespace std;
#include "Koloda.h"
#include "Igrok.h"
#include <ctime>

int main()
{
    srand(time(0));
    Koloda A;
    A.Shuffle();
    Igrok Sanya, Vanya;
    char name1[10]{ "Sanya"};
    Sanya.Set_name(name1);
    char name2[10]{ "Vanya" };
    
    Sanya.Get_Kart(A.Give_Kart());
    Sanya.Get_Kart(A.Give_Kart());


    Vanya.Get_Kart(A.Give_Kart());
    Vanya.Get_Kart(A.Give_Kart());

    Sanya.Show();
    Vanya.Show();

    
}
