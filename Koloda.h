#pragma once
#include "Karta.h"
#include <iostream>
using namespace std;

class Koloda
{
	const int max_kart = 36; // ������������ ���������� ���� � ������
	int cur; // ������� ���������� ���� � ������
	char Digit[9]{'6','7','8','9','d', 'V', 'D', 'K', 'A'}; // �������� ����������
	char Masti[4][7]{ "chervi", "bubi", "kresti", "piki"}; // �������� ������
	Karta Karta_cur[36]; // ������� ������ ����
public:
	Koloda() //����������� ������ �� ���������, ������� 36 ����
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

	void Show_coloda() // ��������� ������� ��� �������, ���������� ��� ������
	{
		for (int i = 0; i < max_kart; i++)
		{
			Karta_cur[i].Get_karta();
		}
	}
};

