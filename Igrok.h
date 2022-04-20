#pragma once
#include <ctime>
using namespace std;
#include "Koloda.h"

class Igrok
{
	char name[10]; // ���
	Karta Karta_own[10]; // ����� �� �����, ����������� 10
	int karta_cur; // ���������� ���� �� �����
	int score; // ����
	int ochki; // ���� ����
public:
	
	Igrok(const char* n) // �����������, ������� ��������� ��� ������
	{
		strcpy_s(name, n);
		karta_cur = score = ochki = 0;
	}
	char* Get_Name()
	{
		return name;
	}
	
	void Get_ochki(Karta a) // ���������� ���� �����. �� �������� ���� ����
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
	
	void Get_Kart(Karta a) //����� �����
	{
		Karta_own[karta_cur] = a;
		Get_ochki(a);
		karta_cur++;
	}

	void Show() // �������� ����� �� �����
	{
		cout << name << "\n";
		for (int i = 0; i < karta_cur; i++)
		{
			Karta_own[i].Get_karta();
		}
		cout << "Ochki - " << ochki;
		cout << "\n----------------\n";
	}
	int Ochki() // ���������  ���� ���� �� �����, ��� ����������� ����������
	{
		return ochki;
	}

	void Score_up() // ���� ������� - �������� ����
	{
		score++;
	}

	int Get_score() // �������� ����
	{
		return score;
	}
	void Reset() //����� ����
	{
		karta_cur = 0;
		ochki = 0;
	}

};

