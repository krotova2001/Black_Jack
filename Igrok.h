#pragma once
#include <ctime>
using namespace std;
#include "Koloda.h"

class Igrok
{
	char name[10]; // имя
	Karta Karta_own[10]; // карты на руках, максимально 10
	int karta_cur; // колчиество карт на руках
	int score; // счет
	int ochki; // очки карт
public:
	void Set_name(char* n)
	{
		strncpy_s(name, n, 9);
	}
	Igrok()
	{
		
		karta_cur = score = ochki = 0;
		
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
		cout << "\n----------------";
	}

};

