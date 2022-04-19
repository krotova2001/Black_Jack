#pragma once
#include "Karta.h"
#include <iostream>
#include <ctime>
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

	void Show_coloda() // ��������� ������� ��� �������, ���������� ������
	{
		for (int i = 0; i < cur; i++)
		{
			cout << i<<" - ";
			Karta_cur[i].Get_karta();
		}
	}

	void Shuffle() // ������������ ������
	{
		for (int i = 0; i < cur; i++) // � ����� �������� ������� �� ������� ������ ����� � ����� ��������� ������
		{
			Karta t; // ������ ��������� �����
			int temp = rand()%36; // ��������� ������ �������
			t = Karta_cur[i];
			Karta_cur[i] = Karta_cur[temp];
			Karta_cur[temp] = t;
		}
	}

	Karta Give_Kart() // ������ ���� ����� (� �����)
	{
		if (cur > 0) // ���� � ������ ��� ���� �����, �� ������
		{
			cur--;
			return Karta_cur[cur+1];
		}
	}
};

