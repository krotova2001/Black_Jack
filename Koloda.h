#pragma once
#include "Karta.h"
#include <iostream>
#include <ctime>
using namespace std;

class Koloda
{
	
	const int max_kart = 36; // максимальное количество карт в колоде
	int cur; // текущее количество карт в колоде
	char Digit[9]{'6','7','8','9','d', 'V', 'D', 'K', 'A'}; // варианты достоинств
	char Masti[4][7]{ "chervi", "bubi", "kresti", "piki"}; // варианты мастей
	Karta Karta_cur[36]; // текущий массив карт
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

	void Show_coloda() // служебная функция для отладки, посмотреть колоду
	{
		for (int i = 0; i < cur; i++)
		{
			cout << i<<" - ";
			Karta_cur[i].Get_karta();
		}
	}

	void Shuffle() // перетусовать колоду
	{
		for (int i = 0; i < cur; i++) // в цикле поменяем местами по порядку каждую карту с одной случайной картой
		{
			Karta t; // третья временная карта
			int temp = rand()%36; // случайный индекс массива
			t = Karta_cur[i];
			Karta_cur[i] = Karta_cur[temp];
			Karta_cur[temp] = t;
		}
	}

	Karta Give_Kart() // выдать одну карту (с конца)
	{
		if (cur > 0) // если в колоде еще есть карты, ты выдаем
		{
			cur--;
			return Karta_cur[cur+1];
		}
	}
};

