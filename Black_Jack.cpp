// Игра Блэк - Джек, два игрока без участия компьютера.
//Правила оценки карт по русской игре "21", туз -всегда 11. Как сделать 1  или 11 я пока не знаю

#include <iostream>
//#include "Koloda.h" можно не импортировать - так работает
#include "Igrok.h"
#include <ctime>
using namespace std;
char* Win(Igrok* a, Igrok* b) // функция проверки не выйграл ли кто. Чтоб не было лишних конструкторов, возвращает указатель на победителя
{
    if (a->Ochki()>b->Ochki()) // если очков больше, то он и выйграл
    {
        a->Score_up(); // увеличиваем счет
        return a->Get_Name(); // возвращаем имя игрока
    }
    if (b->Ochki() > a->Ochki())
    {
        b->Score_up();
        return b->Get_Name();
    }
    //else return; // если ничья - ничего не возвращаем
}

int main()
{
    srand(time(0)); // только в main работает эта функция 
    Koloda A; // создаем колоду
    A.Shuffle(); // тусуем
    Igrok Sanya("Sanya"), Vanya("Vanya"); // создаем двух игроков
    
    Sanya.Get_Kart(A.Give_Kart()); // берем по карте
    Sanya.Get_Kart(A.Give_Kart()); // немного громоздко - через две функции, игрок - берет, а колода - дает
    Vanya.Get_Kart(A.Give_Kart());
    Vanya.Get_Kart(A.Give_Kart());
    //по правилам берем по две карты, далее - уже по желанию
    Sanya.Show(); // смотрим
    Vanya.Show();
    cout << "Winner is " << Win(&Sanya, &Vanya)<<"\n";

    cout << "Play untill end? (y/n)";
    char ans;
    cin>> ans;
   
    if (ans=='y') 
    {
        while (A.Get_cur()<2)
        {
            return;
        }
    }
  
    cout << "SCORE:\n";
    cout << Sanya.Get_Name() << " - "<< Sanya.Get_score() << "\n";
    cout << Vanya.Get_Name() << " - "<< Vanya.Get_score() << "\n";
}
