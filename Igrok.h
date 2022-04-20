#pragma once
#include <ctime>
using namespace std;
#include "Koloda.h"

class Igrok
{
	char name[10]; // имя
	Karta Karta_own[10]; // карты на руках, максимально 10
	int karta_cur; // количество карт на руках
	int score; // счет
	int ochki; // очки карт
public:
	
	Igrok(const char* n) // конструктор, который принимает имя игрока
	{
		strcpy_s(name, n);
		karta_cur = score = ochki = 0;
	}
	char* Get_Name()
	{
		return name;
	}
	
	void Get_ochki(Karta a) // опредление очка карты. По правилам игры Очко
	{
		int temp=0;
		if (a.Get_num()=='6')temp = 6;
		if (a.Get_num() == '7')temp = 7;
		if (a.Get_num() == '8')temp = 8;
		if (a.Get_num() == '9')temp = 9;
		if (a.Get_num() == 'd')temp = 10;
		if (a.Get_num() == 'V')temp = 8;
		if (a.Get_num() == 'D')temp = 9;
		if (a.Get_num() == 'K')temp = 10;
		if (a.Get_num() == 'A')temp = 11;
		ochki += temp;
	}
	
	void Get_Kart(Karta a) //взять карту
	{
		Karta_own[karta_cur] = a;
		Get_ochki(a);
		karta_cur++;
	}

	void Show() // показать карты на руках
	{
		cout << name << "\n";
		for (int i = 0; i < karta_cur; i++)
		{
			Karta_own[i].Get_karta();
		}
		cout << "Ochki - " << ochki;
		cout << "\n----------------\n";
	}
	int Ochki() // возращает  очки карт на руках, для определения победителя
	{
		return ochki;
	}

	void Score_up() // если выйграл - повышаем счет
	{
		score++;
	}

	int Get_score() // показать счет
	{
		return score;
	}
	void Reset() //сброс карт
	{
		karta_cur = 0;
		ochki = 0;
	}

};

