#pragma once
#include "Karta.h"
#include <iostream>
using namespace std;

class Koloda
{
	const int max_kart = 36; // максимальное количество карт в колоде
	int cur; // текущее количество карт в колоде
	char Digit[9]{'6','7','8','9','d', 'V', 'D', 'K', 'A'}; // варианты достоинств
	char Masti[4][7]{ "chervi", "bubi", "kresti", "piki"}; // варианты мастей
	Karta Karta_cur[36]; // такущий массив карт
public:
	Koloda() //конструктор колоды по умолчанию, создает 36 карт
	{
		cur = 0;
		for (int m = 0; m < 4; m++)
		{
			for (int d = 0; d < 9; d++)
			{
				Karta_cur[cur].Set_num(Digit[d]);
				Karta_cur[cur].Set_mast(Masti[m]);
				cur++;
			}
		}
	}

	void Show_coloda() // служебная функция для отладки, посмотреть всю колоду
	{
		for (int i = 0; i < max_kart; i++)
		{
			Karta_cur[i].Get_karta();
		}
	}
};

