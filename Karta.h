#pragma once
#include <iostream>
using namespace std;

class Karta // класс одной карты 
{
	char digit; // достоинство карты
	char mast[7]; // масть
public:
	char Get_num() // вернуть достоинство карты
	{
		return digit;
	}
	void Get_karta() // показать карту
	{
		cout << digit <<"/" <<mast<<"\n";
	}
	void Set_num(char n) // установление достоинства
	{
		digit = n;
	}
	void Set_mast(const char *m) // установление масти
	{
		strcpy_s(mast, m);
	}
};

