#pragma once
#include <iostream>
using namespace std;

class Karta // ����� ����� ����� 
{
	char digit; // ����������� �����
	char mast[7]; // �����
public:
	char Get_num() // ������� ����������� �����
	{
		return digit;
	}
	void Get_karta() // �������� �����
	{
		cout << digit <<"/" <<mast<<"\n";
	}
	void Set_num(char n) // ������������ �����������
	{
		digit = n;
	}
	void Set_mast(const char *m) // ������������ �����
	{
		strcpy_s(mast, m);
	}
};

